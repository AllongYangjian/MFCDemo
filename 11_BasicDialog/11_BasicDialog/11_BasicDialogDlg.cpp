﻿
// 11_BasicDialogDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "11_BasicDialog.h"
#include "11_BasicDialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,\
IMG_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

#define HICO(filepath) (HICON)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_ICON,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE);


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


// CMy11BasicDialogDlg 对话框



CMy11BasicDialogDlg::CMy11BasicDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY11_BASICDIALOG_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11BasicDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_button);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_EDIT_SOURCE, m_etSource);
	DDX_Control(pDX, IDC_EDIT_DESTINATION, m_etDest);
}

BEGIN_MESSAGE_MAP(CMy11BasicDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11BasicDialogDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMy11BasicDialogDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy11BasicDialogDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BTN_COPY, &CMy11BasicDialogDlg::OnBnClickedBtnCopy)
	ON_BN_CLICKED(IDC_BTB_CLOSE, &CMy11BasicDialogDlg::OnBnClickedBtbClose)
END_MESSAGE_MAP()


// CMy11BasicDialogDlg 消息处理程序

BOOL CMy11BasicDialogDlg::OnInitDialog()
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

	m_button.SetWindowTextW(TEXT("逃跑的按钮"));

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	m_button.SetBitmap(bitmap);

	m_button.MoveWindow(20, 20, bmp.bmWidth, bmp.bmHeight);

	m_str = TEXT("sb");
	UpdateData(false);//更新变量


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy11BasicDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11BasicDialogDlg::OnPaint()
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
HCURSOR CMy11BasicDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy11BasicDialogDlg::OnBnClickedButton1()
{
	
	
}


void CMy11BasicDialogDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy11BasicDialogDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	MessageBox(m_str);
}



void CMy11BasicDialogDlg::OnBnClickedBtnCopy()
{
	CString str;
	m_etSource.GetWindowTextW(str);

	if (str.GetLength() > 0)
	{
		m_etDest.SetWindowTextW(str);
	}
}


void CMy11BasicDialogDlg::OnBnClickedBtbClose()
{
	CDialogEx::OnOK();
}
