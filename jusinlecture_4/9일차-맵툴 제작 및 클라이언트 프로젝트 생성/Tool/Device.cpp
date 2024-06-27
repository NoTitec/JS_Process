#include "stdafx.h"
#include "Device.h"

IMPLEMENT_SINGLETON(CDevice)

CDevice::CDevice()
	: m_pSDK(nullptr), m_pDevice(nullptr), m_pSprite(nullptr), m_pFont(nullptr)
{
}


CDevice::~CDevice()
{
	Release();
}

HRESULT CDevice::Init_Device()
{
	// 장치 초기화
	// 1. SDK 컴객체 생성
	// 2. SDK 컴객체를 이용하여 장치의 성능을 조사
	// 3. 그리기 담당 DEVICE 객체 생성

	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9		DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// FAILED : 성공 유무를 확인하는 매크로, 실패 시 true를 반환하는 매크로
	// GetDeviceCaps : 장치에 대한 지원 수준을 파악하는 함수
	// D3DADAPTER_DEFAULT : 정보를 얻어오려는 기본 그래픽 카드를 의미

	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		AfxMessageBox(L"GetDeviceCaps Failed");
		return E_FAIL;
	}

	// 버텍스 프로세싱 = 정점의 변환 + 조명(명암) 연산
	DWORD	vp(0);

	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	D3DPRESENT_PARAMETERS		d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	Set_Parameters(d3dpp);

	if (FAILED(m_pSDK->CreateDevice(D3DADAPTER_DEFAULT, 
									D3DDEVTYPE_HAL, 
									g_hWnd,
									vp, 
									&d3dpp, 
									&m_pDevice)))
	{
		AfxMessageBox(L"CreateDevice Failed");
		return E_FAIL;
	}
	
	// 스프라이트 컴 객체
	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
	{
		AfxMessageBox(L"D3DXCreateSprite Failed");
		return E_FAIL;
	}

	// 폰트 컴객체

	D3DXFONT_DESCW	tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESCW));

	tFontInfo.Height = 20;
	tFontInfo.Width = 10;
	tFontInfo.Weight = FW_HEAVY;
	tFontInfo.CharSet = HANGEUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, L"궁서");

	if (FAILED(D3DXCreateFontIndirect(m_pDevice, &tFontInfo, &m_pFont)))
	{
		AfxMessageBox(L"Create Font Failed");
		return E_FAIL;
	}

	return S_OK;
}

// 후면 버퍼 동작 원리

void CDevice::Render_Begin()
{
	m_pDevice->Clear(0,		// 렉트 개수
					nullptr,// 렉트 중 첫 번 째 주소
					D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, 
					D3DCOLOR_ARGB(255, 0, 0, 255), // 후면 버퍼 색상
					1.f, // 깊이 버퍼 초기화 값
					0);	 // 스텐실 버퍼 초기화 값

	m_pDevice->BeginScene();

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CDevice::Render_End(HWND hWnd)
{
	m_pSprite->End();
	m_pDevice->EndScene();
	// Present : 후면 버퍼에서 전면 버퍼로 화면을 전환
	
	// 1, 2번 인자 : 스왑 체인 옵션이 D3DSWAPEFFECT-COPY로 지정되어있지 않는 한 NULL
	// 4번 인자 : 스왑 체인 옵션이 D3DSWAPEFFECT-COPY로 지정되어있지 않는 한 NULL
	m_pDevice->Present(NULL, NULL, hWnd, NULL);
}

void CDevice::Release()
{
	Safe_Release(m_pFont);
	Safe_Release(m_pSprite);
	Safe_Release(m_pDevice);
	Safe_Release(m_pSDK);
}

void CDevice::Set_Parameters(D3DPRESENT_PARAMETERS & d3dpp)
{
	d3dpp.BackBufferWidth  = WINCX;
	d3dpp.BackBufferHeight = WINCY;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount  = 1;

	d3dpp.MultiSampleType	 = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	// D3DSWAPEFFECT_DISCARD : 스왑 체인 방식
	// D3DSWAPEFFECT_FLIP : 하나의 버퍼를 뒤집으면서 사용하는 방식
	// D3DSWAPEFFECT_COPY : 더블 버퍼링과 유사한 복사 방식

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.hDeviceWindow = g_hWnd;

	// 창 모드로 출력할 것인가 전체 화면 모드로 출력할 것인가
	d3dpp.Windowed = TRUE;	// 창 모드 지정

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	// 전체 화면 모드일 때만 적용되는 옵션

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	// 모니터 재생률과 시연 간격 설정 옵션
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}
