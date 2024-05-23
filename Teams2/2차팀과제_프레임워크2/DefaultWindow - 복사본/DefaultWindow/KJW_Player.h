#pragma once
#include "KJW_Obj.h"
class CKJW_Player :
    public CKJW_Obj
{
    // CKJW_Obj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Key_Input();
    void Update_Position();
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Offset();
private:
    bool m_bJump;
    float m_fJumpPower;
    float m_fJumpTime;

    float m_fXSpd;
    float m_fYSpd;

    float m_fFootHeight;
};

