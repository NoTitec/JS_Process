#pragma once
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public: 
	// 기본 프레임 워크에 사용되는 함수
	virtual void	Initialize() PURE;
	virtual int		Update() PURE;
	virtual void	Late_Update() PURE;
	virtual void	Render(HDC _hdc) PURE;
	virtual void	Release() PURE;

public:
	// 방향 Update
	virtual void	Update_Dir() PURE;
	// m_vDir(방향기반) 포신 좌표 Update (각도를 기반으로 Posin을 업데이트 하고자하면 오버라이딩.)
	virtual void	Update_Posin(); 
	virtual void	Render_Posin(HDC hDC);

protected:
	// 그리기를 위한 Rect Update
	void			Update_Rect();

public:
	// Get
	RECT	Get_Rect() { return m_tRect; }
	INFO	Get_Info() { return m_tInfo; }

	Vec2	Get_Dir() { return m_vDir; }
	Vec2	Get_Posin() { return m_vPosin; }
	float	Get_Speed() { return m_fSpeed; }

	float	Get_Distance() { return m_fDistance; }
	float	Get_Degree() { return m_fDegree; }
	bool	IsDead() { return m_bDead; }
	

	// Set
	void	Set_Rect(RECT _rt) { m_tRect = _rt; }
	void	Set_Info(INFO _info) { m_tInfo = _info; }

	void	Set_Dir(Vec2 _dir) { m_vDir = _dir; }
	void	Set_Posin(Vec2 _posin) { m_vPosin = _posin; }
	void	Set_Speed(float _speed) { m_fSpeed = _speed; }

	void	Set_Distance(float _distance) { m_fDistance = _distance; }
	void	Set_Degree(float _degree) { m_fDegree = _degree; }
	void	Set_Dead() { m_bDead = true; }

	void	Set_Pos(float _x, float _y) { m_tInfo.fX = _x; m_tInfo.fY = _y; }

protected:
	INFO m_tInfo;
	RECT m_tRect;

	Vec2		m_vDir;		// 방향
	Vec2		m_vPosin;	// 포신 좌표
	float		m_fDistance;// 객체와 포신 사이의 거리
	float		m_fSpeed;	// 속도
	float		m_fDegree;	// 각도

	bool		m_bDead; 
};

