
// 03_MFCTest.h: 03_MFCTest 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy03MFCTestApp:
// 有关此类的实现，请参阅 03_MFCTest.cpp
//

class CMy03MFCTestApp : public CWinAppEx
{
public:
	CMy03MFCTestApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03MFCTestApp theApp;
