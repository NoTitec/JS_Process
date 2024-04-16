#include "CPlayer.h"
#include "stdafx.h"

CPlayer::CPlayer()
{
	memset(m_item, 0, sizeof(m_item));
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
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "전사");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;

	case WIZARD:
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "마법사");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "도적");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;
	}
}

void CPlayer::Render() const
{
	cout << "-------------플레이어-------------" << endl;
	cout << "이름 : " << m_Stat.szName << endl;
	cout << "체력 : " << m_Stat.iHp << "\t공격력 : " << m_Stat.iAttack << endl;
	cout << "아이템 : " << m_item << endl;
}

void CPlayer::SetItem(const char* itemname)
{
	strcpy_s(m_item, sizeof(m_item), itemname);
}
