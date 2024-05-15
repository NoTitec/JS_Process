#pragma once

#include "Obj.h"
class CObj;
class CBulletItem : public CObj
{
public:
	CBulletItem();
	virtual ~CBulletItem();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
public:
	void Set_Bullet_Item_Type(BULLET_TYPE _eBulletType) { m_iType = _eBulletType; }
	void Set_Target(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	BULLET_TYPE Get_Bullet_Item_Type() { return (BULLET_TYPE)m_iType; }
private:
	CObj* m_pPlayer;
	DWORD m_dwSurviveTime;
};

