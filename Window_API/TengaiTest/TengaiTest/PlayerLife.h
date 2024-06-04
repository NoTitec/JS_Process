#pragma once
#include "UI.h"
class CPlayerLife :
    public CUI
{
public:
    CPlayerLife();
    virtual ~CPlayerLife();

public:


    // CUI��(��) ���� ��ӵ�
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;

private:
    int m_iPlayerLifeCount;
};

