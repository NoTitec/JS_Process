#include "stdafx.h"

// ���Ǻ� ������ : ������ ������ ������ ���Ͽ� �ڵ������ �ڵ带 ������ ���� ���� �����ϴ� ����

// #if, #ifdef, #ifndef

// #if  (����)  // if���� ���۰� ������ ���
// #elif(����)  // if���� else if�� ������ ���
// #else		// �ռ� ������ ��� �����̸� ����
// #endif		// ���Ǻ� �������� �����ϰڴٴ� �ǹ�

#pragma region ��ó����if

//#define			NUMBER		3
//
//int main()
//{
//#if 5 > NUMBER	
//	cout << "5 ���� �۴�" << endl;
//
//#elif 5 < NUMBER
//	cout << "5 ���� ũ��" << endl;
//
//#else
//	cout << "5 �� ����" << endl;
//#endif
//
//	return 0;
//}

#pragma endregion ��ó����if

#pragma region ��ó����ifdef

//#ifdef(��ó���� ���� ����) // define���� ���ǵǾ� �ִٸ� ����
//#elif(��ó���� ���� ����) // define���� ���ǵǾ� �ִٸ� ����
//#else // define���� ���ǵǾ� ���� �ʴٸ� ����
//#endif

//int main()
//{
//#ifdef _DEBUG
//	cout << "����� ��� �Դϴ�" << endl;
//#else
//	cout << "������ ��� �Դϴ�" << endl;
//#endif // DEBUG
//
//	return 0;
//}
#pragma endregion ��ó����ifdef


#pragma region ��ó����ifndef

//#ifndef(��ó���� ���� ����) // define���� ���� �Ǿ� ���� �ʴٸ� ����
//#elif(��ó���� ���� ����) // define���� ���� �Ǿ� ���� �ʴٸ�  ����
//#else // ��� ���ǵǾ� ���� �ʴٸ� ����
//#endif
#pragma endregion ��ó����ifdef