// CLoginDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "22_MedicineDoc.h"
#include "CUser.h"
// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_uiAccount(_T(""))
	, m_uiPassword(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCom);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uiPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CLoginDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	exit(1);//关闭窗口时退出进程
	CDialogEx::OnClose();
}


void CLoginDlg::OnBnClickedButtonClose()
{
	OnClose();
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//设置组合框显示第一个
	m_uiCom.SetCurSel(0);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

/*******************************
desc:用户登录函数
method:OnBnClickedButtonLogin
param:void
return:void
*******************************/
void CLoginDlg::OnBnClickedButtonLogin()
{

	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc =  (CMy22MedicineDoc*)frame->GetActiveDocument();
	//获取用户数据指针
	CUserSet* userSet = pDoc->GetUserSet();
	
	if (!userSet->IsOpen())
	{
		userSet->Open();
	}

	UpdateData(TRUE);

	int m_index = m_uiCom.GetCurSel();
	CString type;
	m_uiCom.GetLBText(m_index, type);

	if (type.IsEmpty() || m_uiAccount.IsEmpty() || m_uiPassword.IsEmpty())
	{
		AfxMessageBox(ID_LOGIN_ERR);
		return;
	}

	CUser *user = pDoc->GetUser();;
	user->SetAllMember(m_uiAccount, m_uiPassword, type);
	user->SetUserSet(userSet);

	int ret = user->Login();
	if (ret == -1)
	{
		AfxMessageBox(_T("未初始化数据集"));
	}
	else if (ret == -2)
	{
		AfxMessageBox(ID_LOGIN_FAILED);
	}
	else if (ret == 0)
	{
		CDialogEx::OnOK();
	}
	else
	{
		AfxMessageBox(_T("未知异常"));
	}
		 

#if 0
	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_uiAccount, m_uiPassword, type);
	userSet->m_strFilter = sql;

	userSet->Requery();

	if (userSet->GetRecordCount() == 0)
	{
		AfxMessageBox(ID_LOGIN_FAILED);
	}
	else
	{
	
		CDialog::OnOK();
	}

#endif // 0


}
