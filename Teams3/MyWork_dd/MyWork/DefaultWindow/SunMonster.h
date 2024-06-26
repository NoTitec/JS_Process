#pragma once
#include "Obj.h"

class CSunMonster : public CObj
{
public:
    void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
public:
    CSunMonster();
    virtual ~CSunMonster();
    // CObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
private:
    CObj* m_pPlayer;

    int iLifeCount=5;
};

