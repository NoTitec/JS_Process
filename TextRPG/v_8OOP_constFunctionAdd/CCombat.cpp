#include "CCombat.h"
#include "stdafx.h"
CCombat::CCombat()
{
}

CCombat::~CCombat()
{
}

int CCombat::Battle(CPlayer* player, CMonster* monster)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		player->Render();
		monster->Render();

		cout << "1.���� 2.����:";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			player->Take_Damage(monster->Get_Attack());
			monster->Take_Damage(player->Get_Attak());

			if (0 >= player->Get_Hp())
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return 1;
			}
			if (0 >= monster->Get_Hp())
			{
				cout << "�¸�" << endl;
				system("pause");
				return 0;
			}
			break;
		case 2:
			return 0;
		}
		//system("pause");
	}
}
