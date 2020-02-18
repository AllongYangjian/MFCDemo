#pragma once
#include <afxwin.h>

class MyApp :public CWinApp
{
public:
	virtual BOOL InitInstance();
private:

};

class MyFrame :public CFrameWnd
{
public:
	MyFrame();
	DECLARE_MESSAGE_MAP();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();
private:

};