#include <iostream>

using namespace std;

#include <stdio.h>

#pragma region �⺻����  ����ü ����
//struct tagInfo
//{
//	char	szName[32];			// ����ü ��� ����
//	int		iKor;
//	float	fAver;
//};

//int main()
//{



	// ����� ���� �ڷ��� : ���α׷����� �ʿ信 ���� ���� ���� ����ϴ� �ڷ���
	// �ڷ����� ��ü���� �˷��ִ� Ű���带 �ݵ�� �����ؾ� ��

	// C��� ����� ���� �ڷ��� : ����ü(struct), ����ü(union), ����ü(enum)
	// C++  ����� ���� �ڷ��� : ����ü(struct), ����ü(union), ����ü(enum) + Ŭ����(class)


	// ����ü : ���� ������ Ÿ���� ��Ƽ� �ϳ��� �ڷ������� ����� ���� �������� ����
	// ��� ���� �������� �� ��

	//tagInfo		tInfo;		// ����ü ���� ����*/

	////cout <<		tInfo.iKor << endl;
	////tagInfo		tInfo = {"ȫ�浿", 100, 3.14f };

	//cin >> tInfo.iKor;		// . : ��� ���� ������
	//cout << tInfo.iKor << endl;
	//return 0;
//}

#pragma endregion �⺻����  ����ü ����

#pragma region c��� ����ü�� c++ ����ü�� ������

 typedef struct tagInfo
{
	int		iA;
	float	fB;

	void	Render()		
	{

	}

}INFO ,*LPINFO;

//using	TEMP = struct tagInfo;

int main()
{
	// 1. c��� ������ ����ü ���� �ÿ��� �ݵ�� Ű���嵵 �����ؾ� ��.
	// //struct tagInfo		tInfo = { 10, 3.14f };
	// 2. c��� ������ ����ü�� �Լ��� ����� ���� �� ���� ����. 

	INFO		tInfo = { 10, 3.14f };
	INFO*		ptInfo = NULL;
	LPINFO		pInfo = NULL;

	pInfo = &tInfo;
	printf("%d\n", sizeof(pInfo));
	printf("%d\n", tInfo.iA);

	cout << pInfo->iA;
	return 0;
}

#pragma endregion c��� ����ü�� c++ ����ü�� ������

//struct tagInfo
//{
//	int			iC;// 4
//	char		cA[10];//1 *10		
//	short		sB;	//2	
//	long long	llD; //8	
//};
//
//struct tagTemp
//{	
//	char		cA;		// 1
//	short		sB;		// 2
//	int			iC;		// 4
//
//	tagInfo  tInfo;
//};
//
//int main()
//{
//	cout << sizeof(tagInfo) << endl;
//	//cout << sizeof(tagTemp) << endl;
//
//	tagInfo	tInfo;
//
//	tagInfo*	pInfo = &tInfo;
//
//	cout << &tInfo << endl;
//	cout << &tInfo.iC << endl;
//	cout << &tInfo.cA << endl;
//	cout << &tInfo.sB << endl;
//	cout << &tInfo.llD << endl;
//	// (*pInfo).iC = 100;
//	//pInfo->iC = 100;		// ����ü�� �ּҷ� ��� ���� �Ǵ� �Լ��� ������ ����ϴ� ������
//
//	//cout << (*pInfo).iC << endl;
//	//cout << pInfo->iC << endl;
//
//	return 0;
//}

// 1. ����ü�� �̿��Ͽ� ����ǥ ���α׷��� ������.

// 1. �Է� 2. ��� 3. �˻�(�̸�)
// - �Է� �ÿ��� �� ���� �л��� ������ �Է¸� �޴´�.
// - ��� �ÿ��� ��� �л��� ������ ��¸� �Ѵ�.
// - �˻� �ÿ��� �̸��� �Է��Ͽ� �̸��� ��ġ�� �л��� ������ ���

// 2. �ؽ�Ʈ RPG�� �ϼ��ؿͶ�.