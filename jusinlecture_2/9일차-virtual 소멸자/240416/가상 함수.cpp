#include "stdafx.h"

#pragma region ����ȭ ��
class CObj1
{
public:
	virtual void		Render() = 0;
};

class CPlayer1 : public CObj1
{
public:
	virtual void		Render() {	cout << "player" << endl;}
	virtual void		Draw() = 0;
};

class CThief : public CPlayer1
{
public:
	virtual void		Render() { cout << "thief" << endl; }
	virtual void		Draw() { cout << "thief Draw" << endl; }
};


int main()
{
	CObj1* pPlayer = new CThief;

	pPlayer->Render();

	return 0;
}

#pragma endregion ����ȭ ��

#pragma region ���� �Ҹ���

//class CObj1
//{
//public:
//	CObj1() { cout << "�θ� ������" << endl; }
//	virtual ~CObj1() { cout << "�θ� �Ҹ���" << endl; }
//};
//
//class CPlayer1 : public CObj1
//{
//public:
//	CPlayer1() { cout << "�ڽ� ������" << endl; }
//	~CPlayer1() { cout << "�ڽ� �Ҹ���" << endl; }
//};
//
//int main()
//{
//	/*CObj1*		pObj = new CObj1;
//
//	delete pObj;
//	pObj = nullptr;*/
//
//	CObj1*		pPlayer = new CPlayer1;
//
//	delete pPlayer;
//	pPlayer = nullptr;
//
//
//
//
//	return 0;
//}



#pragma endregion ���� �Ҹ���
