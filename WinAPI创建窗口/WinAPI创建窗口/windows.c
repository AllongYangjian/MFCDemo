#include <windows.h>
/*
���ڹ��̺���
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
		MessageBox(hwnd, TEXT("abc"), TEXT("����������"), MB_OK);
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
	wc.cbClsExtra = 0;//��ĸ�����Ϣ
	wc.cbWndExtra = 0;//���ڵĸ�����Ϣ
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//����ɫ
	//wc.hCursor = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_HELP);
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);

	wc.hInstance = hInstance;

	wc.lpfnWndProc = DealMessage;

	wc.lpszClassName = TEXT("abc");//
	wc.lpszMenuName = NULL;//�˵�����
	wc.style = nCmdShow;//��ʾ���

	//ע�ᴰ���࣬����ϵͳ���ڹ��̺����ĵ�ַ
	RegisterClass(&wc);

	//����������
	HWND wind = CreateWindow(TEXT("abc"), TEXT("Hello Windows"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(wind, nCmdShow);
	UpdateWindow(wind);

	MSG msg;
	//������յ�WM_QUIT ����0���Ƴ�
	//�����������-1�����˳�
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		//������ϵͳ�ַ���Ϣ
		DispatchMessage(&msg);
	}
	return 0;
}