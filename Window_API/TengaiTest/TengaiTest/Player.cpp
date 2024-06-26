#include "Player.h"
#include "MikoPet.h"
#include "EventDefine.h"
#include "enumDefine.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "MikoBasicBullet.h"
#include "MikoBomb.h"
#include "PlayerDeadEffect.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
CPlayer::CPlayer() : m_fTime(0.f), m_iPower(0), m_eCurState(FORWARDMOVE), m_ePreState(ST_END),m_bBombKeyOn(false)
{
    ZeroMemory(&m_tPetPoint, sizeof(POINT));

}

CPlayer::~CPlayer()
{
    Release();

}

void CPlayer::Initialize()
{
	m_eID = OBJ_PLAYER;
	m_LifeCount = 2;
	m_dwHitCoolTime = GetTickCount();
	m_iBombCount = 4;
	m_iPower = 0;
	m_bBombKeyOn = false;
    m_tInfo = { 100.f, WINCY / 2.f, 32.f, 32.f };
	m_tPetPoint.x = m_tInfo.fX - 16.f;
	m_tPetPoint.y = m_tInfo.fY - 16.f;
    m_fSpeed = 8.f;
	m_dwDebugMassageTime = GetTickCount();
	//비트이미지 가로
	m_tFrame.iFrameStart = -1;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 2;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.dwSpeed = 100;
	//총알로직
	m_dwBulletGenarateTime = GetTickCount();
	m_dwBulletGenarateSpeed = 150;
	//사운드
	m_dwBulletSoundTime = GetTickCount();
	m_dwBulletSoundSpeed = 310;
	m_dwBulletSoundTime2 = GetTickCount()+150;
	m_dwBulletSoundSpeed2 = 310;
	//폭탄
	m_dwBombGenarateDelay = 1000;
	m_pFrameKey = L"Miko_Fly_Forward";
	m_eCurState = FORWARDMOVE;
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	Key_Input();
	__super::Update_Rect();
	m_tPetPoint.x = m_tInfo.fX - 16.f;
	m_tPetPoint.y = m_tInfo.fY - 16.f;
	Create_Basic_Bullet();
	Bullet_Sound_Control();
	Create_Bomb();
	if ((m_dwHitCoolTime + 1000 < GetTickCount()) && !m_bCanHit)
	{
		m_bCanHit = true;
		m_dwHitCoolTime = GetTickCount();
	}
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	Motion_Change();
	Offset();
	__super::Move_Frame();
	//원리 이해 안되지만 lateupdate들어가야함
	switch (m_eCurState)
	{
	case HITED:
		if (m_tFrame.iFrameStart + 1 > m_tFrame.iFrameEnd)
		{
			Set_State_ForwardMove();
		}
		break;
	}
#ifdef _DEBUG

	if (m_dwDebugMassageTime + 1000 < GetTickCount())
	{
		cout << "플레이어 좌표 : " << m_tInfo.fX << "\t" << m_tInfo.fY << endl;
		cout << "플레이어 파워 : " << m_iPower << endl;
		cout << "플레이어 라이프 : " << m_LifeCount << endl;
		m_dwDebugMassageTime = GetTickCount();
	}



#endif // _DEBUG
}

void CPlayer::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		(int)m_tInfo.fCX * m_tFrame.iFrameStart,
		(int)m_tInfo.fCY * m_tFrame.iMotion,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 0, 152));
}

void CPlayer::Release()
{
	ObjMgr->Set_Player_DeadTime();
}

void CPlayer::OnHit(CObj* _pObj)
{
	OBJ_ID pObj_ID = _pObj->Get_ID();
	switch (pObj_ID)
	{
	case OBJ_ITEM:
		SoundMgr->PlaySound(L"tengai-161 miko power up voice.wav", SOUND_GET_ITEM,0.5f);
		if (m_iPower == 0)
		{
			ObjMgr->Add_Object(OBJ_PET, CAbstractFactory<CMikoPet>::Create(m_tInfo.fX - 16.f, m_tInfo.fY - 16.f,this));
			CObj* petpoint = ObjMgr->Get_Pet_Pointer();
			dynamic_cast<CMikoPet*>(petpoint)->Set_Level(CMikoPet::LEVEL_ONE);
			++m_iPower;
			m_HeadUIShow = true;
		}
		else if (m_iPower == 1)
		{
			SoundMgr->StopSound(SOUND_GET_ITEM);
			SoundMgr->PlaySound(L"tengai-161 miko power up voice.wav", SOUND_GET_ITEM, 0.5f);

			CObj* petpoint = ObjMgr->Get_Pet_Pointer();
			dynamic_cast<CMikoPet*>(petpoint)->Set_Level(CMikoPet::LEVEL_TWO);
			++m_iPower;
			m_HeadUIShow = true;
		}
		break;
	case OBJ_BOMB_ITEM:
		if (m_iBombCount < 5)
		{
			++m_iBombCount;
		}
		break;
	case OBJ_MONSTERBULLET:
	case OBJ_MONSTER:
	case OBJ_BOSSMONSTER:
		if (m_bCanHit)
		{
			if (m_iPower == 0)
			{
				if (m_LifeCount == 0)
				{
					SoundMgr->StopSound(SOUND_PLAYER_DEAD);
					SoundMgr->PlaySoundW(L"koyori getting hit.wav", SOUND_PLAYER_DEAD, 0.1f);
					ObjMgr->Add_Object(OBJ_EFFECT, CAbstractFactory<CPlayerDeadEffect>::Create(m_tInfo.fX, m_tInfo.fY));
					Set_Dead();
					return;
				}
				else
				{
					--m_LifeCount;
					SoundMgr->StopSound(SOUND_PLAYER_HITED);
					SoundMgr->PlaySoundW(L"koyori lvl down.wav", SOUND_PLAYER_HITED, 0.5f);
					m_pFrameKey = L"MikoHited";
					m_eCurState = HITED;
				}
			}
			if (m_iPower > 0)
			{
				SoundMgr->StopSound(SOUND_PLAYER_HITED);
				SoundMgr->PlaySoundW(L"koyori lvl down.wav", SOUND_PLAYER_HITED, 0.5f);
				--m_iPower;
				CObj* petpoint = ObjMgr->Get_Pet_Pointer();
				dynamic_cast<CMikoPet*>(petpoint)->Set_Level((CMikoPet::MIKOPETLEVEL)m_iPower);
				m_pFrameKey = L"MikoHited";
				m_eCurState = HITED;
			}
			m_bCanHit = false;
			m_dwHitCoolTime = GetTickCount();
			cout << "몬스터에게 피격" << endl;
		}
		break;
	}
}

