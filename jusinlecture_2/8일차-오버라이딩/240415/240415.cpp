// 240415.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// �߻� Ŭ���� : ���� ���� �Լ��� �� ���� �ִ� Ŭ����

class CObj
{
public:
	virtual void	Render() = 0;		// ���� ���� �Լ�(overring�� ���� ����)
	virtual void	Draw() { cout << "Obj Draw" << endl; }
};

class CPlayer : public CObj
{
public:
	void	Render() { cout << "player" << endl; }
};

class CMonster : public CObj
{
public:
	void	Render() {}
};

	
int main()
{
	// ���� ���̵��� ����
	// 
	// 1. �θ�� �ڽ��̶�� ��� ���迩�� ��
	// 2. �θ�� �ڽ� Ŭ������ ���°� �Ϻ��� ��ġ�ϴ� �Լ��� �����ؾ� �Ѵ�.
	// 3. �θ� Ŭ������ �Լ� �տ� �ݵ�� virtual Ű���尡 ���� �Ǿ�� �Ѵ�.

	//cout << sizeof(CObj) << endl;
	//
	//cout << sizeof(CPlayer) << endl;

	// CObj Obj;
	// Obj.Render();

	// CPlayer		Player;
	// Player.Render();

	CObj*		pObj = new CMonster;
	//__vfptr = 0x00e58c4c {240415.exe!const CObj::`vftable'} {0x00e514a6 {240415.exe!CObj::Render(void)}, 0x00e514ce {240415.exe!CObj::Draw(void)}}
	//pObj->Render();

	//CObj*		pPlayer = new CPlayer;
	//__vfptr = 0x00e58d4c {240415.exe!const CPlayer::`vftable'} {0x00e514c4 {240415.exe!CPlayer::Render(void)}, 0x00e514ce {240415.exe!CObj::Draw(void)}}
	//pPlayer->Render();

	/*CObj*	pPlayer = new CPlayer;

	pPlayer->Render();

	delete pPlayer;
	pPlayer = nullptr;*/

	// 1. �θ� �Լ�
	// 2. �ڽ� �Լ�
	// 3. ������ ����

    return 0;
}

