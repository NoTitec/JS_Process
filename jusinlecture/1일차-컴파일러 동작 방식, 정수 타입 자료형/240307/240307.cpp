//	���� �ּ� : �� �� �ȿ� �ִ� �۾��� ������ �� ����
/*	���� �ּ� : ���� ��¥�� �۾��� ������ �� ����*/

//���� ���� ���� ����
// 1. �ڵ� �ۼ� -> 2. �� ó���� -> 3. ������ -> 4. ����� -> 5. ��ũ -> 6. �������� ����

// �����Ϸ��� ���� 
// 1. �ڵ� ������ 2. ���� ���� ������

#pragma region hello world

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "Hello world" << endl;
//
//	return 0;
//}

#pragma endregion hello world

#pragma region ������ ����

#include <iostream>

using namespace std;

int main()
{
	// ���: ������ �ʴ� ����

	// ���ͷ� ��� : 10, 3.14
	// �ɺ��� ��� : ���α׷��� �� �����ϴ� � ��¡���� ��ȣ�� �̿��Ͽ� ����� ����� ���� ����
	// (ex)	const int iA(10);
	
	// ���� : �ڵ��� �帧�� ���� ���ϴ� ����

	////////////////////////////////////////////////
	// ���� : � �ڷ� Ÿ���� � �̸��� ���� �ִ��� �����Ϸ����� �˸��� ����
	// �ʱ�ȭ : �ռ� ���� ������ �޸� ������ ����ڰ� ���ϴ� ������ ä������ ����
	// ������ : ���� ���� �ȿ��� ���� �̸��� ����� �� ����

	// int	iNumber;			// int�� ���� iNumber�� �����ϴ�.
	// int	iNumber = 10;		// int�� ���� iNumber�� ����� ���ÿ� �ʱ�ȭ�ϴ�.(c��� ������ �ʱ�ȭ ���)
	// int	iNumber(10);			// int�� ���� iNumber�� ����� ���ÿ� �ʱ�ȭ�ϴ�.(c++�� �ʱ�ȭ ���)

	// cout << iNumber << endl;

	// �޸� ũ�� ���� (byte-> kb -> M -> G -> T)

	// ������ �ּ� ���� : bit
	// ������ �ּ� ���� : byte(1byte == 8bit)

	// ���� : short(2), int(4), long(4), long long(8)
	// __int16, __int32, __int64

	// unsigned : ��� ���� ����, ���� Ÿ���� �ڷ� Ÿ�Կ��� ��� ����

	unsigned short		sName = 32769;		// -32768 ~ 32767
											// 0 ~ 65535
	cout << sName << endl;

	sName = 40000;

	cout << sName << endl;

	short oName = 32768;
	cout << oName<<'\n';
	oName = -32770;
	cout << oName<<'\n';
	//�Ǽ�
	//����
	//unsigned char	cName = 65;
	//cout << cName << endl;

	//��




	return 0;
}

#pragma endregion ������ ����


