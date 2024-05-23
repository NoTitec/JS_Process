#pragma once
#include "KJW_Obj.h"
class CKJW_Player :
    public CKJW_Obj
{
    enum STATE { BORN, IDLE, WALK, JUMP, LAND,RUN, PUSH, BUBBLE, DEAD, THROW, ST_END };
public:
    CKJW_Player();
    ~CKJW_Player();

    // CKJW_Obj을(를) 통해 상속됨
    void Initialize() override;

    int Update() override;
    virtual void KJW_Update_Rect();
    void Key_Input();
    void Update_Position();
    void Late_Update() override;
    void Change_Motion() override;

    void Render(HDC hDC) override;

    void Release() override;

    void OnHit(CObj* _pObj) override;

    void Offset();
    virtual void OnMotionEnd();

    void Shoot();
private:

    Point2F             m_tShootPoint;
    float               m_fShootDelay;
    float               m_fShootTime;
};

