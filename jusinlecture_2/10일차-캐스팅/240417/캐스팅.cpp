// 240417.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CObj
{
public:
	virtual ~CObj() {}
};
class CPlayer{};
class CPlayer2 : public CObj 
{
public:
	void	Render() { cout << "player2" << endl; }
};

int main()
{
	// static_cast, dynamic_cast, const_cast, reinterpret_cast

#pragma region static_cast ������

	//int		iNumber = (int)3.14;

	// static_cast : ���� ĳ����, �� ��ȯ ������ ������ Ÿ��, c��� ������ ĳ��Ʈ�� ���� ����
	// c����� ĳ���� ���ٴ� ������
	// static_cast�� ������ �� ��ȯ�� ���� : Ŭ������ ��� ���迡 ������ �����̶�� �Ǵ�

	// ���輺 : ������ Ÿ�ӿ� �����ϴ� �� ��ȯ�̾ �� Ÿ�� ��, Ÿ�� üũ�� ���� �ʾ� ������ ��ȯ�� �������� ���Ѵ�.

	// int		iNumber = static_cast<int>(3.14);
	// cout << iNumber << endl;

	// CPlayer*	pPlayer = new CPlayer;

	// CObj*		pObj = (CObj*)pPlayer;	// c���
	// CObj*		pObj2 = static_cast<CObj*>(pPlayer);	// ������ �� ��ȯ�� �ƴ� ��� ĳ������ ������� ����

	// CObj*		pObj = new CObj;
	// 
	// CPlayer2*	pPlayer = static_cast<CPlayer2*>(pObj);		
	// pPlayer->Render();

#pragma endregion static_cast ������

#pragma region dynamic_cast ������

	// dynamic_cast ������ : �� Ÿ�ӿ� ĳ������ ����
	// 
	// 1. �Ϲ� �ڷ��� �Ǵ� �Ϲ� �ڷ��� �����ʹ� ��� �� �� ����
	// 2. ��ü ������ ���� �� ��ȯ�� ������� ����(down casting��)
	// 3. �θ�� �ڽ��̶�� Ŭ���� ��� ���迩�� ��
	// 4. �θ� Ŭ������ ���� �Լ��� �ϳ��� �־�� ��� ����
	// 5. ������� ĳ������ ��� nullptr�� ��ȯ


	//CObj*		pObj = new CObj;
	//CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);
	//CPlayer2*	pPlayer2 = dynamic_cast<CPlayer2*>(pObj);

	//if (nullptr == pPlayer2)
	//	cout << "�̻���" << endl;

	//pPlayer2->Render();

	/*CObj*		pObj = new CPlayer2;

	static_cast<CPlayer2*>(pObj)->Render();
	dynamic_cast<CPlayer2*>(pObj)->Render();*/


#pragma endregion dynamic_cast ������

#pragma region const_cast ������

	// const_cast : const�� ������ �����ϴ� ĳ���� ������, ��, �����ͳ� ���۷��� ���� ����

	// const int iData = 10;
	// const_cast<int>(iData) += 10;

	// int		iNumber(10);
	// 
	// const int*		ptr = &iNumber;		// �б� ���� ������
	// 
	// int*	ptr2 = const_cast<int*>(ptr);
	// 
	// *ptr2 = 20;
	// 
	// cout << iNumber << endl;

#pragma endregion const_cast ������

#pragma region reinterpret_cast

	// reinterpret_cast : const �����͸� ������ ��� �������� �� ��ȯ�� ���, �� ������ �� ��ȯ�� ���
	// ���� �� �� ���� ����� �ʷ��ϱ� ������ ����� ������ ���� ����

	// CPlayer2*	pPlayer = new CPlayer2;
	// CObj*		pObj = reinterpret_cast<CObj*>(pPlayer);

	// int		iNumber(65);
	// char*	ptr = reinterpret_cast<char*>(&iNumber);
	// cout << ptr << endl;
	
#pragma endregion reinterpret_cast

    return 0;
}

