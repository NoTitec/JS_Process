#pragma once
enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	LOAD,
	END
};
class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	bool Initialize(const char* name, int atk, int hp);
	bool Save_Player_Data();
	bool Load_Player_Data();
	void Release();
	//CPlayer* Self_Return();
	char* Get_Name();
	void Set_Name(const char* name);
	int Get_Atk();
	void Set_Atk(int atk);
	int Get_Hp();
	void Set_Hp(int hp);
	void Print_Player_Info();
	void Take_Damage(int atk);
private:
	char m_szName[20];
	int m_iAtk;
	int m_iHp;

};

