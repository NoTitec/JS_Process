#pragma once
#include "Obj.h"
class CMikoPet : public CObj
{
public:
	enum MIKOPETLEVEL{LEVEL_ONE,LEVEL_TWO,LEVEL_END};

public:
	CMikoPet();
	virtual ~CMikoPet();

public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;
	virtual void OnHit(CObj* _pObj) override;
	void Release() override;
public:
	void Set_Level(MIKOPETLEVEL level)
	{
		m_eLevel = level;
	}
public:
	template<typename T>
	void Create_one_Bullet(DIRECTION e_Dir);
	template<typename T>
	void Create_three_Bullet();
private:
	DWORD				m_dwBulletGenarateSpeed;
	DWORD				m_dwBulletGenarateTime;
	MIKOPETLEVEL		m_eLevel;
	//void		Create_Basic_Bullet();
};
