#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
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
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp		= 100;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "������");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;
	}

}

void CPlayer::Render()
{
	cout << "-----------------------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}
