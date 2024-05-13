#pragma once
class CUI
{
public:
	CUI() {}
	virtual ~CUI() {}
public:
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render()		PURE;
	virtual void	Release()		PURE;
public:
	Vec2 Get_Pos() { return m_vPos; }

	void Set_Pos(Vec2 _vPos) { m_vPos = _vPos; }
private:
	Vec2 m_vPos;
};

