#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = nullptr;

CKeyMgr::CKeyMgr()
{
    ZeroMemory(m_bKeyState, sizeof(m_bKeyState));

}

CKeyMgr::~CKeyMgr()
{
}

//Ư��Ű ���Ȥ����� true��ȯ
bool CKeyMgr::Key_Pressing(int _iKey)
{
    if (GetAsyncKeyState(_iKey) & 0x8000)
        return true;

    return false;
}

bool CKeyMgr::Key_Down(int _iKey)
{
	// ������ ������ ����, ���� ������ ���
	if ((!m_bKeyState[_iKey]) && (GetAsyncKeyState(_iKey) & 0x8000))
	{
		//���� ���� Ű�� ���¸� true�� �ٲٰ� true ����
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}

bool CKeyMgr::Key_Up(int _iKey)
{
	// ������ ������ �־���, ���� ������ �ʾ��� ���
	if ((m_bKeyState[_iKey]) && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		//���� �� Ű�� ���¸� false�� �ٲٷ� true����
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	return false;
}

void CKeyMgr::Key_Update()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		//Ű ���º��� true�� ���� �� ���¸� ���� Ű�� false�� ��ȯ
		if (m_bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
		//Ű ���º��� false�� ���� ���� ���¸� ���� Ű�� true�� ��ȯ
		if (!m_bKeyState[i] && (GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}
}
