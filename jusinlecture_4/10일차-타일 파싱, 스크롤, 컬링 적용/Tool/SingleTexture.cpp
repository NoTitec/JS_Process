#include "stdafx.h"
#include "SingleTexture.h"
#include "Device.h"

CSingleTexture::CSingleTexture() : m_pTexInfo(NULL)
{
}

CSingleTexture::~CSingleTexture()
{
	Release();
}

HRESULT CSingleTexture::Insert_Texture(const TCHAR * pFilePath, 
										const TCHAR * pStateKey, 
										const int & iCount)
{
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO));

	// D3DXGetImageInfoFromFile : �̹��� ������ ������� ���� ������ �о����
	
	if (FAILED(D3DXGetImageInfoFromFile(pFilePath, &(m_pTexInfo->tImgInfo))))
	{
		Safe_Delete(m_pTexInfo);
		AfxMessageBox(pFilePath);
		return E_FAIL;
	}

	// D3DPOOL_DEFAULT	   : ���� ������ �޸�, ���� �׷��� �޸𸮸� �ǹ�
	// D3DPOOL_MANAGED	   : ���� �׷��� �޸𸮿� ���������� �̸� RAM�� ���
	// D3DPOOL_SYSTEMMEM  : RAM�� ����
	// D3DPOOL_SCRATCH	   : RAM�� ���������� ��ġ�� ���� ���� �Ұ�

	// D3DXCreateTextureFromFileEx : �ؽ�ó �İ�ü ����
	if (FAILED(D3DXCreateTextureFromFileEx(CDevice::Get_Instance()->Get_Device(),
											pFilePath,
											m_pTexInfo->tImgInfo.Width,
											m_pTexInfo->tImgInfo.Height,
											m_pTexInfo->tImgInfo.MipLevels,
											0,	// USAGE(���� ���) : D3DUSAGE_RENDERTARGET
											m_pTexInfo->tImgInfo.Format,
											D3DPOOL_MANAGED,
											D3DX_DEFAULT,
											D3DX_DEFAULT,
											0, nullptr, nullptr,
											&(m_pTexInfo->pTexture))))
	{
		Safe_Delete(m_pTexInfo);
		AfxMessageBox(L"Single Texture Failed");
		return E_FAIL;
	}

	return S_OK;
}

void CSingleTexture::Release()
{
	Safe_Release(m_pTexInfo->pTexture);
	Safe_Delete(m_pTexInfo);
}
