#include "stdafx.h"
#include "Terrain.h"
#include "TextureMgr.h"
#include "Device.h"
#include "ToolView.h"

CTerrain::CTerrain()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTerrain::~CTerrain()
{
	Release();
}

void CTerrain::Initialize()
{
	if (FAILED(CTextureMgr::Get_Instance()->Insert_Texture(L"../Texture/Stage/Terrain/Tile/Tile%d.png", TEX_MULTI, L"Terrain", L"Tile", 36)))
	{
		AfxMessageBox(L"Tile img insert Failed");
		return;
	}

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			TILE*	pTile = new TILE;

			float fX = (TILECX * j) + (i % 2) * (TILECX / 2.f);
			float fY = (TILECY / 2.f) * i;

			pTile->vPos = {fX, fY, 0.f};
			pTile->vSize = { TILECX, TILECY };
			pTile->byOption = 0;
			pTile->byDrawID = 3;

			m_vecTile.push_back(pTile);
		}
	}
}

void CTerrain::Update()
{
}

void CTerrain::Render()
{
	D3DXMATRIX	matWorld, matScale, matTrans;

	TCHAR		szBuf[MIN_STR] = L"";
	int			iIndex(0);

	for (auto& pTile : m_vecTile)
	{

		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
		D3DXMatrixTranslation(&matTrans,
			pTile->vPos.x - m_pMainView->GetScrollPos(0), 
			pTile->vPos.y - m_pMainView->GetScrollPos(1),
			pTile->vPos.z);

		matWorld = matScale * matTrans;

		const TEXINFO*		pTexInfo = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", pTile->byDrawID);
		
		float	fCenterX = pTexInfo->tImgInfo.Width / 2.f;
		float	fCenterY = pTexInfo->tImgInfo.Height / 2.f;

		CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	
		CDevice::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture,  // 텍스처 컴객체
			nullptr, // 출력할 이미지의 RECT 영역에 주소값(null인경우 0, 0부터 출력하겠다는 의미)
			&D3DXVECTOR3(fCenterX, fCenterY, 0.f), // 출력할 이미지의 중심 위치에 대한 vec3 주소값(null인경우 0,0이 텍스처의 중심 위치)
			nullptr, // 출력할 위치 vec3 주소값(null인 경우 스크린 상 0,0 좌표에 출력)
			D3DCOLOR_ARGB(255, 255, 255, 255));	// 출력할 원본 이미지와 섞을 색상 값, 0xffffffff를 넘겨주면 원본 색상 유지

		swprintf_s(szBuf, L"%d", iIndex);
		CDevice::Get_Instance()->Get_Font()->DrawTextW(CDevice::Get_Instance()->Get_Sprite(), szBuf, lstrlen(szBuf), nullptr, 0, D3DCOLOR_ARGB(255, 255, 255, 255));
				
		++iIndex;
	}
}

void CTerrain::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), CDeleteObj());
	m_vecTile.clear();
}
