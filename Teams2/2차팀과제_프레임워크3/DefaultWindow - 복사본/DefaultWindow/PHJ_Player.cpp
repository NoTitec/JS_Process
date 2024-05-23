#include "stdafx.h"
#include "PHJ_Player.h"
#include "PHJ_LineMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"
#include "PHJ_Bullet.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"

using namespace std;

CPHJ_Player::CPHJ_Player()
{
}

CPHJ_Player::~CPHJ_Player()
{
	Release();
}

void CPHJ_Player::Initialize()
{
	m_tInfo = { 400.f, 100.f, 100.f, 100.f };
	m_fSpeed = 7.f;
	m_bJump = false;
	m_bFall = true;
	m_fJumptimer = 0.f;
	m_fFalltimer = 0.f;
	m_fExguage = 100.f;
	m_eWtype = DEFAULT;
	m_iHp = 100000; // 시연용이라 걍 안 죽게 설정함
	m_eID = PHJ_PLAYER;
}

int CPHJ_Player::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_fAngle = 0; // 방향 미입력시 사격 방향 전방

	Key_Input();

	Update_Rect(); // 중점이 y는 바닥, x는 가운데 있는 구조라 obj랑 다른 함수 씀

	return OBJ_NOEVENT;
}

void CPHJ_Player::Key_Input()
{
	if (KEY.Key_Pressing(VK_RIGHT))
	{
		if (!KEY.Key_Pressing(VK_SHIFT)) // SHIFT 안눌렀을때만 이동 : SHIFT 누르면 시즈모드
		{
			m_tInfo.fX += m_fSpeed;
			float fLineY = 0.f;
			bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY);
			if ((!m_bJump && !m_bFall) && (!bLineCol || fLineY - m_tInfo.fY > 30.f)) // 라인타기 중인데 다음 발판과 높이 많이 차이남 or 다음 발판 X
				m_bFall = true;
		}
		m_fAngle = 0;// m_fAngle은 사격 방향 - 항상 방향표따라 움직임
	}

	if (KEY.Key_Pressing(VK_LEFT))
	{
		if (!KEY.Key_Pressing(VK_SHIFT)) // SHIFT 안눌렀을때만 이동 : SHIFT 누르면 시즈모드
		{
			m_tInfo.fX -= m_fSpeed; 
			float fLineY = 0.f;
			bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY);
			if ((!m_bJump && !m_bFall) && (!bLineCol || fLineY - m_tInfo.fY > 30.f)) // 라인타기 중인데 다음 발판과 높이 많이 차이남 or 다음 발판 X
				m_bFall = true;
		}
		m_fAngle = 180;
	}

	if (KEY.Key_Pressing(VK_UP)) // 위 아래는 이동 x, 사격 방향만 돌아감
	{
		m_fAngle = 90;
		if (KEY.Key_Pressing(VK_RIGHT)) // 대각선으로 쏘라고
			m_fAngle -= 45;
		if (KEY.Key_Pressing(VK_LEFT)) // 대각선으로 쏘라고
			m_fAngle += 45;
	}

	if (KEY.Key_Pressing(VK_DOWN))
	{
		m_fAngle = 270;
		if (KEY.Key_Pressing(VK_RIGHT)) // 대각선으로 쏘라고
			m_fAngle += 45;
		if (KEY.Key_Pressing(VK_LEFT)) // 대각선으로 쏘라고
			m_fAngle -= 45;
	}

	if (KEY.Key_Down(VK_SPACE)) // 점프
	{
		if ((KEY.Key_Pressing(VK_DOWN) && !m_bJump) && !m_bFall) // 선타기 중에 밑점하면
			m_tInfo.fY += 0.1f, m_bFall = true;
		else if(!m_bFall) // 선타기 중이면
			m_bJump = true;
	}

	if (KEY.Key_Down('C')) // C 누르면 무기 SWAP
	{
		switch(m_eWtype)
		{
		case DEFAULT:
		{
			m_eWtype = TRI_BULLET;
			break;
		}
		case TRI_BULLET:
		{
			m_eWtype = DEFAULT;
			break;
		}
		default:
			break;
		}
	}

	if (KEY.Key_Down('X')) // X 누르면 탄 종류 따라 공격
	{
		CObj* pBullet;
		int iScrollX = (int)SCROLL.Get_ScrollX();
		switch (m_eWtype)
		{
		case DEFAULT: // 길쭉한 탄 바라보는 방향으로 1발
		{
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(m_eWtype);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			break;
		}
		case TRI_BULLET: // 동그란 탄 바라보는 방향 + 대각 위 아래로 3발
		{
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(m_eWtype);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle -45);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(m_eWtype);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle + 45);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(m_eWtype);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			break;
		}
		default:
			break;
		}
	}

	if (KEY.Key_Down('Z')) // Z 누르면 필살기
	{
		if(m_fExguage == 100.f) // 게이지 꽉 차있을 때
		{
			CObj* pBullet;
			int iScrollX = (int)SCROLL.Get_ScrollX();
			switch (m_eWtype)
			{
			case DEFAULT: // 길쭉한 탄 바라보는 방향으로 큰 거 1발
			{
				pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle);
				dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(DEFAULT_EX);
				OBJ.Add_Object(OBJ_BULLET, pBullet);
				break;
			}
			case TRI_BULLET: // 동그란 탄 8방향으로 발사
			{
				for (float i = 0.f; i < 360.f; i += 45.f)
				{
					pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle + i);
					dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(TRI_BULLET_EX);
					OBJ.Add_Object(OBJ_BULLET, pBullet);
				}
				break;
			}
			default:
				break;
			}
			//m_fExguage = 0.f; - 무한 궁 - 원래 한번쓰면 게이지 초기화 되야됨 
		}
	}
}