void CPlayer::Key_Input()
{
	//폭탄 생성
	if (KeyMgr->Key_Down(VK_SPACE))
	{
		if (ObjMgr->Check_ID_Empty(OBJ_PLAYERBOMB)&&(m_iBombCount>0)&&(!m_bBombKeyOn))
		{
			ObjMgr->Delete_ID(OBJ_MONSTERBULLET);
			--m_iBombCount;
			SoundMgr->StopSound(SOUND_PLAYER_BOMB);
			SoundMgr->PlaySoundW(L"principi ulti koyori.wav", SOUND_PLAYER_BOMB, 0.5f);
			m_dwBombGenarateTime = GetTickCount();
			m_bBombKeyOn = true;
			m_tBombGenaratePoint.x = m_tInfo.fX;
			m_tBombGenaratePoint.y = m_tInfo.fY;
		}
	}
	////////////////////
	if (KeyMgr->Key_Pressing(VK_UP))
	{
		int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
		if (m_tInfo.fY+ iScrollY >= 16)
		m_tInfo.fY -= m_fSpeed;
	}
	if (KeyMgr->Key_Pressing(VK_DOWN))
	{
		int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
		if (m_tInfo.fY+ iScrollY <= 584)
		m_tInfo.fY += m_fSpeed;
	}
	if (KeyMgr->Key_Pressing(VK_RIGHT))
	{
		if (m_tInfo.fX <= 784)
			m_tInfo.fX += m_fSpeed;

		if (m_eCurState != HITED)
		{
			m_pFrameKey = L"Miko_Fly_Forward";
			m_eCurState = FORWARDMOVE;
		}
	}
	else if (KeyMgr->Key_Pressing(VK_LEFT))
	{
		if(m_tInfo.fX>=16)
			m_tInfo.fX -= m_fSpeed;
		if (m_eCurState != HITED)
		{
			m_pFrameKey = L"Miko_Fly_Backward";
			m_eCurState = BACKMOVE;
		}
	}
	if(m_eCurState!=HITED)
	{
		m_eCurState = FORWARDMOVE;
		m_pFrameKey = L"Miko_Fly_Forward";
	}
}

void CPlayer::Offset()
{
	int	iOffSetminX = 16;
	int	iOffSetmaxX = 784;

	int	iOffSetminY = 100;
	int	iOffSetmaxY = 500;

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (iOffSetminY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetmaxY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
}

void CPlayer::Motion_Change()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case CPlayer::FORWARDMOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 100;
			break;
		case CPlayer::BACKMOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 100;
			break;
		case CPlayer::HITED:
			m_tFrame.iFrameStart = -1;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 200;
			break;
		}
		m_ePreState = m_eCurState;

	}
}

void CPlayer::Create_Basic_Bullet()
{
	if (m_dwBulletGenarateTime + m_dwBulletGenarateSpeed < GetTickCount())
	{
		
		ObjMgr->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CMikoBasicBullet>::Create(m_tInfo.fX,m_tInfo.fY,DIR_RIGHT));
		m_dwBulletGenarateTime = GetTickCount();
	}
}

void CPlayer::Create_Bomb()
{
	if (m_bBombKeyOn)
	{
		if (m_dwBombGenarateTime + m_dwBombGenarateDelay < GetTickCount())
		{
			ObjMgr->Add_Object(OBJ_PLAYERBOMB, CAbstractFactory<CMikoBomb>::Create(m_tBombGenaratePoint.x + 180.f, m_tBombGenaratePoint.y));
			m_bBombKeyOn = false;
		}

	}
}

void CPlayer::Bullet_Sound_Control()
{
	if (m_dwBulletSoundTime + m_dwBulletSoundSpeed < GetTickCount())
	{
		SoundMgr->StopSound(SOUND_PLAYER_FIRE);
		SoundMgr->PlaySoundW(L"Bullet_effect 2.wav", SOUND_PLAYER_FIRE, 0.5f);
		m_dwBulletSoundTime = GetTickCount();
	}
	if (m_dwBulletSoundTime2 + m_dwBulletSoundSpeed2 < GetTickCount())
	{
		SoundMgr->StopSound(SOUND_PLAYER_FIRE2);
		SoundMgr->PlaySoundW(L"Bullet_effect 2.wav", SOUND_PLAYER_FIRE2, 0.5f);
		m_dwBulletSoundTime2 = GetTickCount();
	}
}


