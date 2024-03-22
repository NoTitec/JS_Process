// JusinTask_Factorial_Recursion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int Factorial_Recursion(int Number);
int main()
{
    bool bEnd(true);
    int iInput(0),iResult(0);

    while (bEnd)
    {
        system("cls");
        cout << "종료하려면 -1입력 그외 원하는 팩토리얼 값 입력"<<endl;
        cin >> iInput;
        if (iInput == -1)
        {
            bEnd = false;
            return 0;
        }
        else
        {
            iResult = Factorial_Recursion(iInput);
            cout << iResult << endl;
        }
        system("pause");
    }

    return 0;
}

int Factorial_Recursion(int Number)
{
    if (Number == 0)
    {
        return 1;
    }
    return Number*Factorial_Recursion(Number-1);
}
