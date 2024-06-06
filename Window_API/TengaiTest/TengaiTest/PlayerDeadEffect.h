#pragma once
#include "Obj.h"
class CPlayerDeadEffect :
    public CObj
{
public:
    CPlayerDeadEffect();
    virtual ~CPlayerDeadEffect();

public:


    // CObj��(��) ���� ��ӵ�
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;

    void OnHit(CObj* _pObj) override;

};

