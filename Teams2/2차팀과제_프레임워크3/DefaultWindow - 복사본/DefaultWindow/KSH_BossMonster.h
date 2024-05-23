#pragma once
#include "Obj.h"
class CKSH_BossMonster : public CObj
{
	//업데이트함수에서
// 매프레임마다
// 
//if(흐르는시간-저장시간>쿨타임)
//{
//    저장시간=흐르는시간
//}
public:
	enum BOSSSTATE{IDLE,ATTACK,BOSS_ST_END};
	enum PATTERN {ONEPATTERN,TWOPATTERN,BOSS_PATTERN_END};
public:
	CKSH_BossMonster();
	virtual ~CKSH_BossMonster();
public:
	// CObj을(를) 통해 상속됨
	void OnHit(CObj* _pObj) override;
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	
	//업데이트에서 사용하는 staypattern 함수
	void Change_State();
	void Pattern1();
	void Pattern2();

	template<typename T>
	CObj* Create_Bullet();
private:
	
	//보통 끝났을때설정
	float m_fSaveTime;
	//패턴쿨타임
	float m_fCoolTime;
	BOSSSTATE boss_state;
};

template<typename T>
inline CObj* CKSH_BossMonster::Create_Bullet()
{
	int	iScrollX = (int)SCROLL.Get_ScrollX();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY);
	pBullet->Set_ID(OBJ_MONSTER_BULLET);
	return pBullet;
}
