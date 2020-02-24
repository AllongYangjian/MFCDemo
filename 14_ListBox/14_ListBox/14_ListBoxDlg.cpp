
// 14_ListBoxDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "14_ListBox.h"
#include "14_ListBoxDlg.h"
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


// CMy14ListBoxDlg 对话框



CMy14ListBoxDlg::CMy14ListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY14_LISTBOX_DIALOG, pParent)
	, m_str(_T(""))
	, m_pos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy14ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_str);
	DDX_Control(pDX, IDC_LIST_BOX, m_listBox);
	DDX_Control(pDX, IDC_COMBO_LEVEL, m_comboBox);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scrollBar);
	DDX_Text(pDX, IDC_EDIT_PROGRESS, m_pos);
}

BEGIN_MESSAGE_MAP(CMy14ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_ADD, &CMy14ListBoxDlg::OnBnClickedButton1Add)
	ON_LBN_SELCHANGE(IDC_LIST_BOX, &CMy14ListBoxDlg::OnLbnSelchangeListBox)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, &CMy14ListBoxDlg::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CMy14ListBoxDlg::OnBnClickedButtonEdit)
	ON_CBN_SELCHANGE(IDC_COMBO_LEVEL, &CMy14ListBoxDlg::OnCbnSelchangeCombo1)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMy14ListBoxDlg::OnDeltaposSpin1)
END_MESSAGE_MAP()


// CMy14ListBoxDlg 消息处理程序

BOOL CMy14ListBoxDlg::OnInitDialog()
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

	SetWindowText(TEXT("列表框&下拉框"));

	m_comboBox.SetCurSel(2);

	//滑块设置
	m_pos = 50;
	UpdateData(FALSE);

	m_scrollBar.SetScrollRange(1, 100);
	m_scrollBar.SetScrollPos(m_pos);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy14ListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy14ListBoxDlg::OnPaint()
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
HCURSOR CMy14ListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy14ListBoxDlg::OnBnClickedButton1Add()
{
	UpdateData(TRUE);
	if (m_str.GetLength() == 0)
	{
		MessageBox(TEXT("内容不能为空"));
		return;
	}
	m_listBox.AddString(m_str);
	m_str.Empty();
	UpdateData(FALSE);
}


void CMy14ListBoxDlg::OnLbnSelchangeListBox()
{
	int position = m_listBox.GetCurSel();
	if (position < -1)
	{
		return;
	}
	m_listBox.GetText(position, m_str);
	UpdateData(FALSE);
}


void CMy14ListBoxDlg::OnBnClickedButtonRemove()
{
	int position = m_listBox.GetCurSel();
	if (position < 0)
	{
		MessageBox(TEXT("请选择要删除的项目"));
		return;
	}
	m_listBox.DeleteString(position);
	m_str.Empty();
	UpdateData(FALSE);

}


void CMy14ListBoxDlg::OnBnClickedButtonEdit()
{
	int position = m_listBox.GetCurSel();
	if (position < 0)
	{
		MessageBox(TEXT("请选择要修改的项目"));
		return;
	}
	UpdateData(TRUE);
	if (m_str.GetLength() == 0)
	{
		MessageBox(TEXT("内容不能为空"));
		return;
	}
	m_listBox.DeleteString(position);
	m_listBox.InsertString(position, m_str);

	m_str.Empty();
	UpdateData(FALSE);
}


void CMy14ListBoxDlg::OnCbnSelchangeCombo1()
{
	int position = m_comboBox.GetCurSel();
	CString str;

	m_comboBox.GetLBText(position, str);

	MessageBox(str);
}

//滑块事件需要在父窗口处理
//nPos的值只有在操作滑块时才有值
void CMy14ListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int tempPos = 0;
	if (pScrollBar == &m_scrollBar)
	{
		switch (nSBCode)
		{
		case SB_THUMBPOSITION:
		{
			m_scrollBar.SetScrollPos(nPos);
			m_pos = nPos;
			UpdateData(FALSE);
		}
		break;
		case SB_LINELEFT:
		{
			tempPos = m_scrollBar.GetScrollPos()-5;
			if (tempPos < 0) 
			{
				tempPos = 0;
			}
			m_scrollBar.SetScrollPos(tempPos);
			m_pos = tempPos;
			UpdateData(FALSE);
		}
			break;
		case SB_LINERIGHT:
		{
			tempPos = m_scrollBar.GetScrollPos() + 5;
			if (tempPos >100)
			{
				tempPos = 100;
			}
			m_scrollBar.SetScrollPos(tempPos);
			m_pos = tempPos;
			UpdateData(FALSE);
		}
			break;
		case SB_PAGELEFT:
		{
			tempPos = m_scrollBar.GetScrollPos() - 10;
			if (tempPos < 0)
			{
				tempPos = 0;
			}
			m_scrollBar.SetScrollPos(tempPos);
			m_pos = tempPos;
			UpdateData(FALSE);
		}
			break;
		case SB_PAGERIGHT:
		{
			tempPos = m_scrollBar.GetScrollPos() + 10;
			if (tempPos > 100)
			{
				tempPos = 100;
			}
			m_scrollBar.SetScrollPos(tempPos);
			m_pos = tempPos;
			UpdateData(FALSE);
		}
			break;
		default:
			break;
		}

	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy14ListBoxDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	*pResult = 0;
}
