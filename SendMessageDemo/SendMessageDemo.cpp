

#include "dbgPrint.h"
#include "getMessage.h"
#include "proc.h"
#include "windows.h"
#include <iostream>

HHOOK hHook = NULL;

#pragma comment(lib,"DbgHelp.lib")
#pragma comment  (lib, "User32.lib")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

int  main()
{

    dbgPrint("ssss");
    // 注册窗口类
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyConsoleWindowClass";
    RegisterClass(&wc);

    // 创建窗口
    HWND hwnd = CreateWindowEx(0, "MyConsoleWindowClass", "AcceptWindow",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, NULL, NULL, GetModuleHandle(NULL), NULL);
    dbgPrint("%p", hwnd);

    // 获取窗口句柄
    if (hwnd != NULL) {
   
        std::cout << "开始hook线程";
        //dbgPrint("hook线程");
       // HINSTANCE hInstance = GetModuleHandle(NULL);

        // 设置钩子
        hHook = SetWindowsHookEx(WH_CALLWNDPROC, acceptProc, NULL, 0);
        if (hHook == NULL) {
            // 处理钩子设置失败的情况
            // ...
            std::cout << "hook失败";
            return 1;
        }
        ShowWindow(hwnd, SW_SHOWDEFAULT);
        UpdateWindow(hwnd);
    }




    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
    
}

