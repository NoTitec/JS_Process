#include "stdafx.h"
#include "FileInfo.h"


CFileInfo::CFileInfo()
{
}


CFileInfo::~CFileInfo()
{
}

CString CFileInfo::ConvertRelativePath(CString strFullPath)
{
	TCHAR		szCurDir[MAX_PATH] = L"";
	TCHAR		szRelativeDir[MAX_PATH] = L"";

	GetCurrentDirectory(MAX_PATH, szCurDir);

	// szCurDir ���� strFullPath�� ���� ��� ��θ� ���ؼ� szRelativeDir�� ����

	PathRelativePathTo(szRelativeDir, 
		szCurDir, FILE_ATTRIBUTE_DIRECTORY,
		strFullPath.GetString(), FILE_ATTRIBUTE_DIRECTORY);


	return CString(szRelativeDir);
}
