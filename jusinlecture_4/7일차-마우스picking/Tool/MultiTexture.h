#pragma once

#include "Texture.h"
#include "Include.h"

class CMultiTexture : public CTexture
{
public:
	CMultiTexture();
	virtual ~CMultiTexture();

public:
	virtual const TEXINFO * Get_Texture(const TCHAR * pStateKey = L"", const int & iCount = 0);
	virtual HRESULT Insert_Texture(const TCHAR * pFilePath, const TCHAR * pStateKey = L"", const int & iCount = 0) override;
	virtual void Release() override;

private:
	map<wstring, vector<TEXINFO*>>		m_MapMultiTex;

};

