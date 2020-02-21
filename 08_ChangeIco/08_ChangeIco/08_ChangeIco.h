
// 08_ChangeIco.h: 08_ChangeIco 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy08ChangeIcoApp:
// 有关此类的实现，请参阅 08_ChangeIco.cpp
//

class CMy08ChangeIcoApp : public CWinApp
{
public:
	CMy08ChangeIcoApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy08ChangeIcoApp theApp;
