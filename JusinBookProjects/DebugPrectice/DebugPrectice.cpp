// DebugPrectice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>

using namespace std;
int methodA(int num)
{
    return num;
};
int methodB()
{
    return 1;
};
int methodC(int num1, int num2)
{
    return num1 + num2;
};
int methodD(int num1, int num2)
{
    return num1 - num2;
}
int main()
{
    int num1 = 7;

    int num2 = methodA(num1);
    int num3 = methodB();
    int num4 = methodC(num2,num3);
    int num5 = methodD(num3,num2);

}

