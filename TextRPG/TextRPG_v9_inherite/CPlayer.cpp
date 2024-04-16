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

void CPlayer::Render() const
{
	cout << "-------------�÷��̾�-------------" << endl;
	cout << "�̸� : " << m_Stat.szName << endl;
	cout << "ü�� : " << m_Stat.iHp << "\t���ݷ� : " << m_Stat.iAttack << endl;
	cout << "������ : " << m_item << endl;
}

void CPlayer::SetItem(const char* itemname)
{
	strcpy_s(m_item, sizeof(m_item), itemname);
}
