#include <iostream>

using namespace std;

#pragma region ���� ����
//int main()
//{
//	// ����� ����Ű
//
//	// Ctrl + . :	���� / ���Ǻη� ���׸��� ȭ�� �����
//	// F5	: ����� ����
//	// Shfit + F5 : ����� ����
//	// F9	: �ߴ��� ����
//	// F11	: �� �ܰ辿 �ڵ� ����(�߰��� �Լ��� ������ �ű⿡ ��)
//	// F10	: ���ν��� ���� ����(���� �ڵ� ������, ���پ� ����)
//	// Ctrl + shift + f9 : ��� ����� ����Ʈ ����
//
//	int		iData(0);
//
//	if (1)
//	{
//	cout << 1 << endl;
//	iData = 1;
//	}
//	else if (1)
//	{
//	cout << 2 << endl;
//	iData = 2;
//	}
//
//	else if (1)
//	{
//	cout << 3 << endl;
//	iData = 3;
//	}
//
//	else
//	{
//	cout << 4 << endl;
//	iData = 4;
//	}
//
//	cout << iData <<"end"<< endl;
//
//
//	int		iData2(0);
//
//	if (1)
//	{
//		cout << 1 << endl;
//		iData2 = 1;
//	}
//
//	if (1)
//	{
//		cout << 2 << endl;
//		iData2 = 2;
//	}
//
//	if (1)
//	{
//		cout << 3 << endl;
//		iData2 = 3;
//	}
//
//	else
//	{
//		cout << 4 << endl;
//		iData2 = 4;
//	}
//
//	cout << iData2 << endl;
//
//	 int		iA(10), iB(20);
//	 
//	 if ((iA < iB) && (iA = 999))
//	 {
//	 	cout << iA << endl;			// ���� �ڵ� �ÿ��� �߰�ȣ ǥ�⸦ ���� �� �� �ִ�.
//	 }
//			
//
//	return 0;
//}
#pragma endregion ���� ����

#pragma region switch

int main()
{
	// switch ��(��� ���� �б⹮) : ���(����)�� ����ϸ� �Ǽ��δ� �б⸦ �� �� ����, ������ ���ǿ� ���� �ڵ��� �帧�� ����
	
	int iInput(0);

	const int iNumber(1);		// �ɺ��� ������� case�� �����ϴµ� ������ ����.

	cout << "1. �ݶ� 2. ���̴� 3. ȯŸ : ";
	cin >> iInput;
	
	switch (iInput)
	{
	case 1:						// case ���� ���� ������ �ݵ�� ������� �Ѵ�.
	{
		cout << "�ݶ�" << endl;
		int		iDst(0);
		iDst = 1;
		cout << iDst << endl;
	}
		break;						// ���� �ڵ��� �帧(��)�� Ż���Ű�� Ű����
	case 2 :
		cout << "���̴�" << endl;
		//iDst = 2;
		//cout << iDst << endl;
		break;

	case 3 :
		cout << "ȯŸ" << endl;
		//iDst = 3;
		//cout << iDst << endl;
		//break;

	default:
		cout << "�߸��� ���Դϴ�" << endl;
		break;
	}

	return 0;
}

#pragma endregion switch

#pragma region ���� ������

//int main()
//{
	// ���� ������ : �ǿ����ڰ� �� ���� ������
	// �ִ� �� �Ǵ� �ּ� ���� ���� �� �����ϰ� ����
	// �������� ������, �� �ڵ带 �ۼ��ϱ⿡ ������ ����.

	// (���ǽ�) ? (���� �� �����ϴ� �ڵ�) : (������ �� �����ϴ� �ڵ�)

	//int		iNumber1(10), iNumber2(20), iMax(0);

	//iMax = (iNumber1 > iNumber2) ? iNumber1 : iNumber2;

	//cout << iMax << endl;

	//return 0;
//}

#pragma endregion ���� ������