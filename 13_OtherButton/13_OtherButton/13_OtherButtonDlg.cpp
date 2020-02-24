
// 13_OtherButtonDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "13_OtherButton.h"
#include "13_OtherButtonDlg.h"
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


// CMy13OtherButtonDlg 对话框



CMy13OtherButtonDlg::CMy13OtherButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY13_OTHERBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy13OtherButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy13OtherButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CURRENT_SEX, &CMy13OtherButtonDlg::OnBnClickedCurrentSex)
	ON_BN_CLICKED(IDC_BUTTON_FRUIT, &CMy13OtherButtonDlg::OnBnClickedButtonFruit)
END_MESSAGE_MAP()


// CMy13OtherButtonDlg 消息处理程序

BOOL CMy13OtherButtonDlg::OnInitDialog()
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
	SetWindowText(TEXT("单选&复选"));

	CheckRadioButton(IDC_MALE, IDC_FEMALE, IDC_MALE);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy13OtherButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy13OtherButtonDlg::OnPaint()
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
HCURSOR CMy13OtherButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy13OtherButtonDlg::OnBnClickedCurrentSex()
{
	CString str;
	if (IsDlgButtonChecked(IDC_MALE))
	{
		str = "男";

	}
	else if (IsDlgButtonChecked(IDC_FEMALE))
	{
		str = "女";
	}
	else
	{
		str = "未知";
	}
	MessageBox(str);
}


void CMy13OtherButtonDlg::OnBnClickedButtonFruit()
{
	CString str;
	if (IsDlgButtonChecked(IDC_CHECK_XJ))
	{
		str += TEXT("香蕉\r\n");
	}
	if (IsDlgButtonChecked(IDC_CHECK_PG))
	{
		str += TEXT("苹果\r\n");
	}
	if (IsDlgButtonChecked(IDC_CHECK_BL))
	{
		str += TEXT("菠萝\r\n");
	}
	if (IsDlgButtonChecked(IDC_CHECK_JZ))
	{
		str += TEXT("橘子\r\n");
	}
	MessageBox(str,TEXT("水果"));
}
