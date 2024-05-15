#pragma once
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public: 
	// �⺻ ������ ��ũ�� ���Ǵ� �Լ�
	virtual void	Initialize() PURE;
	virtual int		Update() PURE;
	virtual void	Late_Update() PURE;
	virtual void	Render(HDC _hdc) PURE;
	virtual void	Release() PURE;

public:
	// ���� Update (�������, ��ǥ��� ���� �������̵��Ͽ� ���)
	virtual void	Dir_Update();
	// Posin Update (�������, ��ǥ��� ���� �������̵��Ͽ� ���)
	virtual void	Posin_Update(); 
	virtual void	Posin_Render(HDC hDC);

protected:
	// �׸��⸦ ���� Rect Update
	void			Update_Rect();

public:
	void			PlusHP() { m_iHP += 1; }
	void			MinusHP() { m_iHP -= 1; }
public:
	// Get
	RECT	Get_Rect() { return m_tRect; }
	INFO	Get_Info() { return m_tInfo; }

	// ��ȯŸ���� Vec2 type��. (����)
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

	void	Set_Pos(float _x, float _y) { m_tInfo.fX = _x; m_tInfo.fY = _y; }				// float �ڷ����� �Ű� ������ �־ SetPos
	void	Set_Pos(Vec2 _vPos) { m_tInfo.fX = _vPos.fX; m_tInfo.fY = _vPos.fY; }			// Vec2 �ڷ����� �Ű� ������ �־ SetPos

	void	Set_Scale(float _x, float _y) { m_tInfo.fCX = _x; m_tInfo.fCY = _y; }			// float �ڷ����� �Ű� ������ �־ SetPos
	void	Set_Scale(Vec2 _vScale) { m_tInfo.fCX = _vScale.fX; m_tInfo.fCY = _vScale.fY; } // Vec2 �ڷ����� �Ű� ������ �־ SetPos
	void	Set_HP(int _ihp) { m_iHP = _ihp; }
protected:
	INFO m_tInfo;
	RECT m_tRect;

	Vec2		m_vDir;		// ����
	Vec2		m_vPosin;	// ���� ��ǥ
	float		m_fDistance;// ��ü�� ���� ������ �Ÿ�
	float		m_fSpeed;	// �ӵ�
	float		m_fDegree;	// ����

	int			m_iType;	// Player, Bullet, Monster ��� ��밡���� Type����, ������ �ٸ��� ����ص���.
	bool		m_bDead; 
	bool		m_bRandDir;
	int			m_iHP;		// ü�� >>> 1ȸ �浹 �ø��� HP�� - 1 >> hp�� 0�̸� ���. 
};

