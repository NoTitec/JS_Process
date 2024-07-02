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

	// szCurDir 에서 strFullPath로 가는 상대 경로를 구해서 szRelativeDir에 저장

	PathRelativePathTo(szRelativeDir, 
		szCurDir, FILE_ATTRIBUTE_DIRECTORY,
		strFullPath.GetString(), FILE_ATTRIBUTE_DIRECTORY);


	return CString(szRelativeDir);
}

int CFileInfo::DirFileCount(const wstring & wstrPath)
{
	CFileFind		Find;

	wstring		wstrFilePath = wstrPath + L"\\*.*";

	// FindFile : 주어진 경로에 파일의 유무를 확인하는 함수
	BOOL		bContinue = Find.FindFile(wstrFilePath.c_str());

	int	iFileCnt(0);

	while (bContinue)
	{
		bContinue = Find.FindNextFile();

		if (Find.IsDots())
			continue;

		if (Find.IsSystem())
			continue;

		++iFileCnt;
	}


	return iFileCnt;
}

int CFileInfo::DirInfoExtraction(const wstring & wstrPath, list<IMGPATH*>& rPathInfoList)
{
	// CFileFind : 파일 및 경로 제어 관련 클래스
	CFileFind		Find;
	
	wstring		wstrFilePath = wstrPath + L"\\*.*";

	// FindFile : 주어진 경로에 파일의 유무를 확인하는 함수
	BOOL		bContinue = Find.FindFile(wstrFilePath.c_str());

	while (bContinue)
	{
		// FindNextFile : 동일 경로 안에서 다음 파일을 탐색
		// 더이상 찾을 게 없거나 마지막 파일을 찾았을 경우 0을 반환

		bContinue = Find.FindNextFile();

		if(Find.IsDots())
			continue;

		else if (Find.IsDirectory())
		{
			// GetFilePath: 현재 찾은 경로를 얻어오는 함수
			DirInfoExtraction(wstring(Find.GetFilePath()), rPathInfoList);
		}
		else
		{
			// 찾은 파일이 숨겨져 있는 시스템 파일인 경우 건너뜀
			if(Find.IsSystem())
				continue;

			IMGPATH*		pImgPath = new IMGPATH;
			TCHAR			szPathBuf[MAX_PATH] = L"";

			lstrcpy(szPathBuf, Find.GetFilePath().GetString());
			//szPathBuf = 0x010fd410 L"D:\\유준환\\147기\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack0.png"

			PathRemoveFileSpec(szPathBuf);
			// szPathBuf = 0x010fd410 L"D:\\유준환\\147기\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack"

			pImgPath->iCount = DirFileCount(szPathBuf);

			// GetFileTitle : 온전히 파일명만 얻어옴
			wstring	wstrTextureName = Find.GetFileTitle().GetString();
			// wstrTextureName = L"BossMultiAttack0"

			// substr(시작, 끝) : 시작과 끝에 해당하는 문자열을 얻어옴
			wstrTextureName = wstrTextureName.substr(0, wstrTextureName.size() - 1) + L"%d.png";
			// wstrTextureName = L"BossMultiAttack%d.png"

			TCHAR	szBuf[MAX_PATH] = L"";
			lstrcpy(szBuf, Find.GetFilePath().GetString());
			PathRemoveFileSpec(szBuf);
			// szBuf = 0x010fd1dc L"D:\\유준환\\147기\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack"

			// PathCombine(dst, src1, src2) : src1과 src2를 결합하여 dst에 저장
			// src1과 src2를 에 \\가 자동으로 삽입되어 저장

			PathCombine(szBuf, szBuf, wstrTextureName.c_str());
			// szBuf = 0x010fd1dc L"D:\\유준환\\147기\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack%d.png"
			pImgPath->wstrPath = ConvertRelativePath(szBuf);
			// pImgPath->wstrPath = L"..\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack%d.png"

			PathRemoveFileSpec(szBuf);
			// L"..\\Texture\\Stage\\Effect\\BossMultiAttack\\

			// PathFindFileName: 파일 이름 찾거나 가장 마지막 폴더 이름을 찾아냄
			pImgPath->wstrStateKey = PathFindFileName(szBuf);

			PathRemoveFileSpec(szBuf);
			// L"..\\Texture\\Stage\\Effect
			pImgPath->wstrObjKey = PathFindFileName(szBuf);

			rPathInfoList.push_back(pImgPath);
			bContinue = 0;
		}
	}
	
	return 0;
}
