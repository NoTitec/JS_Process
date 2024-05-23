#pragma once
#include "Obj.h"
class CKSHPlayer :
    public CObj
{
public:
    CKSHPlayer();
    virtual ~CKSHPlayer();


public:
    // CObj��(��) ���� ��ӵ�
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;

    void Key_Input();
    void		Jump();
    void		Offset();
private:
    //���� �� ��ġ
    POINT m_tBarrel;
    bool				m_bJump;
    float				m_fPower;
    float				m_fTime;
};

