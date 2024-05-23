#include "stdafx.h"
#include "Scene.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "LineMgr.h"


CScene::CScene()
{
}

CScene::~CScene()
{
}

//void CScene::RemoveObjects()//objmgr·Î ÀÌµ¿
//{
//    auto pObjMgr = CObjMgr::Get_Instance();
//    for (auto& i : *pObjMgr->Get_List(OBJ_MONSTER))
//    {
//        Safe_Delete(i);
//    }
//    pObjMgr->Get_List(OBJ_MONSTER)->clear();
//    for (auto& i : *pObjMgr->Get_List(OBJ_P_BULLET))
//    {
//        Safe_Delete(i);
//    }
//    pObjMgr->Get_List(OBJ_P_BULLET)->clear();
//    for (auto& i : *pObjMgr->Get_List(OBJ_E_BULLET))
//    {
//        Safe_Delete(i);
//    }
//    pObjMgr->Get_List(OBJ_E_BULLET)->clear();
//    for (auto& i : *pObjMgr->Get_List(OBJ_ITEM))
//    {
//        Safe_Delete(i);
//    }
//    pObjMgr->Get_List(OBJ_ITEM)->clear();
//}










