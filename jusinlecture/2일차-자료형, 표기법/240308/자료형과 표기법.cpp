#include <iostream>

using namespace std;

int main()
{
#pragma region �Ǽ� Ÿ�� �ڷ���

	// float(4), double(8), long double(8)
	// �Ҽ��� ������ ���� ���� ������ ���� ���е��� ���ٶ�� ���� �� �ִ�.

	//float		fTime = 3.14f;		// f��  float ���� �ǹ��ϴ� ��� ��ȣ
	//int		iData = 10;
	//long		lData = 10l;

#pragma endregion �Ǽ� Ÿ�� �ڷ���

#pragma region ���� Ÿ�� �ڷ���

	//char(1),			wchar_t(2)
	//�ƽ�Ű�ڵ� ǥ		�����ڵ� ǥ

	// SBCS(�ƽ�Ű�ڵ常 ���)	->	MBCS(�ƽ�Ű, �����ڵ� ���Ͽ� ���) -> WBCS(�����ڵ�� ����)
	
	// ABCD		-> 4byte
	// ��������	-> 8byte
	
	// char		cName = 'A';
	// cName = "Hello world";
	// cout << cName << endl;
	
	// char	cName = 65;
	// cout << cName << endl;
	
#pragma endregion ���� Ÿ�� �ڷ���

#pragma region �� Ÿ�� �ڷ���

	// bool(1) : �� �Ǵ� ������ ǥ���ϱ� ���� �ڷ���

	// bool		bSelect = true;		// false
	// cout << bSelect << endl;

#pragma endregion �� Ÿ�� �ڷ���

#pragma region ���� �̸� ����� ǥ���

	// ���� �̸� ����

 // 1. ���� �̸��� ���ĺ��� ���ڷ� ���� �� �� �ִ�.��, ���ڰ� �� �� ���ڷ� �� �� ����
 // 2. ���� �̸��� ��ҹ��ڸ� Ȯ���� �����Ѵ�.
 // 3. ���α׷��ֿ��� �����ϴ� Ű����� ���� �̸��� ���� �� ����.
 // (ex) int namespace; (x)
 // 4. ���� �̸��� ���� �Ǵ� Ư�� ���ڰ� �� �� ����. ��, _�� ��� (ex) int iPlayer_Hp;
 // 5. ���� �̸��� ������ ���� �������� �� ����(�� ����)�� �� ����.

 // ǥ���

 // 1. �밡���� ǥ��� : ���� �̸� �տ� �ڷ����� �ǹ��ϴ� ���ĺ��� ����
 // int iHp, float fAver;
 
 // 2. ī�� ǥ��� : �ܾ�� �ܾ� ���̸� �빮�ڸ� �����Ͽ� ����
 // int playerHp;
 
 // 3. �Ľ�Į ǥ��� : ���� �̸����� ù ���ڸ� �빮�ڷ� ǥ���ϴ� ���
 // int PlayerHp;
 
 // 4. ����� ǥ��� : �ܾ�� �ܾ� ���̿� _�� ����
 // void	Attack_Monster(int _iAttack);

#pragma endregion ���� �̸� ����� ǥ���

	return 0;
}