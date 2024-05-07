// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//window 초기화 구문

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다. 실행파일 이름

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
//창생성시 각종 옵션
ATOM                MyRegisterClass(HINSTANCE hInstance);
//창생성 메시지
BOOL                InitInstance(HINSTANCE, int);

//무조건 정해진 인자, 캐스팅도 안먹힘
//메시지 처리기 함수
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//필요없으면 없어도됨
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//int main 처럼 운영체제가 호출하는 함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,//운영체제가 부여하는 식별번호저장
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,//lpwstr중요
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 멀티프로세스위한 getmessage 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass,
       szTitle,
       WS_OVERLAPPEDWINDOW, // 만들고자 하는 윈도우 스타일 지정(기본 값 사용하는 모양)
       CW_USEDEFAULT, 0,	// 생성되는 창의 X,Y 좌표
       800, 600,	// 생성되는 창의 가로, 세로 사이즈
       nullptr,	// 부모 윈도우가 있다면 부모 윈도우 핸들 지정
       nullptr,	// 윈도우에서 사용할 메뉴의 핸들
       hInstance,
       nullptr);		//운영체제가 특수한 목적으로 사용함

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

RECT rc{ 100,100,200,200 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 0, 0, 0);

        break;
    case WM_TIMER:
        InvalidateRect(hWnd, 0, TRUE);

        break;
    }
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        case VK_RIGHT:
            rc.left += 10;
            rc.right += 10;
            break;
        case VK_LEFT:
            rc.left -= 10;
            rc.right -= 10;
            break;
        case VK_DOWN:
            rc.top += 10;
            rc.bottom += 10;
            break;
        case VK_UP:
            rc.top -= 10;
            rc.bottom -= 10;
            break;
            //총알 elipse로 만들어서 위로 날아가게
            //stl list 활용
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

           /* MoveToEx(hdc, 100, 100,NULL);
            LineTo(hdc, 200, 100);
            LineTo(hdc, 200, 200);
            LineTo(hdc, 100, 200);
            LineTo(hdc, 100, 100);
            LineTo(hdc, 200, 200);
            MoveToEx(hdc, 200, 100,NULL);
            LineTo(hdc, 100, 200);
            
            MoveToEx(hdc, 300, 300, NULL);*/
            //ltrb
            // 사각형
            Rectangle(hdc,rc.left,rc.top,rc.right,rc.bottom);
            //원
            //Elipse
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
