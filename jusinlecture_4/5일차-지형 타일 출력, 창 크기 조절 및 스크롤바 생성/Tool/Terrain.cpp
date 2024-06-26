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
	
		CDevice::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture,  // �ؽ�ó �İ�ü
			nullptr, // ����� �̹����� RECT ������ �ּҰ�(null�ΰ�� 0, 0���� ����ϰڴٴ� �ǹ�)
			&D3DXVECTOR3(fCenterX, fCenterY, 0.f), // ����� �̹����� �߽� ��ġ�� ���� vec3 �ּҰ�(null�ΰ�� 0,0�� �ؽ�ó�� �߽� ��ġ)
			nullptr, // ����� ��ġ vec3 �ּҰ�(null�� ��� ��ũ�� �� 0,0 ��ǥ�� ���)
			D3DCOLOR_ARGB(255, 255, 255, 255));	// ����� ���� �̹����� ���� ���� ��, 0xffffffff�� �Ѱ��ָ� ���� ���� ����

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
