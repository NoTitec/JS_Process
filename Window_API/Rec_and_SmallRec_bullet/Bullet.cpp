#include "Bullet.h"
#include "Define.h"
#include <cmath> 
CBullet::CBullet() : dx(0),dy(0),isDiagonal(false)
{
    
}

CBullet::~CBullet()
{
    Release();
}

void CBullet::Initialize()
{
    m_tInfo.fCX = 20.f;
    m_tInfo.fCY = 20.f;
    m_fSpeed = 5.f;
}
//생성후 밖에서 dx&&dy!=0 이면 대각선이며 이경우 속도 맞추기위해 m_fSpeed/=sqrt(2); 하고 push
int CBullet::Update()
{
    //dx,dy 에따라 총알 방향별 이동중심위치 설정

    //왼쪽오른쪽
    switch (dx)
    {
    case 1:
        m_tInfo.fX -= m_fSpeed;
        break;
    case 2:
        m_tInfo.fX += m_fSpeed;
        break;
    }
    //위아래
    switch (dy)
    {
    case 1:
        m_tInfo.fY -= m_fSpeed;
        break;
    case 2:
        m_tInfo.fY += m_fSpeed;
        break;
    }
    
    __super::Update_Rect();
    if (m_tRect.left < 100|| m_tRect.right > SMALLWINCX|| m_tRect.top < 100|| m_tRect.bottom > SMALLWINCY)
        return 1;
    return 0;
}

void CBullet::Render(HDC hDC)
{
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::Set_Direction(int _dx, int _dy)
{
    //생성후 밖에서 dx&&dy!=0 이면 대각선이며 이경우 속도 맞추기위해 m_fSpeed/=sqrt(2); 하고 push
    dx = _dx;
    dy = _dy;
    if (_dx != 0 && _dy != 0)
    {
        isDiagonal = true;
    }
}

bool CBullet::Get_Diagonal()
{
    return isDiagonal;
}
