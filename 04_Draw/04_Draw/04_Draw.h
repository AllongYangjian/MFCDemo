﻿
// 04_Draw.h: 04_Draw 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy04DrawApp:
// 有关此类的实现，请参阅 04_Draw.cpp
//

class CMy04DrawApp : public CWinApp
{
public:
	CMy04DrawApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04DrawApp theApp;