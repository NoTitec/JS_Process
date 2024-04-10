#pragma once

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

typedef struct tagInfo
{
	char	szName[32];
	int		iAttack;
	int		iHp;

}INFO;
