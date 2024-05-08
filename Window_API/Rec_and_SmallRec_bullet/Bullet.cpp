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
//������ �ۿ��� dx&&dy!=0 �̸� �밢���̸� �̰�� �ӵ� ���߱����� m_fSpeed/=sqrt(2); �ϰ� push
int CBullet::Update()
{
    //dx,dy ������ �Ѿ� ���⺰ �̵��߽���ġ ����

    //���ʿ�����
    switch (dx)
    {
    case 1:
        m_tInfo.fX -= m_fSpeed;
        break;
    case 2:
        m_tInfo.fX += m_fSpeed;
        break;
    }
    //���Ʒ�
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
    //������ �ۿ��� dx&&dy!=0 �̸� �밢���̸� �̰�� �ӵ� ���߱����� m_fSpeed/=sqrt(2); �ϰ� push
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
