#pragma once
#include "KJW_Monster.h"
class CKJW_WalkingMonster :
    public CKJW_Monster
{
public:
    CKJW_WalkingMonster();
    ~CKJW_WalkingMonster();
    // CKJW_Monster��(��) ���� ��ӵ�
    void OnHit(CObj* _pObj) override;
    void Initialize() override;
    int Update() override;
    void Update_Position() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
};

