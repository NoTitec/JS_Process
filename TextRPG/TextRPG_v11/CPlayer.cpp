#include "CPlayer.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "ItemBase.h"
//RTTI header추가
#include <typeinfo>
CPlayer::CPlayer() : m_pItem_Weapon(nullptr), m_pItem_Armor(nullptr)
{
}

CPlayer::~CPlayer()
{
	for (ItemBase* ptr : vecInventory)
	{
		delete ptr;
	}
	vecInventory.clear();
	vector<ItemBase*>().swap(vecInventory);
	//플레이어 소멸자서 Safedelete하면 Maingame에서 플레이어 제거할때 오류 발생 왜?
	//Safe_Delete(m_pItem_Weapon);
	//Safe_Delete(m_pItem_Armor);
}

//인벤토리 아이템 추가 max 5
void CPlayer::Add_Item(ItemBase* item)
{
	if(vecInventory.size()<5)
	vecInventory.push_back(item);
}

void CPlayer::SelectJob()
{
	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";

	int iInput(0);

	cin >> iInput;

	switch (iInput)
	{
	case WARRIOR:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "전사");
		m_Info.iAttack = 10;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case WIZARD:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "마법사");
		m_Info.iAttack = 20;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;

	case THIEF:
		strcpy_s(m_Info.szName, sizeof(m_Info.szName), "도적");
		m_Info.iAttack = 50;
		m_Info.iHp = 100;
		m_Info.iMoney = 10000;
		break;
	}
}

void CPlayer::Start_Inventory()
{
	while (true)
	{
		system("cls");
		Render_Inventory();
		
		cout << "1.아이템 장착 2.무기 해제 3. 방어구 해제 4.나가기" << endl;
		int iInput(0);
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			//원하는 장비 이름 입력
			cout << "장착할 아이템 이름 입력 : " << endl;
			char szTemp[32];
			cin >> szTemp;
			if (!vecInventory.empty())
			{
				for (vector<ItemBase*>::iterator Itemiter = vecInventory.begin(); Itemiter != vecInventory.end(); ++Itemiter)
				{
					if (0 == strcmp(szTemp, (*Itemiter)->Get_Info().szName))
					{
						//Itemiter 의 객체가 CWeapon인지 CArmor인지 어떻게 확인하는가?
						//RTTI 테스트
						if (typeid(**Itemiter) == typeid(CWeapon))
						{
							Set_Weapon(*Itemiter);
							cout << "무기장착";
							system("pause");
						}
						else
						{
							Set_Armor(*Itemiter);
							cout << "방어구장착";
							system("pause");
						}
						break;
					}
				}
			}
			break;
		case 2:
			if (m_pItem_Weapon != nullptr)
			{
				Set_Weapon();
				cout << "무기해제" << endl;
				system("pause");
			}
			break;
		case 3:
			if (m_pItem_Armor != nullptr)
			{
				Set_Armor();
				cout << "방어구해제" << endl;
				system("pause");
			}
			break;
		case 4:
			return;
		}
	}
}

void CPlayer::Render_Inventory()
{
	cout << "-------인벤토리-------" << endl;
	for (vector<ItemBase*>::iterator iter = vecInventory.begin();
		iter!=vecInventory.end();
		++iter)
	{
		(*iter)->Render();
	}
	cout << "------------------------" << endl;
}

void CPlayer::Render()
{
	cout << "-------------플레이어----------------------" << endl;
	cout << "이름 : " << m_Info.szName << "\t소지금 : " << m_Info.iMoney << endl;
	cout << "체력 : " << m_Info.iHp << "\t공격력 : " << m_Info.iAttack << endl;
	if (m_pItem_Weapon != nullptr)
		cout << "무기이름 : " << m_pItem_Weapon->Get_Info().szName << "\t무기공격력:" << m_pItem_Weapon->Get_Info().iAttack << endl;
	if (m_pItem_Armor != nullptr)
		cout << "방어구이름 : " << m_pItem_Armor->Get_Info().szName << "\t방어구방어력:" << m_pItem_Armor->Get_Info().iHp << endl;
	cout << "----------------------------------------------" << endl;
}
