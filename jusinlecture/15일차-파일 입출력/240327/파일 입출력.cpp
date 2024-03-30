#include "stdafx.h"

int main()
{

	// 경로 : 파일의 저장하거나 불러올 위치를 의미

	// 절대 경로 : 드라이브명부터 현재 파일이 있는 위치까지를 표기한 상태
	// 상대 경로 : 프로젝트 파일 기준으로 위치를 표기한 상태

	// 파일 스트림 생성 == 파일 개방

	// fopen -> fopen_s

	// 파일 입출력 3 단계

	// 1. 파일 개방 2. 파일 쓰기 or 읽기 함수 호출 3. 개방했던 파일 소멸

#pragma region 텍스트 모드 파일 입출력 예
	// (개방한 파일의 주소를 리턴, 파일의 이름을 포함한 경로, 파일 입출력 모드 설정)
	// errno_t fopen_s(FILE** _Stream, char const* _FileName, char const* _Mode)

	//FILE*	pFile = NULL;
	//
	//errno_t		err = fopen_s(&pFile, "../Data/Test.txt", "wt");	// 1단계
	//
	//if (0 == err)
	//{
	//	fputs("hello world", pFile);	// 2단계

	//	cout << "저장 성공" << endl;

	//	fclose(pFile);	// 3단계
	//}
	//else
	//{
	//	cout << "파일 개방 실패" << endl;
	//}


	//FILE*	pLoadFile = NULL;

	//errno_t		err = fopen_s(&pLoadFile, "../Data/Test.txt", "rt");	// 1단계

	//char	szBuf[32] = "";

	//if (0 == err)
	//{
	//	fgets(szBuf, sizeof(szBuf), pLoadFile);
	//	fputs(szBuf, stdout);	// 2단계

	//	cout << "불러오기 성공" << endl;

	//	fclose(pLoadFile);	// 3단계
	//}
	//else
	//{
	//	cout << "파일 개방 실패" << endl;
	//}
#pragma endregion 텍스트 모드 파일 입출력 예
	
#pragma region 파일 입출력 함수 소개
	
	// fseek : 파일 내의 커서를 원하는 위치로 이동시켜 주는 함수
	// (파일 스트림, 이동할 바이트 수, 커서의 시작 위치)
	// int fseek(FILE* _Stream, long  _Offset, int   _Origin);

	// ftell : 현재 파일의 커서 위치를 알려주는 함수
	// long ftell(FILE* stream)

	// feof : 파일 커서가 EOF에 도달했는지 검사하는 함수
	// int feof(FILE* stream)
	
	//FILE*	pLoadFile = NULL;

	//errno_t		err = fopen_s(&pLoadFile, "../Data/Test.txt", "rt"); 

	//char	szBuf[32] = "";

	//if (0 == err)
	//{
	//	/*fseek(pLoadFile, 3, SEEK_SET);

	//	char	ch = fgetc(pLoadFile);

	//	cout << ch << endl;
	//	cout << ftell(pLoadFile) << endl;*/

	//	while (0 == feof(pLoadFile))
	//	{
	//		fputc(fgetc(pLoadFile), stdout);
	//	}
	//	
	//	cout << "불러오기 성공" << endl;

	//	fclose(pLoadFile);	
	//}
	//else
	//{
	//	cout << "파일 개방 실패" << endl;
	//}


#pragma endregion 파일 입출력 함수 소개

#pragma region 바이너리 모드 파일 입출력 예

 // 바이너리 모드 쓰기 전용 함수
//size_t  fwrite( void const* _Buffer,		// 출력할 메모리의 시작 주소
//				size_t      _ElementSize,  // 출력할 메모리의 크기
//				size_t      _ElementCount, // 출력할 메모리의 개수
//				FILE*       _Stream)		// 개방한 스트림

	//FILE*	pFile = NULL;

	//int		iArray[5] = { 1, 2, 3, 4, 5 };

	//errno_t		err = fopen_s(&pFile, "../Data/Binary.txt", "wb");

	//if (0 == err)
	//{
	//	//fwrite(iArray, sizeof(iArray), 1, pFile);
	//	 fwrite(iArray, sizeof(int), 5, pFile);

	//	cout << "저장 성공" << endl;

	//	fclose(pFile);	// 3단계
	//}
	//else
	//{
	//	cout << "파일 개방 실패" << endl;
	//}
	//---------------읽기
	// 
	FILE*	pLoadFile = NULL;

	int		iTemp[5] = { };

	errno_t		err2 = fopen_s(&pLoadFile, "../Data/Binary.txt", "rb");

	if (0 == err2)
	{
		fread(iTemp, sizeof(iTemp), 1, pLoadFile);
		//fread(iTemp, sizeof(int), 5, pLoadFile);

		cout << "불러오기 성공" << endl;

		fclose(pLoadFile);	// 3단계
	}
	else
	{
		cout << "파일 개방 실패" << endl;
	}

	for (unsigned int i = 0; i < size(iTemp); ++i)
	{
		cout << iTemp[i] << endl;
	}

#pragma endregion 바이너리 모드 파일 입출력 예

	return 0;
}

// 1. 텍스트 rpg 저장, 불러오기 만들 것

// - 저장하기는 아무 시점에나 삽입해도 됨
// - 불러오기는 직업을 생성하는 시점에 만들 것

// 2. 이미지를 파일 입출력을 이용하여 복사해 올 것
