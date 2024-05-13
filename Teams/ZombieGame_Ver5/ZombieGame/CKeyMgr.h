#pragma once
// Player class에서만 사용하는 Mgr입니다. 
// 사용법만 간단하게 인지하면 됩니당.
enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

// 아래 키 추가시, CKeyMgr.cpp에 전역으로 선언된 배열에도 반드시 같은 순서에 추가해줘야함.
enum class KEY // 자체적으로 지원 할 키 종류
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,

	LBUTTON,
	RBUTTON,
	ESC,

	LAST, // 끝을 알리는.
};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrevPush;
};

class CKeyMgr
{
	SINGLETONE(CKeyMgr);

private:
	vector<tKeyInfo> m_vecInfo;
public:
	KEY_STATE GetKeyState(KEY _eKey) const { return m_vecInfo[(int)_eKey].eState; }
	bool GetPrevPush(KEY _eKey) const { return m_vecInfo[(int)_eKey].bPrevPush; }
public:
	void Initialize();
	void Update();
};

