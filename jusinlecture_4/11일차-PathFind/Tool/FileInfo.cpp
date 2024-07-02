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

int CFileInfo::DirFileCount(const wstring & wstrPath)
{
	CFileFind		Find;

	wstring		wstrFilePath = wstrPath + L"\\*.*";

	// FindFile : �־��� ��ο� ������ ������ Ȯ���ϴ� �Լ�
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
	// CFileFind : ���� �� ��� ���� ���� Ŭ����
	CFileFind		Find;
	
	wstring		wstrFilePath = wstrPath + L"\\*.*";

	// FindFile : �־��� ��ο� ������ ������ Ȯ���ϴ� �Լ�
	BOOL		bContinue = Find.FindFile(wstrFilePath.c_str());

	while (bContinue)
	{
		// FindNextFile : ���� ��� �ȿ��� ���� ������ Ž��
		// ���̻� ã�� �� ���ų� ������ ������ ã���� ��� 0�� ��ȯ

		bContinue = Find.FindNextFile();

		if(Find.IsDots())
			continue;

		else if (Find.IsDirectory())
		{
			// GetFilePath: ���� ã�� ��θ� ������ �Լ�
			DirInfoExtraction(wstring(Find.GetFilePath()), rPathInfoList);
		}
		else
		{
			// ã�� ������ ������ �ִ� �ý��� ������ ��� �ǳʶ�
			if(Find.IsSystem())
				continue;

			IMGPATH*		pImgPath = new IMGPATH;
			TCHAR			szPathBuf[MAX_PATH] = L"";

			lstrcpy(szPathBuf, Find.GetFilePath().GetString());
			//szPathBuf = 0x010fd410 L"D:\\����ȯ\\147��\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack0.png"

			PathRemoveFileSpec(szPathBuf);
			// szPathBuf = 0x010fd410 L"D:\\����ȯ\\147��\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack"

			pImgPath->iCount = DirFileCount(szPathBuf);

			// GetFileTitle : ������ ���ϸ� ����
			wstring	wstrTextureName = Find.GetFileTitle().GetString();
			// wstrTextureName = L"BossMultiAttack0"

			// substr(����, ��) : ���۰� ���� �ش��ϴ� ���ڿ��� ����
			wstrTextureName = wstrTextureName.substr(0, wstrTextureName.size() - 1) + L"%d.png";
			// wstrTextureName = L"BossMultiAttack%d.png"

			TCHAR	szBuf[MAX_PATH] = L"";
			lstrcpy(szBuf, Find.GetFilePath().GetString());
			PathRemoveFileSpec(szBuf);
			// szBuf = 0x010fd1dc L"D:\\����ȯ\\147��\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack"

			// PathCombine(dst, src1, src2) : src1�� src2�� �����Ͽ� dst�� ����
			// src1�� src2�� �� \\�� �ڵ����� ���ԵǾ� ����

			PathCombine(szBuf, szBuf, wstrTextureName.c_str());
			// szBuf = 0x010fd1dc L"D:\\����ȯ\\147��\\Frame147\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack%d.png"
			pImgPath->wstrPath = ConvertRelativePath(szBuf);
			// pImgPath->wstrPath = L"..\\Texture\\Stage\\Effect\\BossMultiAttack\\BossMultiAttack%d.png"

			PathRemoveFileSpec(szBuf);
			// L"..\\Texture\\Stage\\Effect\\BossMultiAttack\\

			// PathFindFileName: ���� �̸� ã�ų� ���� ������ ���� �̸��� ã�Ƴ�
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
