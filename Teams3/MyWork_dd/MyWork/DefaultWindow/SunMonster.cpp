#include "stdafx.h"
#include "SunMonster.h"
#include "Define.h"
#include "random"



CSunMonster::CSunMonster()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(-1.0, 1.0);
    float randomValuex = dis(gen);
    float randomValuey = dis(gen);
    m_tInfo.vDir.x = randomValuex;
    m_tInfo.vDir.y = randomValuey;
}

CSunMonster::~CSunMonster()
{
    Release();
}

void CSunMonster::Initialize()
{
    m_tInfo.vPos = { 100.f, 100.f, 0.f };
    m_fSpeed = 2.f;
}

int CSunMonster::Update()
{
	/*m_tInfo.vDir = m_pPlayer->Get_PlayerWorldCenterPos() - m_tInfo.vPos;

	float	fLength = sqrt(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;*/

    if (iLifeCount == 0)
    {
        return OBJ_DEAD;
    }
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	return OBJ_NOEVENT;
}

void CSunMonster::Late_Update()
{//좌충돌 dirx 를 -방향으로
    if (m_tInfo.vPos.x < 5) {
        --iLifeCount;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(0.0, 1.0);
        float randomValuex = dis(gen);
        m_tInfo.vDir.x = randomValuex;
    }
    // 우충돌
    if (m_tInfo.vPos.x > 795) {
        --iLifeCount;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(-1.0, 0.0);
        float randomValuex = dis(gen);
        m_tInfo.vDir.x = randomValuex;
    }
    // 상충돌
    if (m_tInfo.vPos.y  < 5) {
        --iLifeCount;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(0.0, 1.0);
        
        float randomValuey = dis(gen);
        m_tInfo.vDir.y = randomValuey;
    }
    // 하충돌
    if (m_tInfo.vPos.y  > 595) {
        --iLifeCount;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(-1.0, 0.0);
        
        float randomValuey = dis(gen);
        m_tInfo.vDir.y = randomValuey;
    }
}

void CSunMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 10.f),
		int(m_tInfo.vPos.y - 10.f),
		int(m_tInfo.vPos.x + 10.f),
		int(m_tInfo.vPos.y + 10.f));
}

void CSunMonster::Release()
{
}