void CPHJ_Player::Late_Update()
{
	Lining();
	Offset();
}

void CPHJ_Player::Lining()
{
	float fLineY = 0.f; // x값 기준으로 발판 있을 때 계산된 y 값
	float fChangeY; // 낙하, 점프 효과 적용된 후 y 값

	bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // 발 아래 라인이 있는지 체크

	if (m_bJump) // 점프 중 O
	{
		m_fJumptimer += 0.2f;

		fChangeY = m_tInfo.fY - ((m_fSpeed * 3 * m_fJumptimer) - ((9.8f * m_fJumptimer * m_fJumptimer) * 0.5f));

		// printf("%.lf %.lf %.lf\n", m_tInfo.fY, fLineY, fChangeY); - 좌표 체크용 코드(나중에 삭제)

		if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // 발판 O, 점프 O, 발판 위에 있다 점프 중 아래로 떨어지면 중단 & 복구
		{
			m_bJump = false;
			m_fJumptimer = 0.f;
			m_tInfo.fY = fLineY;
		}
		else // 발판 없거나 발판 아래로 떨어지지 않았을 때
			m_tInfo.fY = fChangeY;
	}
	else if (m_bFall) // 낙하 중 O
	{
		fChangeY = m_tInfo.fY + ((4.8f * m_fFalltimer * m_fFalltimer) * 0.5f); // 수평 포물선 운동
		m_fFalltimer += 0.2f;

		if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // 발판 O, 낙하 O, 발판 위에 있다 낙하 중 아래로 떨어지면 중단 & 복구
		{
			m_bFall = false;
			m_fFalltimer = 0.f;
			m_tInfo.fY = fLineY;
		}
		else // 발판 없거나 발판 아래로 떨어지지 않았을 때
			m_tInfo.fY = fChangeY;
	}
	else if (bLineCol) // 점프 X, 낙하 X, 발판 O
	{
		m_tInfo.fY = fLineY;
	}

	if (m_tInfo.fY > WINCY) // 화면 밖 -> 낙사
		m_bDead = true;
}

void CPHJ_Player::Render(HDC hDC)
{
	RECT rect = m_tRect;
	int iScrollX = (int)SCROLL.Get_ScrollX();
	rect.left += iScrollX;
	rect.right += iScrollX;
	//printf("%.lf %.lf\n", m_tInfo.fX, m_tInfo.fY);
	RENDER.DrawRect(rect);
}

void CPHJ_Player::Release()
{
}

void CPHJ_Player::OnHit(CObj* _pObj)
{
	PHJ_ID ID = dynamic_cast<CPHJ_Obj*>(_pObj)->Get_ID();
	if (ID == PHJ_MONSTER)
		m_iHp--;
	else if (ID == PHJ_BULLET)
	{
		OWNER Own = dynamic_cast<CPHJ_Bullet*>(_pObj)->Get_Owner();
		if (Own == ENEMY)
			m_iHp--;
	}
}

void CPHJ_Player::Update_Rect()
{
	m_tRect.left = long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top = long(m_tInfo.fY - m_tInfo.fCY);
	m_tRect.right = long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom = long(m_tInfo.fY);
}

void CPHJ_Player::Offset()
{
	float fMinx = 300.f;
	float fMaxx = 500.f;
	float fScrollx = SCROLL.Get_ScrollX();
	if (m_tInfo.fX + fScrollx < fMinx)
		SCROLL.Set_ScrollX(m_fSpeed);
	if (m_tInfo.fX + fScrollx > fMaxx)
		SCROLL.Set_ScrollX(-1 * m_fSpeed);
}


