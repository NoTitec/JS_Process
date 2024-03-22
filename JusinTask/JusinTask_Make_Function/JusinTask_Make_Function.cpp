// JusinTask_Make_Function.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
// 2. 자판기 게임
/*
- 소지금을 입력받고 항상 잔액을 출력한다
- 메뉴는 1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환
- 해당 목록을 선택하여 구매 시, "xx 구매 완료"를 출력
- 단, 소지금이 부족할 경우 잔액이 부족합니다 출력
- 4번을 누르면 "거스름 돈은 <잔액>입니다" 출력 후, 프로그램 종료
*/

//소지금입력함수
int Get_Money();
//잔액출력하고 메뉴 출력하는 함수
void Print_LeftMoneyandMenu(int iMoney);
//선택메뉴에따라 동작 수행후 잔액 반환하는 함수
int DoTask_By_Select_Menu(int iMoney,int iSelectMenu);

int main()
{
	int		iMoney(0), iInput(0);
	bool	bChoice(true);

	iMoney = Get_Money();
	while (bChoice)
	{
		system("cls");
		Print_LeftMoneyandMenu(iMoney);
		cin >> iInput;

		if (iInput == 4) {
			cout << "잔액은 " << iMoney << " 원 입니다" << endl;
			bChoice = false;
			break;
		}
		else
		{
			iMoney=DoTask_By_Select_Menu(iMoney, iInput);
		}

		system("pause");
	}

	return 0;
}

int Get_Money()
{
	int iMoney(0);
	cout << "돈을 넣어주세요 : ";
	cin >> iMoney;
	return iMoney;
}

void Print_LeftMoneyandMenu(int iMoney)
{
	cout << "잔액 : " << iMoney << endl;
	cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
}

int DoTask_By_Select_Menu(int iMoney,int iSelectMenu)
{
	int iCoke(100), iCider(200), iFanta(300);
	switch (iSelectMenu)
	{
	case 1:
		if (iMoney >= iCoke)
		{
			cout << "콜라 구매 완료" << endl;
			iMoney -= iCoke;
		}
		else
		{
			cout << "잔액이 부족합니다" << endl;
		}
		break;

	case 2:
		if (iMoney >= iCider)
		{
			cout << "사이다 구매 완료" << endl;
			iMoney -= iCider;
		}
		else
		{
			cout << "잔액이 부족합니다" << endl;
		}
		break;

	case 3:
		if (iMoney >= iFanta)
		{
			cout << "환타 구매 완료" << endl;
			iMoney -= iFanta;
		}
		else
		{
			cout << "잔액이 부족합니다" << endl;
		}
		break;
	default:
		cout << "잘못 누르셨습니다" << endl;
		break;
	}
	return iMoney;
}
