#include "CPlayer.h"
#include "stdafx.h"

//������ �̴ϼȶ����� �ۼ���

CPlayer::~CPlayer()
{
	
}

void CPlayer::Take_Damage(int iAttack)
{
	m_tInfo.iHp -= iAttack;
}

int CPlayer::Get_Attak()
{
	return m_tInfo.iAttack;
}

int CPlayer::Get_Hp()
{
	return m_tInfo.iHp;
}

void CPlayer::Set_Hp(int hp)
{
	m_tInfo.iHp = hp;
}

void CPlayer::SelectJob()
{
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "������");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;
	}


}

void CPlayer::Render() const
{
	cout << "-----------------------------------" << endl;
	cout << "�̸� : " << m_tInfo.saName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;

}
