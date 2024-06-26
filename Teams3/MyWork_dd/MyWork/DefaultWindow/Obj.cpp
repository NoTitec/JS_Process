#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));

	// 항등 행렬로 만드는 코드가 들어가야한다.
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matRotZ);
	D3DXMatrixIdentity(&m_matTran);
	D3DXMatrixIdentity(&m_matRevo);
	D3DXMatrixIdentity(&m_matParent);
}


CObj::~CObj()
{
}

