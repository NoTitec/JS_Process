#pragma once

#include "Include.h"

class CDevice
{
public:
	CDevice();
	~CDevice();

public:
	LPDIRECT3DDEVICE9		Get_Device() { return m_pDevice; }

public:
	HRESULT		Init_Device();
	void		Render_Begin();
	void		Render_End(HWND hWnd = nullptr);
	void		Release();

private:
	void		Set_Parameters(D3DPRESENT_PARAMETERS& d3dpp);

private:
	LPDIRECT3D9			m_pSDK;		// 그래픽 카드 성능 조사
	LPDIRECT3DDEVICE9	m_pDevice;	// 각종 그리기 함수를 제공하는 객체

};

