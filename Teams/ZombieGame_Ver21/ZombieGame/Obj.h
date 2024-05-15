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
	// 방향 Update (각도기반, 좌표기반 각자 오버라이딩하여 사용)
	virtual void	Dir_Update();
	// Posin Update (각도기반, 좌표기반 각자 오버라이딩하여 사용)
	virtual void	Posin_Update(); 
	virtual void	Posin_Render(HDC hDC);

protected:
	// 그리기를 위한 Rect Update
	void			Update_Rect();

public:
	void			PlusHP() { m_iHP += 1; }
	void			MinusHP() { m_iHP -= 1; }
public:
	// Get
	RECT	Get_Rect() { return m_tRect; }
	INFO	Get_Info() { return m_tInfo; }

	// 반환타입이 Vec2 type임. (주의)
	Vec2	Get_Pos() { return Vec2(m_tInfo.fX, m_tInfo.fY); }
	Vec2	Get_Scale() { return Vec2(m_tInfo.fCX, m_tInfo.fCY); }

	Vec2	Get_Dir() { return m_vDir; }
	Vec2	Get_Posin() { return m_vPosin; }
	float	Get_Speed() { return m_fSpeed; }

	float	Get_Distance() { return m_fDistance; }
	float	Get_Degree() { return m_fDegree; }
	int		Get_Type() { return m_iType; }
	bool	IsDead() { return m_bDead; }
	int		Get_HP() { return m_iHP; }

	// Set
	void	Set_Rect(RECT _rt) { m_tRect = _rt; }
	void	Set_Info(INFO _info) { m_tInfo = _info; }

	void	Set_Dir(Vec2 _dir) { m_vDir = _dir; }
	void	Set_Posin(Vec2 _posin) { m_vPosin = _posin; }
	void	Set_Speed(float _speed) { m_fSpeed = _speed; }

	void	Set_Distance(float _distance) { m_fDistance = _distance; }
	void	Set_Degree(float _degree) { m_fDegree = _degree; }
	void	Set_Type(int _type) { m_iType = _type; }
	void	Set_Dead() { m_bDead = true; }
	void	Set_RandDir() { m_bRandDir = true; }

	void	Set_Pos(float _x, float _y) { m_tInfo.fX = _x; m_tInfo.fY = _y; }				// float 자료형을 매개 변수로 넣어서 SetPos
	void	Set_Pos(Vec2 _vPos) { m_tInfo.fX = _vPos.fX; m_tInfo.fY = _vPos.fY; }			// Vec2 자료형을 매개 변수로 넣어서 SetPos

	void	Set_Scale(float _x, float _y) { m_tInfo.fCX = _x; m_tInfo.fCY = _y; }			// float 자료형을 매개 변수로 넣어서 SetPos
	void	Set_Scale(Vec2 _vScale) { m_tInfo.fCX = _vScale.fX; m_tInfo.fCY = _vScale.fY; } // Vec2 자료형을 매개 변수로 넣어서 SetPos
	void	Set_HP(int _ihp) { m_iHP = _ihp; }
protected:
	INFO m_tInfo;
	RECT m_tRect;

	Vec2		m_vDir;		// 방향
	Vec2		m_vPosin;	// 포신 좌표
	float		m_fDistance;// 객체와 포신 사이의 거리
	float		m_fSpeed;	// 속도
	float		m_fDegree;	// 각도

	int			m_iType;	// Player, Bullet, Monster 모두 사용가능한 Type변수, 별도로 다른거 사용해도됌.
	bool		m_bDead; 
	bool		m_bRandDir;
	int			m_iHP;		// 체력 >>> 1회 충돌 시마다 HP를 - 1 >> hp가 0이면 사망. 
};

