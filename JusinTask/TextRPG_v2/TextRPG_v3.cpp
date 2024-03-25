#include <iostream>
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
using namespace std;

//�÷��̾� ����ü
typedef struct tagPlayer
{
    char	szName[32];
    int		iAttack;
    int		iHp;
}PLAYER, * LPPLAYER;
//���� ����ü
typedef struct tagMonster
{
    char	szName[32];
    int		iAttack;
    int		iHp;
}MONSTER, * LPMONSTER;

//���� ���̵� ����ü
enum Monsters
{
    EASY = 1,
    NORMAL,
    HARD
};

//�������� �� �������� ĳ�� �����ؼ� ��ȯ
LPPLAYER Select_Job();
//���� ���� ���� �� ��ȯ
LPPLAYER Make_Warriar();
//������ ���� ���� �� ��ȯ
LPPLAYER Make_Wizard();
//���� ���� ���� �� ��ȯ
LPPLAYER Make_Bandit();

//�Լ� ������ �迭
LPPLAYER(*pFunc[3])() = { Make_Warriar,Make_Wizard,Make_Bandit };

void RenderPlayer(LPPLAYER lpplayer);
void RenderMonster(LPMONSTER lpmonster);

//����� �Լ�
void Into_Field(LPPLAYER lpplayer);
//���� ���� �Լ�
LPMONSTER Create_Monster(int iDifficult);
//����
void Fight(LPPLAYER lpPlayer, LPMONSTER lpMonster);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    LPPLAYER lpPlayer = nullptr;
        //���� �����ϱ�
    lpPlayer = Select_Job();
        
    while (true)
    {
        int iInput(0);
        system("cls");
        RenderPlayer(lpPlayer);

        cout << "1. ����� 2. ���� : ";
        cin >> iInput;

        if (iInput == 2)
        {
            //����� �÷��̾� �޸� ��ȯ �� ����
            delete lpPlayer;
            lpPlayer = nullptr;
            return 0;
        }
        else
        {
            //����� ����
            Into_Field(lpPlayer);
        }
    }
    
    return 0;
}

LPPLAYER Select_Job()
{
	//�÷��̾� ������ ����
	LPPLAYER tTemp;
	int		iInput(0);

	cout << "������ �����ϼ���(1. ���� 2. ������ 3 ����) : ";
	cin >> iInput;
    tTemp = pFunc[iInput - 1]();
	//�������ÿ� ���� ���� �� �ش� ���޸� ������ tTemp ��ȯ
	return tTemp;
}

LPPLAYER Make_Warriar()
{
	LPPLAYER warriar = new PLAYER;
	strcpy_s(warriar->szName, sizeof(warriar->szName), "����");
	warriar->iAttack = 10;
	warriar->iHp = 100;

	return warriar;
}

LPPLAYER Make_Wizard()
{
    LPPLAYER wizard = new PLAYER;
    strcpy_s(wizard->szName, sizeof(wizard->szName), "������");
    wizard->iAttack = 10;
    wizard->iHp = 100;

    return wizard;
}

LPPLAYER Make_Bandit()
{
    LPPLAYER bandit = new PLAYER;
    strcpy_s(bandit->szName, sizeof(bandit->szName), "����");
    bandit->iAttack = 10;
    bandit->iHp = 10;

    return bandit;
}

void Into_Field(LPPLAYER lpplayer)
{
    //�Է� ���� ����
    int	iInput(0);

    //
    while (true)
    {
        system("cls");
        RenderPlayer(lpplayer);

        cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
        cin >> iInput;

        if (4 == iInput)
            return;

        //���� ���� ���ý� ���� ���̵� ���� ���� ���� ���� �� ���� ����
        else if (3 >= iInput)
        {
            LPMONSTER lpMonster = Create_Monster(iInput);
            Fight(lpplayer, lpMonster);
        }
    }
}

void RenderPlayer(LPPLAYER lpplayer)
{
    cout << "----------------------------------------" << endl;
    cout << "�̸� : " << lpplayer->szName << endl;
    cout << "ü�� : " << lpplayer->iHp << "\t���ݷ� : " << lpplayer->iAttack << endl;
}
void RenderMonster(LPMONSTER lpmonster)
{
    cout << "----------------------------------------" << endl;
    cout << "�̸� : " << lpmonster->szName << endl;
    cout << "ü�� : " << lpmonster->iHp << "\t���ݷ� : " << lpmonster->iAttack << endl;
}

LPMONSTER Create_Monster(int iDifficult)
{
    LPMONSTER tTemp = new MONSTER{};
    const int iBaseHP(30);
    const int iBaseAtk(3);

    switch (iDifficult)
    {
    case EASY:
        strcpy_s(tTemp->szName, sizeof(tTemp->szName), "�ʱ�");
        tTemp->iHp = EASY * iBaseHP;
        tTemp->iAttack = EASY * iBaseAtk;
        break;
    case NORMAL:
        strcpy_s(tTemp->szName, sizeof(tTemp->szName), "�߱�");
        tTemp->iHp = NORMAL * iBaseHP;
        tTemp->iAttack = NORMAL * iBaseAtk;
        break;

    case HARD:
        strcpy_s(tTemp->szName, sizeof(tTemp->szName), "���");
        tTemp->iHp = HARD * iBaseHP;
        tTemp->iAttack = HARD * iBaseAtk;
        break;
    default:

        break;
    }
    return tTemp;
}

void Fight(LPPLAYER lpPlayer, LPMONSTER lpMonster)
{
    int iInput(0);

    while (true)
    {
        system("cls");
        RenderPlayer(lpPlayer);
        RenderMonster(lpMonster);

        cout << "1. ���� 2. ���� : ";
        cin >> iInput;

        if (1 == iInput)
        {
            lpMonster->iHp -= lpPlayer->iAttack;
            lpPlayer->iHp -= lpMonster->iAttack;

            if (0 >= lpPlayer->iHp)
            {
                cout << "�÷��̾� ���" << endl;
                lpPlayer->iHp = 100;
                system("pause");
                return;
            }
            //���� ó���� ���� �� �޸� ��ȯ
            if (0 >= lpMonster->iHp)
            {
                cout << "�¸�" << endl;
                delete lpMonster;
                lpMonster = nullptr;

                system("pause");
                return;
            }
        }
        // ����ģ ��� ���� �� �޸� ��ȯ
        else if (2 == iInput) {
            delete lpMonster;
            lpMonster = nullptr;
            return;
        }
    }

}