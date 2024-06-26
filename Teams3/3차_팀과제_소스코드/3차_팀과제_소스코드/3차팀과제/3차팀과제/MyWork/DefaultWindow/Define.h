#pragma once


// ==========================================================================
// 싱글톤
#define DECLARE_SINGLE(className)								\
	static className* m_pInstance;								\
private:														\
	className();												\
	virtual ~className();										\
public:															\
	static className* Get_Instance()							\
	{															\
		if (nullptr != m_pInstance) return m_pInstance;			\
		else return m_pInstance = new className;				\
	}															\
	static void Destroy_Instance()								\
	{															\
		if (m_pInstance)										\
		{														\
			delete m_pInstance;									\
			m_pInstance = nullptr;								\
		}														\
	}															\
																\
																\
			
// ==========================================================================


#define			GET_SINGLE(classname)		classname::Get_Instance()


#define			GAME		GET_SINGLE(CMainGame)
#define			KEYMGR		GET_SINGLE(CKeyMgr)
#define			COLMGR		GET_SINGLE(CColMgr)
#define			OBJMGR		GET_SINGLE(CObjMgr)
#define			BMPMGR		GET_SINGLE(CBmpMgr)
#define			SOUNDMGR	GET_SINGLE(CSoundMgr)
#define			SCENEMGR	GET_SINGLE(CSceneMgr)



// ==========================================================================


// ==========================================================================
// 키 끝 값
#define			VK_MAX						0xff
// ==========================================================================



#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600


#define			OBJ_NOEVENT					0
#define			OBJ_DEAD					1




#define			DRAW_RECT(dc, left, top, right, bottom)			Rectangle(dc, int(left), int(top), int(right), int(bottom))
#define			DRAW_ELLIPSE(dc, left, top, right, bottom)		Ellipse(dc, int(left), int(top), int(right), int(bottom))
#define			DRAW_START_LINE(dc, startX, startY)				MoveToEx(dc, int(startX), int(startY), nullptr)
#define			DRAW_END_LINE(dc, endX, endY)					LineTo(dc, int(endX), int(endY))



template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}


enum OBJ_ID
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	// TODO...

	OBJ_END,
	
};




extern HWND g_hWnd;