#include "stdafx.h"

int main()
{

	// ��� : ������ �����ϰų� �ҷ��� ��ġ�� �ǹ�

	// ���� ��� : ����̺����� ���� ������ �ִ� ��ġ������ ǥ���� ����
	// ��� ��� : ������Ʈ ���� �������� ��ġ�� ǥ���� ����

	// ���� ��Ʈ�� ���� == ���� ����

	// fopen -> fopen_s

	// ���� ����� 3 �ܰ�

	// 1. ���� ���� 2. ���� ���� or �б� �Լ� ȣ�� 3. �����ߴ� ���� �Ҹ�

#pragma region �ؽ�Ʈ ��� ���� ����� ��
	// (������ ������ �ּҸ� ����, ������ �̸��� ������ ���, ���� ����� ��� ����)
	// errno_t fopen_s(FILE** _Stream, char const* _FileName, char const* _Mode)

	//FILE*	pFile = NULL;
	//
	//errno_t		err = fopen_s(&pFile, "../Data/Test.txt", "wt");	// 1�ܰ�
	//
	//if (0 == err)
	//{
	//	fputs("hello world", pFile);	// 2�ܰ�

	//	cout << "���� ����" << endl;

	//	fclose(pFile);	// 3�ܰ�
	//}
	//else
	//{
	//	cout << "���� ���� ����" << endl;
	//}


	//FILE*	pLoadFile = NULL;

	//errno_t		err = fopen_s(&pLoadFile, "../Data/Test.txt", "rt");	// 1�ܰ�

	//char	szBuf[32] = "";

	//if (0 == err)
	//{
	//	fgets(szBuf, sizeof(szBuf), pLoadFile);
	//	fputs(szBuf, stdout);	// 2�ܰ�

	//	cout << "�ҷ����� ����" << endl;

	//	fclose(pLoadFile);	// 3�ܰ�
	//}
	//else
	//{
	//	cout << "���� ���� ����" << endl;
	//}
#pragma endregion �ؽ�Ʈ ��� ���� ����� ��
	
#pragma region ���� ����� �Լ� �Ұ�
	
	// fseek : ���� ���� Ŀ���� ���ϴ� ��ġ�� �̵����� �ִ� �Լ�
	// (���� ��Ʈ��, �̵��� ����Ʈ ��, Ŀ���� ���� ��ġ)
	// int fseek(FILE* _Stream, long  _Offset, int   _Origin);

	// ftell : ���� ������ Ŀ�� ��ġ�� �˷��ִ� �Լ�
	// long ftell(FILE* stream)

	// feof : ���� Ŀ���� EOF�� �����ߴ��� �˻��ϴ� �Լ�
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
	//	cout << "�ҷ����� ����" << endl;

	//	fclose(pLoadFile);	
	//}
	//else
	//{
	//	cout << "���� ���� ����" << endl;
	//}


#pragma endregion ���� ����� �Լ� �Ұ�

#pragma region ���̳ʸ� ��� ���� ����� ��

 // ���̳ʸ� ��� ���� ���� �Լ�
//size_t  fwrite( void const* _Buffer,		// ����� �޸��� ���� �ּ�
//				size_t      _ElementSize,  // ����� �޸��� ũ��
//				size_t      _ElementCount, // ����� �޸��� ����
//				FILE*       _Stream)		// ������ ��Ʈ��

	//FILE*	pFile = NULL;

	//int		iArray[5] = { 1, 2, 3, 4, 5 };

	//errno_t		err = fopen_s(&pFile, "../Data/Binary.txt", "wb");

	//if (0 == err)
	//{
	//	//fwrite(iArray, sizeof(iArray), 1, pFile);
	//	 fwrite(iArray, sizeof(int), 5, pFile);

	//	cout << "���� ����" << endl;

	//	fclose(pFile);	// 3�ܰ�
	//}
	//else
	//{
	//	cout << "���� ���� ����" << endl;
	//}
	//---------------�б�
	// 
	FILE*	pLoadFile = NULL;

	int		iTemp[5] = { };

	errno_t		err2 = fopen_s(&pLoadFile, "../Data/Binary.txt", "rb");

	if (0 == err2)
	{
		fread(iTemp, sizeof(iTemp), 1, pLoadFile);
		//fread(iTemp, sizeof(int), 5, pLoadFile);

		cout << "�ҷ����� ����" << endl;

		fclose(pLoadFile);	// 3�ܰ�
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}

	for (unsigned int i = 0; i < size(iTemp); ++i)
	{
		cout << iTemp[i] << endl;
	}

#pragma endregion ���̳ʸ� ��� ���� ����� ��

	return 0;
}

// 1. �ؽ�Ʈ rpg ����, �ҷ����� ���� ��

// - �����ϱ�� �ƹ� �������� �����ص� ��
// - �ҷ������ ������ �����ϴ� ������ ���� ��

// 2. �̹����� ���� ������� �̿��Ͽ� ������ �� ��
