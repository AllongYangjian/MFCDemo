// CChangePwdDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CChangePwdDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "22_MedicineDoc.h"

// CChangePwdDlg 对话框

IMPLEMENT_DYNAMIC(CChangePwdDlg, CDialogEx)

CChangePwdDlg::CChangePwdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CHANGE_PWD, pParent)
	, m_uiAccount(_T(""))
	, m_uiOldPwd(_T(""))
	, m_uiNewPwd(_T(""))
	, m_uiNewConfirmPwd(_T(""))
{

}

CChangePwdDlg::~CChangePwdDlg()
{
}

void CChangePwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uiOldPwd);
	DDX_Text(pDX, IDC_EDIT3, m_uiNewPwd);
	DDX_Text(pDX, IDC_EDIT4, m_uiNewConfirmPwd);
}


BEGIN_MESSAGE_MAP(CChangePwdDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_PWD_EDIT, &CChangePwdDlg::OnBnClickedButtonChangePwdEdit)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_PWD_CLOSE, &CChangePwdDlg::OnBnClickedButtonChangePwdClose)
END_MESSAGE_MAP()


// CChangePwdDlg 消息处理程序


void CChangePwdDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}


BOOL CChangePwdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();

	CMy22MedicineDoc *pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();

	CUser* user = pDoc->GetUser();

	m_uiAccount = user->GetAccount();
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CChangePwdDlg::OnBnClickedButtonChangePwdEdit()
{


	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();

	CMy22MedicineDoc *pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();

	CUser* user = pDoc->GetUser();

	UpdateData(TRUE);
	if (m_uiOldPwd.IsEmpty())
	{
		AfxMessageBox(_T("请输入旧密码"));
		return;
	}

	if (user->GetPassowrd() != m_uiOldPwd)
	{
		AfxMessageBox(_T("原密码不正确"));
		return;
	}


	if (m_uiNewPwd.IsEmpty() || m_uiNewConfirmPwd.IsEmpty())
	{
		AfxMessageBox(_T("请输入新密码"));
		return;
	}

	if (m_uiNewPwd != m_uiNewConfirmPwd)
	{
		AfxMessageBox(_T("两次密码不相同"));
		return;
	}

	int ret = user->ChangePwd(m_uiNewPwd);
	if (ret == 0)
	{
		m_uiOldPwd.Empty();
		m_uiNewConfirmPwd.Empty();
		m_uiNewPwd.Empty();
		UpdateData(FALSE);
		AfxMessageBox(_T("修改成功"));

	}
	else if (ret == -1)
	{
		AfxMessageBox(_T("未设置数据库连接"));
	}
	else if (ret == -2)
	{
		AfxMessageBox(_T("用户不存在"));
	}
	else if (ret == -3)
	{
		AfxMessageBox(_T("修改失败"));
	}
	else if (ret == -4)
	{
		AfxMessageBox(_T("无法修改用户，请确认数据库连接"));
	}
	else
	{
		AfxMessageBox(_T("修改失败"));
	}
}


void CChangePwdDlg::OnBnClickedButtonChangePwdClose()
{
	CDialogEx::OnOK();
}
