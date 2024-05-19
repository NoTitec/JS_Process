#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = nullptr;

CKeyMgr::CKeyMgr()
{
    ZeroMemory(m_bKeyState, sizeof(m_bKeyState));

}

CKeyMgr::~CKeyMgr()
{
}

//특정키 눌렸ㅇ르때 true반환
bool CKeyMgr::Key_Pressing(int _iKey)
{
    if (GetAsyncKeyState(_iKey) & 0x8000)
        return true;

    return false;
}

bool CKeyMgr::Key_Down(int _iKey)
{
	// 이전에 눌림이 없고, 현재 눌렸을 경우
	if ((!m_bKeyState[_iKey]) && (GetAsyncKeyState(_iKey) & 0x8000))
	{
		//현재 누른 키의 상태를 true로 바꾸고 true 리턴
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}

bool CKeyMgr::Key_Up(int _iKey)
{
	// 이전에 눌림이 있었고, 현재 눌리지 않았을 경우
	if ((m_bKeyState[_iKey]) && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		//현재 뗀 키의 상태를 false로 바꾸로 true리턴
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}

void CKeyMgr::Key_Update()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		//키 상태별로 true에 현재 뗀 상태면 현재 키를 false로 전환
		if (m_bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
		//키 상태별로 false에 현재 누른 상태면 현재 키를 true로 전환
		if (!m_bKeyState[i] && (GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}
}
