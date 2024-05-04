#include "CInventory.h"
#include "ItemBase.h"
#include "CWeapon.h"
#include "CArmor.h"
#include "stdafx.h"
#include "Define.h"
#include "Player.h"
CInventory::CInventory() : m_iSize(5)
{
}

CInventory::~CInventory()
{
    Release();
}

bool CInventory::Add_Item(ItemBase* pItem)
{
    if (m_vecInven.size() > m_iSize)
        return false;
    //����Ÿ�� �ƴϸ�
    if (nullptr == dynamic_cast<CWeapon*>(pItem))
    {
        CArmor* Origin = static_cast<CArmor*>(pItem);
        ItemBase* Copy = new CArmor(*Origin);
        m_vecInven.push_back(Copy);
        return true;
    }
    //�����
    else
    {
        CWeapon* Origin = static_cast<CWeapon*>(pItem);
        ItemBase* Copy = new CWeapon(*Origin);
        m_vecInven.push_back(Copy);
        return true;
    }
}

bool CInventory::Sell_Item(int iIndex, int* pMoney)
{
    return false;
}

void CInventory::Initialize()
{
}

void CInventory::Update()
{
    int		iInput(0);

    while (true)
    {
        system("cls");

        m_pPlayer->Render();
        cout << "1. ���� 2. ���� 3. ������ : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Equip_Item();
            break;

        case 2:
            Unequip_Item();
            break;

        case 3:
            return;
        }
        system("pause");
    }
}

void CInventory::Render()
{
    for (size_t i = 0; i < m_vecInven.size(); ++i)
    {
        cout << i + 1 << ". ";
        m_vecInven[i]->Render();
    }
}

void CInventory::Release()
{
    //for_each�� ������� algorithm��
    for_each(m_vecInven.begin(), m_vecInven.end(), DeleteObj());
    m_vecInven.clear();
}

void CInventory::Equip_Item()
{
    int	iInput(0);

    while (true)
    {
        system("cls");

        //�÷��̾� ���� ���
        m_pPlayer->Render();
        //�κ��丮 ���
        Render();

        cout << "0. ������ : ";
        cin >> iInput;
        --iInput;

        if (0 > iInput)
            return;

        if ((size_t)iInput >= m_vecInven.size())
            continue;

        dynamic_cast<Player*>(m_pPlayer)->Equip_Item(m_vecInven[iInput]);
    }
}

void CInventory::Unequip_Item()
{
    int	iInput(0);

    while (true)
    {
        system("cls");

        m_pPlayer->Render();
        Render();

        cout << "0. ������ : ";
        cin >> iInput;
        --iInput;

        if (0 > iInput)
            return;

        if ((size_t)iInput >= m_vecInven.size())
            continue;

        dynamic_cast<Player*>(m_pPlayer)->UnEquip_Item(m_vecInven[iInput]);
    }
}
