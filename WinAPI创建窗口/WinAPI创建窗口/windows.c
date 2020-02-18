#include <windows.h>
/*
窗口过程函数
*/
LRESULT CALLBACK DealMessage
(HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("abc"), TEXT("鼠标左键按下"), MB_OK);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC dc = BeginPaint(hwnd, &ps);
		TCHAR *p = L"aaaaaaa";
		TextOut(dc, 30, 30, p, wcslen(p));
		EndPaint(hwnd, &ps);

	}
		break;
	case WM_DESTROY:
		PostQuitMessage(2);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPreInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;//类的附加信息
	wc.cbWndExtra = 0;//窗口的附加信息
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景色
	//wc.hCursor = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_HELP);
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);

	wc.hInstance = hInstance;

	wc.lpfnWndProc = DealMessage;

	wc.lpszClassName = TEXT("abc");//
	wc.lpszMenuName = NULL;//菜单名字
	wc.style = nCmdShow;//显示风格

	//注册窗口类，告诉系统窗口过程函数的地址
	RegisterClass(&wc);

	//创建窗口类
	HWND wind = CreateWindow(TEXT("abc"), TEXT("Hello Windows"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(wind, nCmdShow);
	UpdateWindow(wind);

	MSG msg;
	//如果接收到WM_QUIT 返回0，推出
	//如果出错，返回-1，不退出
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		//给操作系统分发消息
		DispatchMessage(&msg);
	}
	return 0;
}