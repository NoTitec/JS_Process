
// 1. 5 * 5 �迭�� �̿��Ͽ� ���� ������
// - 1~25���� 5*5 �迭�� �����
// - ���ڸ� �Է� �ް� �Է� ���� ���� ��ġ�� ��ġ�� ���ڸ� *�� ����Ѵ�.
// - * �� �ټ��������� �߻��� ��� ���� ������Ų��.
// - 5 ���� �̻��̸� ����

//����

//1. �� �����
//2. �� �ʱ�ȭ�ϱ�
//3. 5���� �ɶ����� �ݺ� while��
//3-1. ���� �Է¹ް� �Է� ��ġ -1�� �����ϱ�
//3-2. *�߰��� �� ����ϱ�
//-----------------------------
//��ǻ�� �߰�
//��ǻ�Ϳ� ��
// //�ʱ�ȭ�� ��ǻ�͸ʵ� ����
// 
//������Է´�� 1~25���� ������ ������ �̱�
//������ ����
//����� ���� �� ��ǻ�� ���� �� ���帶�� ���ϴ� ��� ������ 5 �����ϸ� �¸����� ��� �� ����

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//������ ������
const int iSize(5);
int iBoard[iSize][iSize]; // ���� ��
int iComputerBoard[iSize][iSize]; // ��ǻ�� ���� ��
int iComputerRandomNumberArray[iSize * iSize]; //��ǻ�� ���� �� ������ �迭
//���� �õ尪 ���� �Լ�
void Set_Random_Seed();
// ���� �� �ʱ�ȭ �Լ�
void InitializeBoard();

// ���� �� ��� �Լ�
void Print_Board(int(*Board)[5]);

// �Է��Ѽ��� ��ġ ã�Ƽ� ǥ�� (-1�� ����) �Լ�
void Mark_Number(int(*Board)[5],int number);

// ���� üũ �Լ� (����: ���� üũ ���ϴ� �迭)
void checkBingo(int(*Board)[5],int* pbingoCount);


int main() {
    InitializeBoard();
    int ibingoCount(0); // ���� ī��Ʈ
    int iComputerbingoCount(0); //��ǻ�� ���� ī��Ʈ
    int iInput(0);
    int iComputerNumber(0);
    int iComputerRandomNumberArray_Index(0);
    while (ibingoCount < 5&&iComputerbingoCount<5) {
        cout << "���� ���� ���" << endl;
        Print_Board(iBoard);
        cout << "----------------------" << endl;
        cout << "��ǻ�� ���� ���" << endl;
        Print_Board(iComputerBoard);
        cout << "----------------------" << endl;
        //���� �Է�����ġ �������� *�����ϰ� ���� ���� ����
        cout << "1~25���� ���� �Է� : ";
        cin >> iInput;

        if (iInput < 1 || iInput > 25) {
            cout << "�߸��� �Է�" << endl;
            continue;
        }
        //�����Ϸ��� ��ġ�� ���� �̹� -1�̸� continue
        int iRow = (iInput-1) / iSize;
        int iCol = (iInput-1) % iSize;
        if (iBoard[iRow][iCol] == -1)
        {
            cout << "�̹� *�� ��ġ" << endl;
            cout << "+++++++++++++++++";
            continue;
        }
        Mark_Number(iBoard,iInput);
        checkBingo(iBoard,&ibingoCount);

        cout << "���� ���� ���� ��: " << ibingoCount << endl;
        cout << "----------------------" << endl;
        //��ǻ�� ���� �� �̾Ƽ� ��ǻ�� ���� * �����ϰ� ���� ���� ����
        iComputerNumber = iComputerRandomNumberArray[iComputerRandomNumberArray_Index];
        iComputerRandomNumberArray_Index++;
        Mark_Number(iComputerBoard, iComputerNumber);
        checkBingo(iComputerBoard,&iComputerbingoCount);
        cout << "���� ��ǻ�� ���� ��: " << iComputerbingoCount << endl;
        cout << "----------------------" << endl;
    }
    if (ibingoCount == 5)
    {
        cout << "���� ���� 5���� �޼�, ����" << endl;
    }
    else
    {
        cout << "����" << endl;
    }
    return 0;
}

void Set_Random_Seed()
{
    srand(unsigned(time(NULL)));
}
void InitializeBoard() 
{
    int number = 1;
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            iBoard[i][j] = number++;
        }
    }
    number = 1;
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            iComputerBoard[i][j] = number++;
        }
    }
    //��ǻ�� ���� �� ����� �迭 �ڼ��� ����
    for (int i = 0; i < iSize * iSize; i++)
        iComputerRandomNumberArray[i] = i + 1;
    for (int i = 0; i < 100; i++)
    {
        swap(iComputerRandomNumberArray[rand() % 25], iComputerRandomNumberArray[rand() % 25]);
    }
}

void Print_Board(int(*Board)[5]) 
{
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            if (Board[i][j] == -1) {
                cout << setw(3) << "*";
            }
            else {
                cout << setw(3) << Board[i][j];
            }
        }
        cout << endl;
    }
}

void Mark_Number(int(*Board)[5],int number) 
{
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            if (Board[i][j] == number) {
                Board[i][j] = -1;
                return;
            }
        }
    }
}

void checkBingo(int(*Board)[5],int* pbingoCount)
{
    *pbingoCount = 0;
    // \ ����밢������ Ƚ��, / ���� �밢������ Ƚ��
    int idiagStarCount1(0), idiagStarCount2(0);

    //��� �� ��ȸ
    for (int i = 0; i < iSize; ++i) {
        //�����Ƚ��, ������Ƚ��
        int irowStarCount(0), icolStarCount(0);

        //��� �� ��ȸ
        for (int j = 0; j < iSize; ++j) {
            //���� ���� * ���� ����
            if (Board[i][j] == -1) irowStarCount++;
            //���� ���� * ���� ����
            if (Board[j][i] == -1) icolStarCount++;
        }
        //���� ����� ���� * 5���� ���� �ϳ� ++
        //() ���� ������ �ּҰ� �����ϴ°� ����!!!!!!!!!!!!!!!!!!!!!!!!!
        if (irowStarCount == iSize) (*pbingoCount)++;
        //���� ����� ���� * 5���� ���� �ϳ� ++
        if (icolStarCount == iSize) (*pbingoCount)++;

        //���� \���� �밢�� *���� ����
        if (Board[i][i] == -1) idiagStarCount1++;
        //���� /���� 
        if (Board[i][iSize - i - 1] == -1) idiagStarCount2++;
    }

    //���� \���� �밢�� *�� 5���� ���� �ϳ�++
    if (idiagStarCount1 == iSize) (*pbingoCount)++;
    //���� /���� �밢�� *�� 5���� ���� �ϳ�++
    if (idiagStarCount2 == iSize) (*pbingoCount)++;
}