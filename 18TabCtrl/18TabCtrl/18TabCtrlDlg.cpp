﻿
// 18TabCtrlDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "18TabCtrl.h"
#include "18TabCtrlDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy18TabCtrlDlg 对话框



CMy18TabCtrlDlg::CMy18TabCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY18TABCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy18TabCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_TAB1, c_tabCtrl);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CMy18TabCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMy18TabCtrlDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMy18TabCtrlDlg 消息处理程序

BOOL CMy18TabCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	InitTabCtrlView();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy18TabCtrlDlg::InitTabCtrlView()
{
	/*CSize size;
	size.cx = 10; size.cy = 10;
	m_tabCtrl.SetPadding(size);*/

//传统方法添加类
	/*m_tabCtrl.InsertItem(0, _T("界面一"));
	m_tabCtrl.InsertItem(1, _T("界面二"));

	m_lc_dlg1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	m_lc_dlg2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));

	CRect rc;
	m_tabCtrl.GetClientRect(rc);
	rc.top += 30;
	rc.bottom += 2;
	rc.left += 1;
	rc.right += 1;

	m_lc_dlg1.MoveWindow(rc);
	m_lc_dlg1.ShowWindow(SW_SHOW);
	m_lc_dlg2.MoveWindow(rc);
	m_lc_dlg2.ShowWindow(SW_HIDE);*/

	m_tabCtrl.AddPage(_T("页面1"), &m_lc_dlg1, IDD_DIALOG1, true);
	m_tabCtrl.AddPage(_T("页面2"), &m_lc_dlg2, IDD_DIALOG2, true);
	m_tabCtrl.CreatePage();
	m_tabCtrl.Show(0);
}

void CMy18TabCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy18TabCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy18TabCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy18TabCtrlDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	switch (m_tabCtrl.GetCurSel())
	{
	case 0:
		m_lc_dlg1.ShowWindow(SW_SHOW);
		m_lc_dlg2.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_lc_dlg1.ShowWindow(SW_HIDE);
		m_lc_dlg2.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}

	*pResult = 0;
}
