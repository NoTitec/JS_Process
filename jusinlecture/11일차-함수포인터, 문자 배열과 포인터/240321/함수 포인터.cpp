#include <iostream>

using namespace std;

void Render();
int	Add(int a, int b);
int	Minus(int a, int b);
int	Mul(int a, int b);
int	Div(int a, int b);

int main()
{
	// �Լ� ������ : �Լ��� �ּҸ� �����ϴ� �뵵�� ������

	// ��ȯŸ��(*������)(�Ű����� ����)

	void(*pFunc)() = Render;
	// pFunc = 0x008912e9 {240321.exe!Render(void)}
	pFunc();

	//int(*pPlus)(int, int) = Add;
	//cout << pPlus(10, 20) << endl;

	int	iDst(0), iSrc(0), iResult(0);
	int iInput(0);

	cout << "�� ���� ���ڸ� �Է� : ";
	cin >> iDst >> iSrc;

	cout << "1. ���� 2. ���� 3. ���� 4. ������ : ";
	cin >> iInput;

	int(*pCalc[4])(int, int) = { Add, Minus, Mul, Div };

	cout << "��� : " << pCalc[iInput - 1](iDst, iSrc) << endl;
	
#pragma region ����
	//int(*pCalc)(int, int) = NULL;

	//switch (iInput)
	//{
	//case 1:
	//	//iResult = Add(iDst, iSrc);
	//	pCalc = Add;
	//	break;

	//case 2:
	//	//iResult = Minus(iDst, iSrc);
	//	pCalc = Minus;
	//	break;

	//case 3:
	//	//iResult = Mul(iDst, iSrc);
	//	pCalc = Mul;
	//	break;

	//case 4:
	//	//iResult = Div(iDst, iSrc);
	//	pCalc = Div;
	//	break;
	//}

	//cout << "���  : " << pCalc(iDst, iSrc) << endl;
#pragma endregion ����

	return 0;
}
void Render()
{
	cout << "hello world" << endl;
}
int	Add(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}
