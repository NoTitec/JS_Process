#pragma once

#include "Define.h"

// sound 용도 - 헤더 순서 중요
#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

// 코드
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

class CSoundMgr
{
	DECLARE_SINGLE(CSoundMgr)

//public:
//	bool	Initialize();
//	void	Update();
//
//public:
//	LPDIRECTSOUND8	GetSoundDevice() { return m_soundCard; }
//	void			RegisterToBGM(CSound* sound);
//
//public:
//	void			Stop_BGM();
//
//public:
//	void			Play_Sound(OBJ_ID eID, SOUND_TYPE eType);
//	void			Play_Sound(SOUND_TYPE_EFFECT eECType);
//
//private:
//	void			Play_Sound_Default(OBJ_ID eID);
//	void			Play_Sound_Dead(OBJ_ID eID);
//	void			Play_Sound_Effect(SOUND_TYPE_EFFECT eType);
//
//public:
//	void	Play_Stage_BGM();
//	void	Play_Main_Menu_BGM();
//
//private:
//	LPDIRECTSOUND8	m_soundCard;				// 사운드 카드 대표 객체
//	CSound* m_pBGM = nullptr;
//
//	vector<vector<CSound*>> m_vec_Sounds_Default;
//	vector<vector<CSound*>> m_vec_Sounds_Dead;
//	vector<vector<CSound*>> m_vec_Sounds_Effect;
};

