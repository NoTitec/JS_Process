#include "stdafx.h"

class CObj
{
public:
	void		Render() { cout << "hello world" << endl; }

public:
	CObj() {
		this->m_iA = 100;
		cout << "�θ� ������" << endl; }
	~CObj() { cout << "�θ� �Ҹ���" << endl; }

protected:
	int			m_iA;
};

// #include "Obj.h"	// �ڽ� Ŭ������ ��� ���Ͽ��� �ݵ�� �θ� Ŭ������ ��� ������ �����ؾ� �Ѵ�.

class CPlayer2 : public CObj
{
public:
	CPlayer2() 
	{
		this->m_iA = 200;
		cout << "�ڽ� ������" << endl; }
	~CPlayer2() { cout << "�ڽ� �Ҹ���" << endl; }

public:
	void	Draw() { 
		cout << m_iA << endl;
		cout << "jusin academy" << endl; 
	}
};

class CMonster2 : public CObj
{
public:
	CMonster2()
	{
		m_iA = 300;
		cout << "�ڽ� ������" << endl;
	}
	~CMonster2() { cout << "�ڽ� �Ҹ���" << endl; }

public:
	void	Draw() {
		cout << m_iA << endl;
		cout << "jusin academy" << endl;
	}
};

int main()
{
	// ����� ����
	// 
	// 1. �θ� Ŭ����(base)�� �����Ϳ� ����� ��� �� �� �ֵ��� ��
	// 2. ������ �ڷ����� ����ϰ� ��

	//CObj	Obj;
	//Obj.Draw();

	 CPlayer2		Player;
	 Player.Draw();
	// Player.Render();

	 CMonster2		Monster;
	 Monster.Draw();


	// �ڽ� ��ü�� ���� ����
	// 1. �޸� �Ҵ� 2. �θ� ������ ȣ�� 3. �ڽ� ������ ȣ��

	// �ڽ� ��ü�� �Ҹ� ����
	// 1. �ڽ� �Ҹ��� ȣ�� 2. �θ� �Ҹ��� ȣ�� 3. �޸� ��ȯ


	return 0;
}