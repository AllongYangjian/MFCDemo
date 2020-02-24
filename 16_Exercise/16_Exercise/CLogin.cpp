// CLogin.cpp: 实现文件
//

#include "stdafx.h"
#include "16_Exercise.h"
#include "CLogin.h"
#include "afxdialogex.h"


// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	DDX_Text(pDX, IDC_EDIT_PWD, m_pwd);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLogin::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CLogin::OnBnClickedButtonExit)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLogin 消息处理程序


void CLogin::OnBnClickedButtonLogin()
{
	UpdateData(TRUE);
	if (m_user.GetLength() == 0 || m_pwd.GetLength() == 0)
	{
		MessageBox(_T("用户名或密码不能为空"), _T("提示"));
		return;
	}

	if (m_user.CompareNoCase(_T("admin"))==0 && m_pwd.CompareNoCase(_T("123"))==0)
	{
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(_T("用户名或密码错误"), _T("提示"));
	}
}


void CLogin::OnBnClickedButtonExit()
{
	exit(1);
}

//默认的退出按钮调用函数
void CLogin::OnClose()
{
	exit(1);
}

//防止按回车键时关闭对话框
void CLogin::OnOK()
{
	
}
