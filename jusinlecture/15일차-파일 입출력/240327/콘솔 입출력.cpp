// 240327.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// https://hungrysoul9.github.io/2019/09/26/add-vs-pre-complied-header/

int main()
{
	

	// �ؽ�Ʈ ��� ���ڿ� �Լ�
	
	// putchar : �ƽ�Ű �ڵ� ���� �� ���ڸ� ����ϴ� �Լ�
	// putchar(65);		// �ֿܼ� �ؽ�Ʈ ��� ���� �Լ�
	
	// fputc : �ƽ�Ű �ڵ� ���� �� ���ڸ� ����ϴ� �Լ�
	// fputc('B', stdout);	// �������� �ؽ�Ʈ ��� ���� �Լ�

	// getchar : �ƽ�Ű �ڵ� ���� �� ���ڸ� �Է¹޴� �Լ�

	/* char	ch = getchar();
	 putchar(ch);
	 
	// fgetc : �ƽ�Ű �ڵ� ���� �� ���ڸ� �Է¹޴� �Լ�
	int ch = fgetc(stdin); // �������� �ؽ�Ʈ ��� ���� �Լ�
	fputc(ch, stdout);
	*/
	
	// EOF : end of file (������ ���� �����ߴٴ� ���� �˷��ִ� ��� ��)
	
	//while (true)
	//{
	//	char	ch = getchar();

	//	if (EOF == ch)		// ctrl + zŰ�� �Է��ϸ� �Է� ���ۿ� EOF�� ����
	//		break;

	//	if ('a' <= ch && 'z' >= ch)
	//		ch -= 32;

	//	else if ('A' <= ch && 'Z' >= ch)
	//		ch += 32;

	//	putchar(ch);
	//}

	// ���ڿ� ��� �Լ�
	// //ȣ�� �� �ڵ� �ٹٲ�
	//puts("hello");
	//ȣ�� �� �ڵ� �ٹٲ� x
	//fputs("hello", stdout);

	//'\r'(carriage return) + '\n' : carriage return�� ���� �� ���� �� ������ �����͵��� �̵���Ų�ٴ� �̽������� ����

	// ���ڿ� �Է� �Լ�
	// char szName[8] = "";
	
	// gets_s(szName, sizeof(szName));	// ����(�����̽�)�� �о�´�. enter�� �о������ ����
	// puts(szName);

	// fgets(szName, sizeof(szName), stdin);	// enter(���� ����)�� ���� ������ �о�´�. ���ڿ��� null���ڱ��� ���, enter�� �о����
	// fputs(szName, stdout);

	// ���� ���� �Լ� : �Է� ���� ����� �Ұ���
	// fflush(stdout) : ��� ���� ����

	/*char	szID[9] = "";
	char	szName[16] = "";

	fgets(szID, sizeof(szID), stdin);
	
	while ('\n' != getchar());

	fgets(szName, sizeof(szName), stdin);

	fputs(szID, stdout);
	fputs(szName, stdout);*/

    return 0;
}

