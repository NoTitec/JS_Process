#pragma once
#include "Obj.h"
class CKSH_BossMonster : public CObj
{
	//������Ʈ�Լ�����
// �������Ӹ���
// 
//if(�帣�½ð�-����ð�>��Ÿ��)
//{
//    ����ð�=�帣�½ð�
//}
public:
	enum BOSSSTATE{IDLE,ATTACK,BOSS_ST_END};
	enum PATTERN {ONEPATTERN,TWOPATTERN,BOSS_PATTERN_END};
public:
	CKSH_BossMonster();
	virtual ~CKSH_BossMonster();
public:
	// CObj��(��) ���� ��ӵ�
	void OnHit(CObj* _pObj) override;
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	
	//������Ʈ���� ����ϴ� staypattern �Լ�
	void Change_State();
	void Pattern1();
	void Pattern2();

	template<typename T>
	CObj* Create_Bullet();
private:
	
	//���� ������������
	float m_fSaveTime;
	//������Ÿ��
	float m_fCoolTime;
	BOSSSTATE boss_state;
};

template<typename T>
inline CObj* CKSH_BossMonster::Create_Bullet()
{
	int	iScrollX = (int)SCROLL.Get_ScrollX();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY);
	pBullet->Set_ID(OBJ_MONSTER_BULLET);
	return pBullet;
}
