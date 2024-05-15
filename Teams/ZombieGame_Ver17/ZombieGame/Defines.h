#pragma once

#define PURE = 0
#define WINCX 800
#define WINCY 600

#define PI 3.141592

#define OBJ_NOEVENT 0
#define OBJ_DEAD	1


// SINGLETONE 매크로
#define SINGLETONE(type) public:\
							static type* GetInstance()\
							{\
								static type mgr;\
								return &mgr;\
							}\
						private:\
							type();\
							~type();

// Key State 매크로
#define KEYCHECK(eKey, eState)	CKeyMgr::GetInstance()->GetKeyState(eKey) == eState

#define KEY_TAP(eKey)			KEYCHECK(eKey, KEY_STATE::TAP)
#define KEY_HOLD(eKey)			KEYCHECK(eKey, KEY_STATE::HOLD)
#define KEY_AWAY(eKey)			KEYCHECK(eKey, KEY_STATE::AWAY)
#define KEY_NONE(eKey)			KEYCHECK(eKey, KEY_STATE::NONE)


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

extern HWND g_hWnd;
