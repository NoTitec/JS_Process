#pragma once
// Player class������ ����ϴ� Mgr�Դϴ�. 
// ������ �����ϰ� �����ϸ� �˴ϴ�.
enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

// �Ʒ� Ű �߰���, CKeyMgr.cpp�� �������� ����� �迭���� �ݵ�� ���� ������ �߰��������.
enum class KEY // ��ü������ ���� �� Ű ����
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

	LAST, // ���� �˸���.
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

