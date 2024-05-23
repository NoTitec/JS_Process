#pragma once
#include "Define.h"
#include "Object.h"
#include "LineColliderComponent.h"
typedef struct
{
	int		lineType;
	Line2F	line;
} LineInfo;

class HGH_LineEditor
{
public:
	HGH_LineEditor();
	~HGH_LineEditor();

public:
	void Update();
	void Render();
	void Release();

	void Store_Line();
	void Load_Line();
	void Add_Line(LineInfo _tLineInfo);
private:
	list<LineInfo>	m_tInfoList;
	LineType		m_eLineType{};
	Point2F			m_tPoint[2]{};
	int				idx{};
};

