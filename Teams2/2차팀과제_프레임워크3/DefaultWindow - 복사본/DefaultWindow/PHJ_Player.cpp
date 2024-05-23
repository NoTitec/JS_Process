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
	m_iHp = 100000; // �ÿ����̶� �� �� �װ� ������
	m_eID = PHJ_PLAYER;
}

int CPHJ_Player::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_fAngle = 0; // ���� ���Է½� ��� ���� ����

	Key_Input();

	Update_Rect(); // ������ y�� �ٴ�, x�� ��� �ִ� ������ obj�� �ٸ� �Լ� ��

	return OBJ_NOEVENT;
}

void CPHJ_Player::Key_Input()
{
	if (KEY.Key_Pressing(VK_RIGHT))
	{
		if (!KEY.Key_Pressing(VK_SHIFT)) // SHIFT �ȴ��������� �̵� : SHIFT ������ ������
		{
			m_tInfo.fX += m_fSpeed;
			float fLineY = 0.f;
			bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY);
			if ((!m_bJump && !m_bFall) && (!bLineCol || fLineY - m_tInfo.fY > 30.f)) // ����Ÿ�� ���ε� ���� ���ǰ� ���� ���� ���̳� or ���� ���� X
				m_bFall = true;
		}
		m_fAngle = 0;// m_fAngle�� ��� ���� - �׻� ����ǥ���� ������
	}

	if (KEY.Key_Pressing(VK_LEFT))
	{
		if (!KEY.Key_Pressing(VK_SHIFT)) // SHIFT �ȴ��������� �̵� : SHIFT ������ ������
		{
			m_tInfo.fX -= m_fSpeed; 
			float fLineY = 0.f;
			bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY);
			if ((!m_bJump && !m_bFall) && (!bLineCol || fLineY - m_tInfo.fY > 30.f)) // ����Ÿ�� ���ε� ���� ���ǰ� ���� ���� ���̳� or ���� ���� X
				m_bFall = true;
		}
		m_fAngle = 180;
	}

	if (KEY.Key_Pressing(VK_UP)) // �� �Ʒ��� �̵� x, ��� ���⸸ ���ư�
	{
		m_fAngle = 90;
		if (KEY.Key_Pressing(VK_RIGHT)) // �밢������ ����
			m_fAngle -= 45;
		if (KEY.Key_Pressing(VK_LEFT)) // �밢������ ����
			m_fAngle += 45;
	}

	if (KEY.Key_Pressing(VK_DOWN))
	{
		m_fAngle = 270;
		if (KEY.Key_Pressing(VK_RIGHT)) // �밢������ ����
			m_fAngle += 45;
		if (KEY.Key_Pressing(VK_LEFT)) // �밢������ ����
			m_fAngle -= 45;
	}

	if (KEY.Key_Down(VK_SPACE)) // ����
	{
		if ((KEY.Key_Pressing(VK_DOWN) && !m_bJump) && !m_bFall) // ��Ÿ�� �߿� �����ϸ�
			m_tInfo.fY += 0.1f, m_bFall = true;
		else if(!m_bFall) // ��Ÿ�� ���̸�
			m_bJump = true;
	}

	if (KEY.Key_Down('C')) // C ������ ���� SWAP
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

	if (KEY.Key_Down('X')) // X ������ ź ���� ���� ����
	{
		CObj* pBullet;
		int iScrollX = (int)SCROLL.Get_ScrollX();
		switch (m_eWtype)
		{
		case DEFAULT: // ������ ź �ٶ󺸴� �������� 1��
		{
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(m_eWtype);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			break;
		}
		case TRI_BULLET: // ���׶� ź �ٶ󺸴� ���� + �밢 �� �Ʒ��� 3��
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

	if (KEY.Key_Down('Z')) // Z ������ �ʻ��
	{
		if(m_fExguage == 100.f) // ������ �� ������ ��
		{
			CObj* pBullet;
			int iScrollX = (int)SCROLL.Get_ScrollX();
			switch (m_eWtype)
			{
			case DEFAULT: // ������ ź �ٶ󺸴� �������� ū �� 1��
			{
				pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY - m_tInfo.fCY / 2.f, m_fAngle);
				dynamic_cast<CPHJ_Bullet*>(pBullet)->Player_Attack(DEFAULT_EX);
				OBJ.Add_Object(OBJ_BULLET, pBullet);
				break;
			}
			case TRI_BULLET: // ���׶� ź 8�������� �߻�
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
			//m_fExguage = 0.f; - ���� �� - ���� �ѹ����� ������ �ʱ�ȭ �Ǿߵ� 
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
	float fLineY = 0.f; // x�� �������� ���� ���� �� ���� y ��
	float fChangeY; // ����, ���� ȿ�� ����� �� y ��

	bool bLineCol = CPHJLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fLineY); // �� �Ʒ� ������ �ִ��� üũ

	if (m_bJump) // ���� �� O
	{
		m_fJumptimer += 0.2f;

		fChangeY = m_tInfo.fY - ((m_fSpeed * 3 * m_fJumptimer) - ((9.8f * m_fJumptimer * m_fJumptimer) * 0.5f));

		// printf("%.lf %.lf %.lf\n", m_tInfo.fY, fLineY, fChangeY); - ��ǥ üũ�� �ڵ�(���߿� ����)

		if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // ���� O, ���� O, ���� ���� �ִ� ���� �� �Ʒ��� �������� �ߴ� & ����
		{
			m_bJump = false;
			m_fJumptimer = 0.f;
			m_tInfo.fY = fLineY;
		}
		else // ���� ���ų� ���� �Ʒ��� �������� �ʾ��� ��
			m_tInfo.fY = fChangeY;
	}
	else if (m_bFall) // ���� �� O
	{
		fChangeY = m_tInfo.fY + ((4.8f * m_fFalltimer * m_fFalltimer) * 0.5f); // ���� ������ �
		m_fFalltimer += 0.2f;

		if (bLineCol && (fLineY > m_tInfo.fY && fLineY < fChangeY)) // ���� O, ���� O, ���� ���� �ִ� ���� �� �Ʒ��� �������� �ߴ� & ����
		{
			m_bFall = false;
			m_fFalltimer = 0.f;
			m_tInfo.fY = fLineY;
		}
		else // ���� ���ų� ���� �Ʒ��� �������� �ʾ��� ��
			m_tInfo.fY = fChangeY;
	}
	else if (bLineCol) // ���� X, ���� X, ���� O
	{
		m_tInfo.fY = fLineY;
	}

	if (m_tInfo.fY > WINCY) // ȭ�� �� -> ����
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


