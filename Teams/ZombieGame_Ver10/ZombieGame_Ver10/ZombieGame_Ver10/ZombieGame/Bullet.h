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
	//////////////////////////////////���� �߰�
	void PlayerPos_Update(Vec2 _vPlayerPos) { m_vPlayerPos = _vPlayerPos; }
	void PlayerDir_Update(Vec2 _vPlayerDir) { m_vPlayerDir = _vPlayerDir; }
public:
	void BulletType1(int _iType);
	void BulletType2(int _iType);
	void BulletType3(int _iType);
	void SetZombieList(list<CObj*>* _pZombieList) 
	{ 
		m_pZombieList = _pZombieList; 
	}
public:
	// get

	// set

private:
	// ��� ����
	int iTime;
	int iCheckTime;
	// PlayerPos;///////////////////////////////////////////���� ���߰�
	Vec2 m_vPlayerPos;
	Vec2 m_vPlayerDir;

	list<CObj*>* m_pZombieList;
};

