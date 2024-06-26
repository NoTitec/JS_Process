#include "stdafx.h"
#include "Device.h"


CDevice::CDevice()
	: m_pSDK(nullptr), m_pDevice(nullptr)
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

	if (FAILED(m_pSDK->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, vp, &d3dpp, &m_pDevice)))
	{
		AfxMessageBox(L"CreateDevice Failed");
		return E_FAIL;
	}
	
	return S_OK;
}

void CDevice::Render_Begin()
{
	m_pDevice->Clear(0, 
					nullptr,
					D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER | D3DCLEAR_TARGET, 
					D3DCOLOR_ARGB(255, 0, 0, 255), 
					1.f, 
					0);

	m_pDevice->BeginScene();
}

void CDevice::Render_End(HWND hWnd)
{
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, hWnd, nullptr);
}

void CDevice::Release()
{
	Safe_Release(m_pDevice);
	Safe_Release(m_pSDK);
}

void CDevice::Set_Parameters(D3DPRESENT_PARAMETERS & d3dpp)
{
	d3dpp.BackBufferWidth;
	d3dpp.BackBufferHeight;
	d3dpp.BackBufferFormat;
	d3dpp.BackBufferCount;
	//안티에일리어싱
	d3dpp.MultiSampleType;
	d3dpp.MultiSampleQuality;
	//가장중요한 옵션
	d3dpp.SwapEffect;
	d3dpp.hDeviceWindow;
	d3dpp.Windowed;
	d3dpp.EnableAutoDepthStencil;
	d3dpp.AutoDepthStencilFormat;

	d3dpp.FullScreen_RefreshRateInHz;
	d3dpp.PresentationInterval;
}
