#include "stdafx.h"
// 2. 이미지를 파일 입출력을 이용하여 복사해 올 것
int main()
{

	//원하는 파일 이름 입력(확장자 포함)

	//선택파일이름+Copy.mp4 만들어서 복사하기

	cout << "복사하고자하는 파일이름을 확장자 포함하여 입력" << endl;
	char Path[230] = "./Data/";
	char szFileName[200];

	gets_s(szFileName, sizeof(szFileName));
	strcat_s(Path,sizeof(Path),szFileName);
	FILE* source, * target=NULL;
	int i;
	errno_t err= fopen_s(&source,Path, "rb");
	cout << Path << endl;
	if (source == NULL) { printf("해당 이름의 파일 없음\n"); return 0; } //exit(EXIT_FAILURE); 

	if (0 == err) {
		//파일 바이트 수 계산
		fseek(source, 0, SEEK_END);
		int length = ftell(source);
		cout << "File Size : " << length << endl;
		fseek(source, 0, SEEK_SET);
		//카피본 파일경로 생성
		char CopyfileName[240]= "./Data/";
		char* dotPosition;
		int iszFileNameLength(0);
		// 문자열에서 '.'의 위치를 찾음
		dotPosition = strchr(szFileName, '.');
		//이름이 확장자가 있는경우
		if (dotPosition != NULL) {
			// 기본 파일 이름의 길이 계산 (확장자 제외)
			iszFileNameLength = dotPosition - szFileName;

			// 확장자전까지 이름을 새로운 파일 이름에 복사
			strncat_s(CopyfileName, sizeof(CopyfileName), szFileName, iszFileNameLength);
			// "Copy" 문자열 추가
			strcat_s(CopyfileName,sizeof(CopyfileName), "Copy");

			// 확장자 추가
			strcat_s(CopyfileName, sizeof(CopyfileName), dotPosition);
		}
		else {
			// 확장자가 없는 경우, 그냥 "Copy"를 붙임
			strcat_s(CopyfileName, sizeof(CopyfileName), szFileName);
			strcat_s(CopyfileName, sizeof(CopyfileName), "Copy");
		}
		//카피본 이름 만들기위해 확장자 지우고 이름에 Copy 붙인다음 다시확장자 붙이기
		errno_t err2 = fopen_s(&target, CopyfileName, "wb");

		if (target == NULL) { fclose(source); return 0; } //exit(EXIT_FAILURE);

		if (0 == err2)
		{
			for (i = 0; i < length; i++) {
				fputc(fgetc(source), target);
			}
			printf("복사완료\n");
			fclose(source);
			fclose(target);
		}
	}

	return 0;
}