#include "stdafx.h"
// 2. �̹����� ���� ������� �̿��Ͽ� ������ �� ��
int main()
{

	//���ϴ� ���� �̸� �Է�(Ȯ���� ����)

	//���������̸�+Copy.mp4 ���� �����ϱ�

	cout << "�����ϰ����ϴ� �����̸��� Ȯ���� �����Ͽ� �Է�" << endl;
	char Path[230] = "./Data/";
	char szFileName[200];

	gets_s(szFileName, sizeof(szFileName));
	strcat_s(Path,sizeof(Path),szFileName);
	FILE* source, * target=NULL;
	int i;
	errno_t err= fopen_s(&source,Path, "rb");
	cout << Path << endl;
	if (source == NULL) { printf("�ش� �̸��� ���� ����\n"); return 0; } //exit(EXIT_FAILURE); 

	if (0 == err) {
		//���� ����Ʈ �� ���
		fseek(source, 0, SEEK_END);
		int length = ftell(source);
		cout << "File Size : " << length << endl;
		fseek(source, 0, SEEK_SET);
		//ī�Ǻ� ���ϰ�� ����
		char CopyfileName[240]= "./Data/";
		char* dotPosition;
		int iszFileNameLength(0);
		// ���ڿ����� '.'�� ��ġ�� ã��
		dotPosition = strchr(szFileName, '.');
		//�̸��� Ȯ���ڰ� �ִ°��
		if (dotPosition != NULL) {
			// �⺻ ���� �̸��� ���� ��� (Ȯ���� ����)
			iszFileNameLength = dotPosition - szFileName;

			// Ȯ���������� �̸��� ���ο� ���� �̸��� ����
			strncat_s(CopyfileName, sizeof(CopyfileName), szFileName, iszFileNameLength);
			// "Copy" ���ڿ� �߰�
			strcat_s(CopyfileName,sizeof(CopyfileName), "Copy");

			// Ȯ���� �߰�
			strcat_s(CopyfileName, sizeof(CopyfileName), dotPosition);
		}
		else {
			// Ȯ���ڰ� ���� ���, �׳� "Copy"�� ����
			strcat_s(CopyfileName, sizeof(CopyfileName), szFileName);
			strcat_s(CopyfileName, sizeof(CopyfileName), "Copy");
		}
		//ī�Ǻ� �̸� ��������� Ȯ���� ����� �̸��� Copy ���δ��� �ٽ�Ȯ���� ���̱�
		errno_t err2 = fopen_s(&target, CopyfileName, "wb");

		if (target == NULL) { fclose(source); return 0; } //exit(EXIT_FAILURE);

		if (0 == err2)
		{
			for (i = 0; i < length; i++) {
				fputc(fgetc(source), target);
			}
			printf("����Ϸ�\n");
			fclose(source);
			fclose(target);
		}
	}

	return 0;
}