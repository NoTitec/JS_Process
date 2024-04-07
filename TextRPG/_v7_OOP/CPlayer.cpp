#include "stdafx.h"
#include "CPlayer.h"
#include "fstream"
CPlayer::CPlayer()
{
	m_iAtk = 0;
	m_iHp = 0;
	strcpy_s(m_szName, sizeof(m_szName), "");
}

CPlayer::~CPlayer()
{
	Release();
}

bool CPlayer::Initialize(const char* name, int atk, int hp)
{
	Set_Name(name);
	Set_Atk(atk);
	Set_Hp(hp);
	return true;
}

bool CPlayer::Save_Player_Data()
{
	FILE* pFile = nullptr;
	if (0 == fopen_s(&pFile, "./Data/Save.txt", "wb"))
	{
		fwrite(this, sizeof(CPlayer), 1, pFile);
		cout << "저장 완료" << endl;

		fclose(pFile);
		return true;
	}
	else
	{
		cout << "저장 실패" << endl;
		return false;
	}
}

bool CPlayer::Load_Player_Data()
{
	ifstream readFile;
	readFile.open("./Data/Save.txt");
	if (readFile.is_open())
	{
		readFile.read((char*)this, sizeof(CPlayer));
		cout << "불러오기 성공" << endl;
		readFile.close();
		return true;
	}
	else
	{
		cout << "불러오기 실패" << endl;
		return false;
	}
}

void CPlayer::Release()
{

}

char* CPlayer::Get_Name()
{
	return m_szName;
}

void CPlayer::Set_Name(const char* name)
{
	strcpy_s(m_szName, sizeof(m_szName), name);
}

int CPlayer::Get_Atk()
{
	return m_iAtk;
}

void CPlayer::Set_Atk(int atk)
{
	m_iAtk = atk;
}

int CPlayer::Get_Hp()
{
	return m_iHp;
}

void CPlayer::Set_Hp(int hp)
{
	m_iHp = hp;
}

//CPlayer* CPlayer::Self_Return()
//{
//	return this;
//}

void CPlayer::Print_Player_Info()
{
	cout << "===============================" << endl;
	cout << "직업: " << m_szName << endl;
	cout << "공격력: " << m_iAtk << endl;
	cout << "체력: " << m_iHp << endl;
}

void CPlayer::Take_Damage(int atk)
{
	m_iHp -= atk;
}
