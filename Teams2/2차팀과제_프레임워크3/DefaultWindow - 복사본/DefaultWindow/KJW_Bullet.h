#pragma once
#include "KJW_Obj.h"
class CKJW_Bullet :
    public CKJW_Obj
{
public:
    CKJW_Bullet();
    ~CKJW_Bullet();
    enum STATE { LAUNCH, DEAD,  ST_END };

    // CKJW_Obj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Update_Position() override;
    void Late_Update() override;
    void Change_Motion() override;
    void Render(HDC hDC) override;
    void Release() override;
    void OnHit(CObj* _pObj) override;
    void OnMotionEnd() override;

private:
    float m_fT;

    Point2F         m_tDeadPos;
};

