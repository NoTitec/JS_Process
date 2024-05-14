#include "FollowBullet.h"
#include "ObjMgr.h"

CFollowBullet::CFollowBullet()
{
}

CFollowBullet::~CFollowBullet()
{
    Release();
}

void CFollowBullet::Initialize()
{
    m_tInfo.fCX = 11.f;
    m_tInfo.fCY = 11.f;

    m_fSpeed = 10.f;

	//�����Ҷ����� ����Ʈ�� �ڱ�� ���� ������ ã��
	m_pTarget = CObjMgr::Get_Instance()->Get_Nearest_Object(OBJ_ZOMBIE, m_tInfo.fX, m_tInfo.fY);
	float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

	//���α���
	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	//���α���
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;
	//��������
	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);
	//���� ����
	fRadian = acos(fWidth / fDiagonal);

	m_fAngle = fRadian / PI * 180.f;
	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;
}

int CFollowBullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

	m_tInfo.fX += cos(m_fAngle / 180.f * PI) * m_fSpeed;
	m_tInfo.fY -= sin(m_fAngle / 180.f * PI) * m_fSpeed;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CFollowBullet::Late_Update()
{
    if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right ||
        100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
    {
        m_bDead = true;
    }
}

void CFollowBullet::Render(HDC hDC)
{
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CFollowBullet::Release()
{
}

RECT* CFollowBullet::Get_Rect_Pointer()
{
    return nullptr;
}
