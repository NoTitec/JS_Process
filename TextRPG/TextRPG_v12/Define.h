#pragma once
#include "stdafx.h"

#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

//캐릭터 정보 구조체
typedef struct tagCharacterInfo
{
	char szName[32];
	int iAttack;
	int iHp;
	int iMoney;

	tagCharacterInfo(){
		memset(&szName, 0, sizeof(szName));
		iAttack = 0;
		iHp = 0;
		iMoney = 0;
	}
	//몬스터 생성자
	tagCharacterInfo(const char* _pName, int _iAttack, int _iHp)
	{
		strcpy_s(szName, sizeof(szName), _pName);
		iAttack = _iAttack;
		iHp = _iHp;
		iMoney = -1;
	}
	//플레이어 생성자
	tagCharacterInfo(const char* _pName, int _iAttack, int _iHp, int _iMoney)
	{
		strcpy_s(szName, sizeof(szName), _pName);
		iAttack = _iAttack;
		iHp = _iHp;
		iMoney = _iMoney;
	}
}CHARACTERINFO;

//아이템 정보 구조체
typedef struct tagItemInfo
{
	char szName[32];
	int iAttack;
	int iHp;
	int iMoney;

	tagItemInfo() {
		memset(&szName, 0, sizeof(szName));
		iAttack = 0;
		iHp = 0;
		iMoney = 0;
	}
	
	tagItemInfo(const char* _Name, int _iAttack, int _iHp,int _iMoney)
	{
		strcpy_s(szName, sizeof(szName), _Name);
		iAttack = _iAttack;
		iHp = _iHp;
		iMoney = _iMoney;
	}
}ITEMINFO;

//포인터 해제 함수 템플릿
template<typename T>
void Safe_Delete(T& Pointer)
{
	if (Pointer)
	{
		delete Pointer;
		Pointer = nullptr;
	}
}

//포인터 해제 클래스 템플릿
struct DeleteObj
{
	template<typename T>
	void operator()(T& Pointer)
	{
		if (Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
	}
};