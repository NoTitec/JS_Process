// 240404.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include "Define.h"

// ��� ����(������) + ��� �Լ�(���)

// 1. ���� ���� �����ڸ� �̿��� ����ȭ ����
// 2. access method�� �̿��� ������ ����

class CObj
{
public:
	void		Render();	// ��� �Լ�

public:		// access method
	void		Set_Hp(int _iHp)	{ m_iHp = _iHp; }
	int			Get_Hp()			{ return m_iHp; }

	void		Set_Attack(int _iAttack) { m_tInfo.iAttack = _iAttack; }
	INFO		Get_Info() { return m_tInfo; }

private :
	int		m_iHp;		// ��� ����
	INFO	m_tInfo;
};

//void	Render()		// ���� �Լ�
void	CObj::Render()	// ��� �Լ�
{
	cout << m_iHp << endl;
}
struct tagInfo
{
public :
	int		iHp;
};

int main()
{
	// C++
	// OOP + Generic Programming

	// Ŭ������ 4�� �Ӽ�
	// ����ȭ, ĸ��ȭ, ��Ӽ�, ������



	/*tagInfo	tInfo = { 100 };

	tInfo.iHp = 200;

	cout << tInfo.iHp << endl;*/

	 CObj	Obj;

	 Obj.Set_Hp(100);
	
	 cout << Obj.Get_Hp() << endl;

	 cout << Obj.Get_Info().iAttack << endl;

	 //Obj.Render();
	
	
	 //cout << tInfo.m_iHp << endl;


    return 0;
}

// ����ǥ ���α׷��� Ŭ������ ����� ���� �迭�� �����϶�

//- �Է��� ������ �� ���� �Է��� �� ���� �Է��� ����
//- ����� ������ ���
//- �Է��� �ٽ� ������ �߰� �Է��� �ǵ��� ���� ��