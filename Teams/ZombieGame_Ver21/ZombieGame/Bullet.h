#pragma once

#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
	//////////////////////////////////유안 추가
	void PlayerPos_Update(Vec2 _vPlayerPos) { m_vPlayerPos = _vPlayerPos; }
	void PlayerDir_Update(Vec2 _vPlayerDir) { m_vPlayerDir = _vPlayerDir; }
public:
	void BulletType1();
	void BulletType2();
	void BulletType3();
	void SetZombieList(list<CObj*>* _pZombieList) 
	{ 
		m_pZombieList = _pZombieList; 
	}
public:
	void Check_WallCollide();
	void Check_NornalCollide();
	void Check_WallCollidePlayer();
	bool Check_Speed();


public:
	// get

	// set

private:
	// 멤버 변수
	int m_iTime;
	int iCheckTime;
	// PlayerPos;///////////////////////////////////////////유안 ㅊ추가
	Vec2 m_vPlayerPos;
	Vec2 m_vPlayerDir;

	Vec2 m_vTempPlayerPos;
	Vec2 m_vTempDir;

	float m_fVecRendomX;
	float m_fVecRendomY;
	list<CObj*>* m_pZombieList;

	bool m_bCheckSpeed;
	bool m_bCollision;
	bool m_Check_Size;
};

