#pragma once
#pragma once
#include "Obj.h"

class CBossHpBar;
class CBossZombie : public CObj
{
public:
	CBossZombie();
	virtual ~CBossZombie();
public:
	void Dir_Update() override;
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
public:
	// get
	Vec2 Get_Target_Pos() { return m_vTargetPos; }
	bool Get_Stuck() { return m_bStuck; }
	int Get_Full_Hp() { return m_iFullHp; }
	// set
	void Set_Target_Pos(Vec2 _vTargetPos) { m_vTargetPos; }
	void Set_Stuck(bool _bStuck) { m_bStuck = _bStuck; }

	// Player 좌표를 매 프레임마다 업데이트 중(MainGameScene 클래스의 lateUpdate)
	void TargetPos_Update(Vec2 _vTargetPos) { m_vTargetPos = _vTargetPos; }

	//패턴공격함수총괄
	void Pattern();
	//패턴들
	BOSSPATTERN Pattern1();
	//호출될때마다 랜덤 각도 방향으로 이동방향 변경
	void Random_Dir_Degree();
	void Set_BossBulletList(list<CObj*>* _pBulletList) { m_pBossBulletList = _pBulletList; }

	void Pos_Hp_Bar_Update();
private:
	// 플레이어좌표
	Vec2	m_vTargetPos;
	HBRUSH Brush;
	//플레이어와의 거리
	float   m_fdistance;
	//패턴 간격측정변수
	DWORD m_CollisionTime;
	//패턴 enum 변수
	BOSSPATTERN m_ePattern;
	//패턴 시간 진행 저장 변수
	ULONGLONG m_fSaveTime;
	//패턴 간격 시간(ms 단위)
	ULONGLONG m_fPatternCoolTime;
	//랜덤이동 시간측정변수
	DWORD m_dwMoveTime;
	//보스 총알 담을 리스트
	list<CObj*>* m_pBossBulletList;
	bool	m_bStuck;
	int	m_iFullHp;
	INFO m_tHpBarInfo;
	RECT m_tHpBarRect;

	CBossHpBar* m_pBossHpBar;
};

