#pragma once
#include "KJW_Monster.h"

class CKJW_BossMonster :
    public CKJW_Monster
{
    enum STATE { IDLE, JUMP, DEAD, ST_END };
    enum PATTERN { RUSH, SUMMON, PT_END, NONE, };
public:
    CKJW_BossMonster();
    ~CKJW_BossMonster();
    // CKJW_Monster을(를) 통해 상속됨
    void OnHit(CObj* _pObj) override;
    void Initialize() override;
    int Update() override;
    void Update_Pattern();
    void Update_Position() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Change_Motion() override;

    void Change_State();
private:
    float m_fPatternDelay;
    float m_fPatternTime;
    PATTERN m_eCurPattern;

};

