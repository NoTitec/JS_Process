#pragma once

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600
#define			VK_MAX				0xff
extern HWND g_hWnd;

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// 위치벡터
	
	D3DXVECTOR3		vDir;		// 방향벡터
	D3DXVECTOR3		vLook;		// 방향벡터

	D3DXVECTOR3		vNormal;	// 법선 벡터(방향벡터)	

	D3DXMATRIX		matWorld;


}INFO;

static D3DXVECTOR3	Get_Mouse()
{
	POINT	ptMouse{};

	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	return D3DXVECTOR3((float)ptMouse.x, (float)ptMouse.y, 0.f);
}



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


//////////////////////////////////////////////////////////
// 행렬 : 여러 개의 숫자를 행과 열의 상태로 정돈해 놓은 상태
// 행렬을 사용하는 이유 : 객체의 여러 상태(크기, 회전, 위치)를 표현하기 위함

// 4 X 4(4행 4열) : 정방 행렬(행과 열의 수가 일치하는 형태의 행렬)

// 항등 행렬 : 항상 어떤 연산을 하더라도 이 행렬과 연산을 수행하는 피연산의 행렬의 값으로 결과가 발생

// 1  0	 0	0
// 0  1	 0	0
// 0  0	 1	0
// 0  0	 0	1

// _11, _12, _13, _14
// _21, _22, _23, _24
// _31, _32, _33, _34
// _41, _42, _43, _44
//
//	크기 정보를 저장하는 원소(x, y, z 순서의 배율) : _11, _22, _33
//
//	x축 회전 정보를 저장하는 원소 : _22(cos), _23(sin), _32(-sin), _33(cos)
//	y축 회전 정보를 저장하는 원소 : _11(cos), _13(-sin), _31(sin), _33(cos)
//	z축 회전 정보를 저장하는 원소 : _11(cos), _12(sin), _21(-sin), _22(cos)
//
//	위치 정보를 저장하는 원소(x, y, z 순서) : _41, _42, _43


// 항등 행렬을 만들어주는 함수
// D3DXMatrixIdentity(항등 행렬을 만들고자 하는 행렬의 주소)

// 크기 변환 행렬을 만들어주는 함수
// D3DXMatrixScaling(결과 값을 저장할 행렬의 주소, x배율, y배율, z배율)

// 회전 변환 행렬을 만들어주는 함수
// D3DXMatrixRotationZ(결과 값을 저장할 행렬의 주소, 회전 각도(라디안))

// 위치 변환 행렬을 만들어주는 함수
// D3DXMatrixTranslation(결과 값을 저장할 행렬의 주소, x좌표, y좌표, z좌표)

// 벡터와 행렬을 곱셈 시켜주는 함수
// D3DXVec3TransformCoord(결과 위치 벡터, 위치 벡터 주소, 행렬의 주소)
// D3DXVec3TransformNormal(결과 방향 벡터, 방향 벡터 주소, 행렬의 주소)

// 숙제 : z축 회전을 이용하여 포신과 몸체가 따로 회전하는 탱크 구현하기
