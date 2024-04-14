#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::SelectJob()
{
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
	
	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp		= 100;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "도적");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;
	}

}
