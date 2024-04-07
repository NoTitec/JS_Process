#pragma once
class CMonster
{
public:
	CMonster();
	~CMonster();
public:
	bool Initialize(const char* name, int atk, int hp);
	void Release();
	char* Get_Name();
	void Set_Name(const char* name);
	int Get_Atk();
	void Set_Atk(int atk);
	int Get_Hp();
	void Set_Hp(int hp);
	void Print_Monster_Info();
	void Take_Damage(int atk);
private:
	char m_szName[20];
	int m_iAtk;
	int m_iHp;
};

