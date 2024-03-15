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
int main()
{
	int iMoney(0);
	int iInput(0);

	cout << "소지금을 입력하세요" << endl;
	cin >> iMoney;

	//while 문 제어위한 bool변수 만들어놓으면 편리
	while (true)
	{
		//현재 콘솔창 내용 지우기
		system("cls");

		cout << "잔액 : "<<iMoney<<" ";
		cout << "메뉴 1. 콜라(100) 2. 사이다(200원) 3. 환타(300원) 4. 반환" << endl;
		//구매가능한지 확인위함 소지금 임시저장변수
		int iTmpMoney(iMoney);

		cin >> iInput;
		if (iInput == 4)
		{
			cout << "거스름돈은 " << iMoney << "입니다";
			break;
		}
		else if (iInput == 1)
		{
			//구매할 소지금이 충분한경우
			if ((iTmpMoney -= 100)>=0)
			{
				cout << "콜라 구매 완료"<<endl;
				iMoney-=100;
			}
			//그렇지 않은경우
			else
			{
				cout << "잔액이 부족합니다";
			}
		}
		else if (iInput == 2)
		{
			if ((iTmpMoney -= 200) >= 0)
			{
				cout << "사이다 구매 완료" << endl;
				iMoney -= 200;
			}
			//그렇지 않은경우
			else
			{
				cout << "잔액이 부족합니다";
			}
		}
		else if (iInput == 3)
		{
			if ((iTmpMoney -= 300) >= 0)
			{
				cout << "환타 구매 완료" << endl;
				iMoney -= 300;
			}
			//그렇지 않은경우
			else
			{
				cout << "잔액이 부족합니다";
			}
		}
		else
		{
			cout << "잘못된 메뉴를 선택하셨습니다";
		}
		//cout << iInput << endl;
		//키를 누를대까지 프로그램을 일시정지
		system("pause");
	}
	return 0;
}