#pragma once
#include "KJW_Monster.h"
class CKJW_FlyingMonster :
    public CKJW_Monster
{
public:
    CKJW_FlyingMonster();
    ~CKJW_FlyingMonster();

    // CKJW_Monster을(를) 통해 상속됨
    void OnHit(CObj* _pObj) override;
    void Initialize() override;
    int Update() override;
    void Update_Position() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
};

