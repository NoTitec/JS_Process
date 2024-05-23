#include "stdafx.h"
#include "PHJ_Bullet.h"
#include "RenderMgr.h"

CPHJ_Bullet::CPHJ_Bullet()
{
}

CPHJ_Bullet::~CPHJ_Bullet()
{
	Release();
}

void CPHJ_Bullet::Initialize()
{
	m_eID = PHJ_BULLET;
	m_ePT = PT_END;
	m_eWtype = WT_END;
	m_eOwn = OWNER_END;
}

int CPHJ_Bullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += LONG(m_fSpeed * cos(m_fAngle * (PI / 180.f))); // ������ �־��� ���� �������� ����
	m_tInfo.fY -= LONG(m_fSpeed * sin(m_fAngle * (PI / 180.f)));

	__super::Update_Rect();

	m_iHp--; // hp = �Ѿ� ���� �Ⱓ
	return OBJ_NOEVENT;
}

void CPHJ_Bullet::Late_Update()
{
	if (WINCY < m_tRect.top || 0 > m_tRect.bottom || 0 == m_iHp) // �Ѿ� ���� ������ ���ó��
		m_bDead = true;
}

void CPHJ_Bullet::Render(HDC hDC)
{
	RENDER.DrawEllipse(m_tRect);
}

void CPHJ_Bullet::Release()
{
}

void CPHJ_Bullet::OnHit(CObj* _pObj)
{
	PHJ_ID ID = dynamic_cast<CPHJ_Obj*>(_pObj)->Get_ID();
	if (m_eOwn == PLAYER && ID == PHJ_MONSTER) // �÷��̾� �Ѿ��̸�
	{
		m_bDead = true;
	}
	else if (m_eOwn == ENEMY && ID == PHJ_PLAYER && m_ePT != FIRE) // �� �Ѿ��̰� �÷��̾����� �¾Ұ� FIRE ���� �ƴϸ�
	{
		m_bDead = true;
	}
}

void CPHJ_Bullet::Player_Attack(WEAPON_TYPE _WT)
{
	m_eOwn = PLAYER;
	m_eWtype = _WT;
	switch (_WT)
	{
	case DEFAULT:
	{
		if (m_fAngle == 0 || m_fAngle == 180) // ���η� �� ��
		{
			m_tInfo.fCX = 50.f;
			m_tInfo.fCY = 20.f;
		}
		else // ���η� �� ��
		{
			m_tInfo.fCX = 20.f;
			m_tInfo.fCY = 50.f;
		}
		m_fSpeed = 10.f;
		m_iAtk = 1;
		m_iHp = 50;
		break;
	}
	case TRI_BULLET:
	{
		m_tInfo.fCX = 30.f;
		m_tInfo.fCY = 30.f;
		m_fSpeed = 20.f;
		m_iAtk = 1;
		m_iHp = 20;
		break;
	}
	case DEFAULT_EX:
	{
		if (m_fAngle == 0 || m_fAngle == 180) // ���η� �� ��
		{
			m_tInfo.fCX = 200.f;
			m_tInfo.fCY = 60.f;
		}
		else // ���η� �� ��
		{
			m_tInfo.fCX = 60.f;
			m_tInfo.fCY = 200.f;
		}
		m_fSpeed = 10.f;
		m_iAtk = 1;
		m_iHp = 100;
		break;
	}
	case TRI_BULLET_EX:
	{
		m_tInfo.fCX = 60.f;
		m_tInfo.fCY = 60.f;
		m_fSpeed = 10.f;
		m_iAtk = 1;
		m_iHp = 50;
		break;
	}
	default:
		break;
	}
}

void CPHJ_Bullet::Boss_Attack(PATTERN _PT)
{
	m_eOwn = ENEMY;
	m_ePT = _PT;
	switch (_PT)
	{
	case FIRE:
	{
		m_tInfo.fCX = 500.f;
		m_tInfo.fCY = 80.f;
		m_fSpeed = 0.f;
		m_iAtk = 1;
		m_iHp = 60;
		break;
	}
	case DOUBLE_BULLET:
	{
		m_tInfo.fCX = 80.f;
		m_tInfo.fCY = 80.f;
		m_fSpeed = 10.f;
		m_iAtk = 1;
		m_iHp = 100;
		break;
	}
	default:
		break;
	}
}
