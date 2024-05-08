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
	//x�� ���� 0: ���� 1:���� 2:������
	int dx;
	//y�� ���� 0: ���� 1:�� 2:�Ʒ�
	int dy;
	//�밢�� ���� �ӵ� ���� flag
	bool isDiagonal;
};

