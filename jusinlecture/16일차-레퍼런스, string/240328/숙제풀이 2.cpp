#include "stdafx.h"

int main()
{
	FILE*		pSaveFile = NULL;
	FILE*		pLoadFile = NULL;

	errno_t		err_Load = fopen_s(&pLoadFile, "../Data/Image.jpg", "rb");
	errno_t		err_Save = fopen_s(&pSaveFile, "../Data/Copy2.jpg", "wb");

#pragma region Ǯ�� �� 1

	/*if (0 == err_Load)
	{
		if (0 == err_Save)
		{
			while (0 == feof(pLoadFile))
			{
				char	ch(0);

				fread(&ch, sizeof(char), 1, pLoadFile);
				fwrite(&ch, sizeof(char), 1, pSaveFile);
			}

			cout << "���� ���� ����" << endl;

			fclose(pSaveFile);
		}

		else
		{
			cout << "�纻 ���� ���� ����" << endl;

		}

		fclose(pLoadFile);
	}
	else
	{
		cout << "���� ���� ���� ����" << endl;
	}*/

#pragma endregion Ǯ�� �� 1

#pragma region Ǯ�� �� 2

	/*fseek(pLoadFile, 0, SEEK_END);

	int	iIndex = ftell(pLoadFile);

	fseek(pLoadFile, 0, SEEK_SET);

	char*	pCh = new char[iIndex];

	fread(pCh, sizeof(char), iIndex, pLoadFile);
	fwrite(pCh, sizeof(char), iIndex, pSaveFile);

	cout << "���� ���� ����" << endl;

	fclose(pLoadFile);
	fclose(pSaveFile);

	delete[]pCh;
	pCh = nullptr;*/
	
#pragma endregion Ǯ�� �� 2





	return 0;
}