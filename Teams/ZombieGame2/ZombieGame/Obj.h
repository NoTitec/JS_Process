#pragma once
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render(HDC _hdc) PURE;
	virtual void Release() PURE;

public:
	void Set_Dead() { m_bDead = true; }
	void Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }
	void Set_Normal(float _fNormalX, float _fNormalY) { m_tInfo.fNormalX = _fNormalX; m_tInfo.fNormalY = _fNormalY; }
	bool Get_Dead() { return m_bDead; }
	INFO Get_Info() { return m_tInfo; }

protected:
	void Update_Rect();
protected:
	INFO m_tInfo;
	RECT m_tRect;
	
	float m_fSpeed;
	bool m_bDead;
};

