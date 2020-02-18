#include "mfc.h"

MyApp myapp;

BOOL MyApp::InitInstance()
{
	MyFrame *frame = new MyFrame;
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;
	return TRUE;
}

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint)
{
	MessageBox(TEXT("鼠标左键点击事件"));
}

void MyFrame::OnPaint()
{
	CPaintDC cdc(this);
	cdc.TextOutW(100, 100, TEXT("你好,mfc"));
}
