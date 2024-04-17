#include "CPlayer.h"
#include "CItem.h"
CPlayer::CPlayer() : m_pItem_Weapon(nullptr),m_pItem_Armor(nullptr)
{
}

CPlayer::~CPlayer()
{
	SAFE_DELETE(m_pItem_Armor);
	SAFE_DELETE(m_pItem_Weapon);
}

void CPlayer::Set_Weapon(CBase* weapon)
{
	CBase* temp = new CItem(weapon->Get_Info().szName,weapon->Get_Info().iAttack,weapon->Get_Info().iHp);
	m_pItem_Weapon = temp;
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
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;

	case WIZARD:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "������");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		m_tInfo.iMoney = 10000;
		break;
	}
}

void CPlayer::Render()
{
	cout << "-------------�÷��̾�----------------------" << endl;
	cout << "�̸� : " << m_tInfo.szName << "\t������ : " << m_tInfo.iMoney << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
	if(m_pItem_Weapon!=nullptr)
	cout << "�������̸�" << m_pItem_Weapon->Get_Info().szName << "\t�����۰��ݷ�:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "�������̸�" << m_pItem_Armor->Get_Info().szName << "\t������ü��:" << m_pItem_Armor->Get_Info().iHp << endl;

}
