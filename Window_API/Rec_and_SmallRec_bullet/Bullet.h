#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void Set_Direction(int _dx, int _dy);
	bool Get_Diagonal();
private:
	//x축 방향 0: 없음 1:왼쪽 2:오른쪽
	int dx;
	//y축 방향 0: 없음 1:위 2:아래
	int dy;
	//대각선 방향 속도 조절 flag
	bool isDiagonal;
};

