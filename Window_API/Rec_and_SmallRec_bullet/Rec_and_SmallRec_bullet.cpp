// Rec_and_SmallRec_bullet.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "Define.h"
#include "framework.h"
#include "Rec_and_SmallRec_bullet.h"
#include "MainGame.h"
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

//다른 클래스에서 창에대한 handle이 필요할때 쓰게하기위한 전역변수
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
    //메모리 누수 점검 F5키
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_RECANDSMALLRECBULLET, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RECANDSMALLRECBULLET));

    MSG msg;

    //기본메시지 null 초기화
    msg.message = WM_NULL;

    // 여기에 메인게임 클래스 생성및 초기화
    CMainGame MainGame;
    MainGame.Initialize();
    // 
    
    //시간 측정위한 변수 선언 64bit면 64함수 이용
    DWORD dwTime = GetTickCount64();

    // 기본 메시지 루프는 게임에는 적합하지 않음
    //아무 입력이없어도 기본 idle update수행해야하기 때문

    while (true)
    {
        // PM_REMOVE : 메세지 큐로부터 메세지를 읽어옴과 동시에 메세지 큐에서 제거
         // PM_NOREMOVE : 메세지 큐에서 메세지의 존재 여부만 파악, 메세지를 읽어오려면 GetMessage를 다시 호출해야 함

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            //종료 메시지면 break
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
            //다시 그리는 fps 제어 구문
            if (dwTime + 10 < GetTickCount64()) //+10이면 야 65프레임
            {
                MainGame.Update();
                MainGame.Render();

                dwTime = GetTickCount64();
            }
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RECANDSMALLRECBULLET));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RECANDSMALLRECBULLET);
    //게임은 메뉴창 필요없으므로 null초기화
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


//게임 제작시 메뉴 완전 무시하도록 지정안하면 좌표 어긋남!

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //그려줄 창 크기 사각형
   RECT rc{ 0,0,WINCX,WINCY };

   //창생성시 menu가 RegistClass에서 null하여 보이진않지만 아직 실제로는 있음, 따라서
   //완전 비활성화하지않으면 좌표계산이 어긋남
   //핵심설정
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(szWindowClass,
       szTitle,
       WS_OVERLAPPEDWINDOW, // 만들고자 하는 윈도우 스타일 지정(기본 값 사용하는 모양)
       CW_USEDEFAULT, 0,	// 생성되는 창의 X,Y 좌표
       rc.right - rc.left,
       rc.bottom - rc.top,	// 생성되는 창의 가로, 세로 사이즈
       nullptr,	// 부모 윈도우가 있다면 부모 윈도우 핸들 지정
       nullptr,	// 윈도우에서 사용할 메뉴의 핸들
       hInstance,
       nullptr);		//운영체제가 특수한 목적으로 사용함

   if (!hWnd)
   {
      return FALSE;
   }

   //전역변수 hWnd에 생성된 핸들 복사
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
