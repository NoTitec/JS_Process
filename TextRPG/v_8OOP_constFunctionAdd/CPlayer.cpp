#include "CPlayer.h"
#include "stdafx.h"

//생성자 이니셜라이저 작성됨

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
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "전사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "마법사");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case THIEF:
		strcpy_s(m_tInfo.saName, sizeof(m_tInfo.saName), "도적");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;
	}


}

void CPlayer::Render() const
{
	cout << "-----------------------------------" << endl;
	cout << "이름 : " << m_tInfo.saName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;

}
