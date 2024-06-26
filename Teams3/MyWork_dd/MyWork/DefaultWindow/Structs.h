#pragma once

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// 위치벡터
	D3DXVECTOR3		vDir;		// 방향벡터
	D3DXVECTOR3		vLook;		// 방향벡터
	D3DXVECTOR3		vNormal;	// 법선 벡터(방향벡터)
	D3DXMATRIX		matWorld;
}INFO;


// 벡터의 상등 : 두 벡터의 크기와 방향이 같을 경우, 두 벡터는 같다는 의미

// 단위 벡터 : 벡터의 크기가 1인 상태
// 벡터의 정규화 : 벡터의 크기를 1로 만드는 과정


// A(x,  y,  z)
// B(x`, y`, z`)
// 
// D3DXVECTOR3(x * x`, y * y`, z * z`)

// 내적 : 두 방향 벡터가 필요, 스칼라(상수) 곱, 내적의 결과 x * x` + y * y` + z * z`, A • B, D3DXVec3Dot

// 외적 : 두 방향 벡터가 필요, 벡터 곱(방향 벡터), A X B, D3DXVec3Cross

// 마우스 포인터를 따라가는 플레이어를 만들어라.
// 뺄셈과 내적을 이용하여 따라다니게 만들어라. (임의의 1,0,0 벡터를 하나 주고 시작)




