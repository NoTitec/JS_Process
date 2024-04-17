#include "CField.h"
#include "CMonster.h"
CField::CField() : m_pPlayer(nullptr),m_pMonster(nullptr)
{
}

CField::~CField()
{
	Release();
}
void CField::Set_Player(CBase* pPlayer)
{
	m_pPlayer = pPlayer;
}
int CField::Fight()
{
	int	iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (1 == iInput)
		{
			m_pMonster->Take_Damage(m_pPlayer->Get_Info().iAttack);
			m_pPlayer->Take_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "플레이어 사망" << endl;
				system("pause");
				return 1;
			}
			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "승리" << endl;
				system("pause");
				return 0;
			}

		}
		else if (2 == iInput)
			return 0;
	}
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("초급", 3, 30);
			break;

		case 2:
			m_pMonster = new CMonster("중급", 6, 60);
			break;

		case 3:
			m_pMonster = new CMonster("고급", 9, 90);
			break;

		case 4:
			return;
		}

		int iResult = Fight();

		if (1 == iResult)
		{
			static_cast<CPlayer*>(m_pPlayer)->Set_Hp(100);
		}
		else
		{
			SAFE_DELETE(m_pMonster);
		}

		system("pause");
	}
}

void CField::Release()
{
}
