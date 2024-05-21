#pragma once
#include "Obj.h"
class CKSHPlayer :
    public CObj
{
public:
    CKSHPlayer();
    virtual ~CKSHPlayer();
public:

    // CObj을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void		Key_Input();
    //void		Jump();
    //template<typename T>
    //CObj* Create_Bullet();
    //CObj* Create_Shield(float _Angle);
private:
    //포신 끝 위치
    POINT m_tBarrel;
    bool				m_bJump;
    float				m_fPower;
    float				m_fTime;
};

