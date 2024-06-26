#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));

	// 항등 행렬로 만드는 코드가 들어가야한다.
	
}


CObj::~CObj()
{
}

