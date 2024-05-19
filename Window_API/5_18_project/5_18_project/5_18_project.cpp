// 5_18_project.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "framework.h"
#include "MainGame.h"
#include "5_18_project.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

//윈도우 헨들 game서알 수있도록 전역변수$
HWND g_hWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //메모리 누수 검출 코드$
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY518PROJECT, szWindowClass, MAX_LOADSTRING);
    //윈도우창의 생성 모양 지정하는 클래스$
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY518PROJECT));

    MSG msg;
    msg.message = WM_NULL;

    //메인게임 생성, 초기화$
    CMainGame MainGame;
    MainGame.Initialize();

    DWORD dwTime = GetTickCount();

    //게임은 사용자 입력 없어도 계속 돌아감, 입력시에만 메시지 처리하도록 무한 while문 안에 메시지 검출문장작성$
    while (true)
    {
        // PM_REMOVE : 메세지 큐로부터 메세지를 읽어옴과 동시에 메세지 큐에서 제거
        // PM_NOREMOVE : 메세지 큐에서 메세지의 존재 여부만 파악, 메세지를 읽어오려면 GetMessage를 다시 호출해야 함

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            // 메뉴 기능의 단축키가 제대로 작동하도록 검사하는 함수
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                // 키보드 메세지를 가공하여 프로그램에서 쉽게 사용 할 수 있도록 해주는 함수
                TranslateMessage(&msg);

                // 시스템 메세지 큐에서 꺼낸 메세지를 프로그램의 메세지 처리 함수에게 전달하는 함수
                DispatchMessage(&msg);
            }
        }
        else
        {
            //프레임 횟수 제한
            if (dwTime + 10 < GetTickCount())
            {
                MainGame.Update();
                MainGame.LateUpdate();
                MainGame.Render();

                dwTime = GetTickCount();
            }
        }
    }

    return (int)msg.wParam;
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY518PROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.hbrBackground = CreateSolidBrush(RGB(200,200,200));
    //게임은 윈도우창의 메뉴 필요 없으므로 null을 넘겨 비활성화 해야함$
    wcex.lpszMenuName = NULL;
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

   RECT	rc{ 0, 0, WINCX, WINCY };

   // rc = 원래의 rc 크기 + 기본 창 옵션 + 메뉴 바 크기 고려 여부
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(szWindowClass,
       L"KwonSunHeok",
       WS_OVERLAPPEDWINDOW,
       //생성 창의 x,y 좌표
      CW_USEDEFAULT,
       0,
       //생성창의 가로셀 사이즈
       rc.right - rc.left,
       rc.bottom - rc.top,
       nullptr,
       nullptr,
       hInstance,
       nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   g_hWnd = hWnd;
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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
