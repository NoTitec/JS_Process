#include "stdafx.h"
#include "CStore.h"
#include "CPlayer.h"

CStore::CStore()
{
	m_pPlayer = nullptr;
}

CStore::~CStore()
{
	Release();
}

void CStore::Set_Player(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::Initialize()
{

}

void CStore::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.�ʱ޾����� 2.�߱޾����� 3.��޾����� 4.������" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pPlayer->SetItem("�ʱ޾�����");
			cout << "�ʱ޾����� ���ſϷ�" << endl;
			system("pause");
			break;
		case 2:
			m_pPlayer->SetItem("�߱޾�����");
			cout << "�߱޾����� ���ſϷ�" << endl;
			system("pause");
			break;
		case 3:
			m_pPlayer->SetItem("��޾�����");
			cout << "�ʱ޾����� ���ſϷ�" << endl;
			system("pause");
			break;
		case 4:
			return;
		}
	}
}

void CStore::Release()
{
	
}
