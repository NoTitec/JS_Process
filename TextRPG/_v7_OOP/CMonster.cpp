#include "stdafx.h"
#include "CMonster.h"

CMonster::CMonster()
{
	m_iAtk = 0;
	m_iHp = 0;
	strcpy_s(m_szName, sizeof(m_szName), "");
}

CMonster::~CMonster()
{
	Release();

}

bool CMonster::Initialize(const char* name, int atk, int hp)
{
	Set_Name(name);
	Set_Atk(atk);
	Set_Hp(hp);
	return false;
}

void CMonster::Release()
{

}

char* CMonster::Get_Name()
{
	return m_szName;
}

void CMonster::Set_Name(const char* name)
{
	strcpy_s(m_szName, sizeof(m_szName), name);
}

int CMonster::Get_Atk()
{
	return m_iAtk;
}

void CMonster::Set_Atk(int atk)
{
	m_iAtk = atk;
}

int CMonster::Get_Hp()
{
	return m_iHp;
}

void CMonster::Set_Hp(int hp)
{
	m_iHp = hp;
}

void CMonster::Print_Monster_Info()
{
	cout << "===============================" << endl;
	cout << "난이도: " << m_szName << endl;
	cout << "공격력: " << m_iAtk << endl;
	cout << "체력: " << m_iHp << endl;
}

void CMonster::Take_Damage(int atk)
{
	m_iHp -= atk;
}
