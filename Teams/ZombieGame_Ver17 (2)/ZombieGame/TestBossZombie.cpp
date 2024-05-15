#include "stdafx.h"
#include "BossMonster.h"
#include "CAbstractFactory.h"
#include "CBullet.h"
#include "Missile.h"
#include "ReflectBullet.h"
#include "BombBullet.h"
#include "SceneMgr.h"

CBossMonster::CBossMonster() : m_fSaveTime(0), m_fPatternCoolTime(3000), m_ePattern(CIRCLE_BULLET), m_iBulletCount(0), m_fBulletAngle(0)
{

}

CBossMonster::~CBossMonster()
{

}

void CBossMonster::Initialize()
{
   m_tInfo = { WINCX / 2.f, -100, 75.f, 75.f };
   m_fCollisionTime = GetTickCount64();
   m_fSpeed = 1.f;
   m_tUnitVec = { 0,1 };
   m_bIsSafe = true;
   m_eType = OBJ_MONSTER;
   m_ePattern = PATTERN(rand() % END_PATTERN);
   m_iHp = 1;
}

int CBossMonster::Update()
{
   if (m_bDead)
      return DEAD;

   Init_Move();
   CObj::Move();
   CObj::Update_Rect();

   return LIVE;
}

void CBossMonster::Late_Update()
{

}

