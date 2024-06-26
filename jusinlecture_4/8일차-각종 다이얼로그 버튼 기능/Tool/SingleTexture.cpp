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

	// D3DXGetImageInfoFromFile : 이미지 파일을 기반으로 파일 정보를 읽어들임
	
	if (FAILED(D3DXGetImageInfoFromFile(pFilePath, &(m_pTexInfo->tImgInfo))))
	{
		Safe_Delete(m_pTexInfo);
		AfxMessageBox(pFilePath);
		return E_FAIL;
	}

	// D3DPOOL_DEFAULT	   : 가장 적합한 메모리, 보통 그래픽 메모리를 의미
	// D3DPOOL_MANAGED	   : 보통 그래픽 메모리에 저장하지만 이를 RAM에 백업
	// D3DPOOL_SYSTEMMEM  : RAM에 저장
	// D3DPOOL_SCRATCH	   : RAM에 저장하지만 장치를 통해 접근 불가

	// D3DXCreateTextureFromFileEx : 텍스처 컴객체 생성
	if (FAILED(D3DXCreateTextureFromFileEx(CDevice::Get_Instance()->Get_Device(),
											pFilePath,
											m_pTexInfo->tImgInfo.Width,
											m_pTexInfo->tImgInfo.Height,
											m_pTexInfo->tImgInfo.MipLevels,
											0,	// USAGE(생성 방식) : D3DUSAGE_RENDERTARGET
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
