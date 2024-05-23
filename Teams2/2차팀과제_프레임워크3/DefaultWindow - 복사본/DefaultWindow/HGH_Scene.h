#pragma once
#include "Define.h"
#include "Scene.h"
#include "HGH_LineEditor.h"
class CHGH_Scene :public CScene
{
public:
	CHGH_Scene();
	virtual ~CHGH_Scene()			override;
public:
	void		Initialize()		override;
	void		Start()				override;
	int			Update()			override;
	void		Late_Update()		override;
	void		Render(HDC hDC)		override;
	void		Release()			override;

private:
	HGH_LineEditor* m_pLineEditor{};
};