void CBossMonster::Render(HDC hDC)
{
   Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBossMonster::Release()
{
}

void CBossMonster::Hit(CObj* _pOtherObj)
{
   if (!m_bIsSafe)
   {
      --m_iHp;
      if (0 >= m_iHp)
      {
         m_bDead = true;
         Add_UI_KillCount();
         Add_UI_MonsterCount();
      }
   }
}

void CBossMonster::Pattern()
{
   ULONGLONG tmp = g_ullCurTick;
   if (tmp - m_fSaveTime > m_fPatternCoolTime)
   {
      m_fSaveTime = tmp;

      switch (DIRECTION_BULLET)
      {
      case CBossMonster::DIRECTION_BULLET:
         m_ePattern = (PATTERN)Pattern_1();
         break;
      case CBossMonster::TRACE_BULLET:
         m_ePattern = (PATTERN)Pattern_2();
         break;
      case CBossMonster::REFLECT_BULLET:
         m_ePattern = (PATTERN)Pattern_3();
         break;
      case CBossMonster::CIRCLE_BULLET:
         m_ePattern = (PATTERN)Pattern_4();
         break;
      case CBossMonster::BOMBING_BULLET:
         m_ePattern = (PATTERN)Pattern_5();
         break;
      }
   }
}

int CBossMonster::Pattern_1()
{
   float fAngle(0);
   if (0 == m_iBulletCount)
      fAngle = 0;
   else
      fAngle = 22.5f;
   ++m_iBulletCount;
   UNITVEC tTempUnit{ 0,0 };
   for (int j = 0; j < 8; ++j)
   {
      fAngle = fAngle + 45;
      tTempUnit.fX = cos(fAngle * PI / 180);
      tTempUnit.fY = sin(fAngle * PI / 180);
      CObj* pObj = CBossMonster::Create_Bullet<CBullet>(8);
      pObj->Set_UnitVector(tTempUnit);

      CSceneMgr::Get_Instance() ->Get_CurScene()->Add_Obj(OBJ_MONSTER_BULLET, pObj);
      //m_pOtherList[OBJ_MONSTER_BULLET].push_back(pObj);   // 예전
   }

   if (2 == m_iBulletCount)
   {
      m_iBulletCount = 0;
      m_fPatternCoolTime = 3000;
      return (rand() % END_PATTERN);
   }
   else
   {
      m_fPatternCoolTime = 200;
      return DIRECTION_BULLET;
   }
}

int CBossMonster::Pattern_2()
{
   ++m_iBulletCount;
   CObj* pObj = CBossMonster::Create_Bullet<CMissile>(8.f);
   if (m_iBulletCount == rand() % 2)
      dynamic_cast<CMissile*>(pObj)->Set_Dot(-1);
   else
      dynamic_cast<CMissile*>(pObj)->Set_Dot(1);

   CSceneMgr::Get_Instance() ->Get_CurScene()->Add_Obj(OBJ_MONSTER_BULLET, pObj);
   //m_pOtherList[OBJ_MONSTER_BULLET].push_back(pObj); 예전
   
   if (3 == m_iBulletCount)
   {
      m_iBulletCount = 0;
      m_fPatternCoolTime = 3000;
      return (rand() % END_PATTERN);
   }
   else
   {
      m_fPatternCoolTime = 200;
      return TRACE_BULLET;
   }
}

int CBossMonster::Pattern_3()
{
   for (int i = 0; i < 4; ++i)
   {
      CObj* pObj = CBossMonster::Create_Bullet<CReflectBullet>(8.f);
      dynamic_cast<CReflectBullet*>(pObj)->Set_StartPos(m_tInfo.fX, m_tInfo.fY);
      CSceneMgr::Get_Instance() ->Get_CurScene()->Add_Obj(OBJ_MONSTER_BULLET, pObj);
      //m_pOtherList[OBJ_MONSTER_BULLET].push_back(pObj); 예전
   }
   m_fPatternCoolTime = 3000;
   return (rand() % END_PATTERN);
}

int CBossMonster::Pattern_4()
{
   UNITVEC tTempVec{ 0,0 };

   float fX(90 * cos(m_fBulletAngle * PI / 180) + m_tInfo.fX);
   float fY(90 * sin(m_fBulletAngle * PI / 180) + m_tInfo.fY);

   CObj* pObj = CBossMonster::Create_Bullet<CBullet>(0.f);
   pObj->Set_Pos(fX, fY);

   m_pCircleBullet.push_back(pObj);

   ++m_iBulletCount;
   m_fBulletAngle = 10 * m_iBulletCount;

   CSceneMgr::Get_Instance() ->Get_CurScene()->Add_Obj(OBJ_MONSTER_BULLET, pObj);
   //m_pOtherList[OBJ_MONSTER_BULLET].push_back(pObj); 예전

   if (36 <= m_iBulletCount)
   {
      for (auto& iter : m_pCircleBullet)
      {
         INFO tInfo = CSceneMgr::Get_Instance() ->Get_CurScene()->Get_Player()->Get_Info();
         tTempVec = CAbstractFactory<float>::Calculate_Distance(tInfo.fX - m_tInfo.fX, tInfo.fY - m_tInfo.fY, tTempVec);
         iter->Set_UnitVector(tTempVec);
         iter->Set_Speed(6.f);
      }
      m_iBulletCount = 0;
      m_fBulletAngle = 0;
      m_fPatternCoolTime = 3000;
      m_pCircleBullet.clear();
      return (rand() % END_PATTERN);
   }
   else
   {
      m_fPatternCoolTime = 10;
      return CIRCLE_BULLET;
   }
}

int CBossMonster::Pattern_5()
{
   if (5 > m_iBulletCount )
   {
      ++m_iBulletCount;
      CObj* pObj = CBossMonster::Create_Bullet<CBombBullet>(1);
      dynamic_cast<CBombBullet*>(pObj)->Set_Info(6-m_iBulletCount, 50);
      dynamic_cast<CBombBullet*>(pObj)->Set_Angle(180.f + m_iBulletCount * 30);
      // CSceneMgr::Get_Instance() ->Get_CurScene()->Add_Obj(OBJ_MONSTER_BULLET, pObj); // 싱글톤
      //m_pOtherList[OBJ_MONSTER_BULLET].push_back(pObj); 예전

      m_fPatternCoolTime = 100;
      return BOMBING_BULLET;
   }
   else
   {
      m_iBulletCount = 0;
      m_fPatternCoolTime = 3000;
      return (rand() % END_PATTERN);
   }
}

void CBossMonster::Init_Move()
{
   if (m_tInfo.fY >= WINCY / 4)
   {
      m_bIsSafe = false;
      m_tUnitVec = { 0,0 };
      Pattern();
   }
}