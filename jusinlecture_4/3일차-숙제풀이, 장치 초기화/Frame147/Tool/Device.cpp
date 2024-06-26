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
	// ��ġ �ʱ�ȭ
	// 1. SDK �İ�ü ����
	// 2. SDK �İ�ü�� �̿��Ͽ� ��ġ�� ������ ����
	// 3. �׸��� ��� DEVICE ��ü ����

	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9		DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// FAILED : ���� ������ Ȯ���ϴ� ��ũ��, ���� �� true�� ��ȯ�ϴ� ��ũ��
	// GetDeviceCaps : ��ġ�� ���� ���� ������ �ľ��ϴ� �Լ�
	// D3DADAPTER_DEFAULT : ������ �������� �⺻ �׷��� ī�带 �ǹ�

	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		AfxMessageBox(L"GetDeviceCaps Failed");
		return E_FAIL;
	}

	// ���ؽ� ���μ��� = ������ ��ȯ + ����(���) ����
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
	//��Ƽ���ϸ����
	d3dpp.MultiSampleType;
	d3dpp.MultiSampleQuality;
	//�����߿��� �ɼ�
	d3dpp.SwapEffect;
	d3dpp.hDeviceWindow;
	d3dpp.Windowed;
	d3dpp.EnableAutoDepthStencil;
	d3dpp.AutoDepthStencilFormat;

	d3dpp.FullScreen_RefreshRateInHz;
	d3dpp.PresentationInterval;
}
