#include "CPlayer.h"
#include "stdafx.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::SelectJob()
{
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "����");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;

	case WIZARD:
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "������");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_Stat.szName, sizeof(m_Stat.szName), "����");
		m_Stat.iAttack = 10;
		m_Stat.iHp = 100;
		break;
	}
}
