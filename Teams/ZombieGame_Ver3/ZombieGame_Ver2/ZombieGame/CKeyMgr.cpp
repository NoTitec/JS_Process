#include "pch.h"
#include "CKeyMgr.h"

int g_ArrVK[(int)KEY::LAST] =
{
	VK_LEFT,//	LEFT,
	VK_RIGHT,//RIGHT,
	VK_UP,//UP,
	VK_DOWN,//DOWN,
	'1',
	'2',
	'3',
	'4',
	'5',
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'Z',
	'X',
	'C',
	'V',
	'B',
	VK_MENU,//ALT,
	VK_CONTROL,//CTRL,
	VK_SHIFT,//LSHIFT,
	VK_SPACE,//SPACE,
	VK_RETURN,//ENTER,
	VK_LBUTTON,
	VK_RBUTTON,

	VK_ESCAPE//ESC,


	//LAST, // ���� �˸���.
};

CKeyMgr::CKeyMgr()
{

}
CKeyMgr::~CKeyMgr()
{

}
void CKeyMgr::Initialize()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecInfo.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::Update()
{
	// ���� ��Ŀ�� ���¸� �˷��ִ� �Լ�.
	HWND hWnd = GetFocus();

	if (nullptr != hWnd) // ��Ŀ�� ���� ��.
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_ArrVK[i]) & 0x8000)		// Ű�� ���ȴ�.
			{
				if (m_vecInfo[i].bPrevPush)					// �������� ���� �־���.
				{
					m_vecInfo[i].eState = KEY_STATE::HOLD;
				}
				else										// �������� �ʾҴ�.
				{
					m_vecInfo[i].eState = KEY_STATE::TAP;
				}
				m_vecInfo[i].bPrevPush = true;
			}
			else
			{
				if (m_vecInfo[i].bPrevPush)					// �������� ���� �־���.
				{
					m_vecInfo[i].eState = KEY_STATE::AWAY;
				}
				else										// �������� �ʾҴ�.
				{
					m_vecInfo[i].eState = KEY_STATE::NONE;
				}
				m_vecInfo[i].bPrevPush = false;
			}
		}
	}
	else // ��Ŀ�� ���� �ƴ� ��.
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecInfo[i].bPrevPush = false;
			if (m_vecInfo[i].eState == KEY_STATE::TAP || m_vecInfo[i].eState == KEY_STATE::HOLD)
			{
				m_vecInfo[i].eState = KEY_STATE::AWAY;
			}
			else if (m_vecInfo[i].eState == KEY_STATE::AWAY)
			{
				m_vecInfo[i].eState = KEY_STATE::NONE;
			}

		}
	}

}
