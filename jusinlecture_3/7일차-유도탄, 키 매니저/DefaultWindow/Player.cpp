#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "Shield.h"
#include "ScrewBullet.h"
#include "ObjMgr.h"
#include "GuideBullet.h"
#include "KeyMgr.h"

CPlayer::CPlayer() : m_cur_line(nullptr), m_LineList(nullptr), is_Jumping(false),t(0.f),g(1.1f)
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { 100.f, 450.f, 100.f, 100.f };

	//m_tInfo = { 100.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	Key_Input();
	// ������ ������

	// t : �ð�
	// g : �߷� ���(9.8)

	// Y = (V0 * sin(angle) * t) - ((1 / 2) * g * t * t);
	if (is_Jumping)
	{
		//ù����� ������ ���
		if (m_fJumpStartfY == m_tInfo.fY)
		{
			t += 0.05f;
			m_tInfo.fY -= 3.f*(sin(90.f / 180.f * PI) * t) - (0.5f) * g * t * t;
		}
		else
		{
			//������ ��������ġ�� ���� ��ü ��ġ���� �۰ų� ������ ���� ������ ��ġ���� �������ٴ� ��
			if (m_fJumpStartfY <= m_tInfo.fY)
			{
				is_Jumping = false;
				t = 0.f;
				m_tInfo.fY = m_fJumpStartfY;
			}
			else
			{
				t += 0.05f;
				m_tInfo.fY -= 3.f*(sin(90.f / 180.f * PI) * t) - (0.5f) * g * t * t;
			}
		}
		/*if (t == 1.f)
		{
			
			is_Jumping = false;
		}*/
	}
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	m_tPosin.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle * (PI / 180.f)));
	m_tPosin.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	// ���� �׸���

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release()
{
}

template<typename T>
CObj * CPlayer::Create_Bullet()
{
	CObj*		pBullet = CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}

void CPlayer::Key_Input()
{
	// GetKeyState()

	/*if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	else if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;*/
		
	if (GetAsyncKeyState(VK_RIGHT))
		m_fAngle -= 5.f;
	
	if (GetAsyncKeyState(VK_LEFT))
		m_fAngle += 5.f;

	if (GetAsyncKeyState(VK_UP))
	{
		//���� �����ΰ����Ҷ� curline�� null�̸� curline�� ����Ʈ ù��° ������
		if (m_cur_line == nullptr)
		{
			it = m_LineList->begin();
			m_cur_line = *(it);
		}
		//���� ���� �ڱ� x ��ġ�� curline�� ������ x�� ������ curline �� ���� ������ ����
		//����Ʈ �������̸� �ȵ���
		if (!(it == m_LineList->end()))
		{
			if (m_tInfo.fX == m_cur_line->Get_Info().tRight.fX)
			{
				++it;
				m_cur_line = *(it);
			}
		}
		m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
		float addY = ((m_cur_line->Get_Info().tRight.fY - m_cur_line->Get_Info().tLeft.fY) / (m_cur_line->Get_Info().tRight.fX - m_cur_line->Get_Info().tLeft.fX)); //* (m_tInfo.fX- m_cur_line->Get_Info().tLeft.fX) + m_cur_line->Get_Info().tLeft.fY;
		m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
		m_tInfo.fY += m_fSpeed*addY;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX += -m_fSpeed * cos(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= -m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}

	if (CKeyMgr::Get_Instance()->Key_Up(VK_SPACE))
	{
		//m_pBullet->push_back(Create_Bullet<CScrewBullet>());

		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CGuideBullet>());
	}
	if (CKeyMgr::Get_Instance()->Key_Down('J'))
	{
		m_fJumpStartfY = m_tInfo.fY;
		is_Jumping = true;
	}
	//if (GetAsyncKeyState('S'))
	//{
	//	m_pShield->push_back(Create_Shield());
	//}

}


CObj * CPlayer::Create_Shield()
{
	CObj*		pShield = CAbstractFactory<CShield>::Create();
	pShield->Set_Target(this);

	return pShield;
}

