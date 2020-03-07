// CUserRegisterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CUserRegisterDlg.h"
#include "afxdialogex.h"
#include "22_MedicineDoc.h"
#include "MainFrm.h"
#include "CUserTreeView.h"
// CUserRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CUserRegisterDlg, CDialogEx)

CUserRegisterDlg::CUserRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_USER_REGISTER, pParent)
	, m_userId(_T(""))
	, m_userName(_T(""))
	, m_userPwd(_T(""))
	, m_userPwdConfirm(_T(""))
{



}

CUserRegisterDlg::~CUserRegisterDlg()
{
}

void CUserRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_userType);
	DDX_Text(pDX, IDC_EDIT1, m_userId);
	DDX_Text(pDX, IDC_EDIT2, m_userName);
	DDX_Text(pDX, IDC_EDIT3, m_userPwd);
	DDX_Text(pDX, IDC_EDIT4, m_userPwdConfirm);
}


BEGIN_MESSAGE_MAP(CUserRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_USER_REGISTER, &CUserRegisterDlg::OnBnClickedButtonUserRegister)
END_MESSAGE_MAP()


// CUserRegisterDlg 消息处理程序

//添加用户
void CUserRegisterDlg::OnBnClickedButtonUserRegister()
{
	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();
	//获取用户数据指针
	CUserSet* userSet = pDoc->GetUserSet();
	
	if (!userSet->IsOpen())
	{
		userSet->Open();
	}

	UpdateData(TRUE);

	//获取用户类型
	CString userType;
	int index = m_userType.GetCurSel();
	m_userType.GetLBText(index, userType);

	if (userType.IsEmpty()) {
		AfxMessageBox(_T("请选择用户类型"));
		return;
	}

	if (m_userId.IsEmpty()) 
	{
		AfxMessageBox(_T("用户ID不能为空"));
		return;
	}
	
	if (m_userName.IsEmpty()) 
	{
		AfxMessageBox(_T("用户名不能为空"));
		return;
	}

	if (m_userPwd.IsEmpty()) 
	{
		AfxMessageBox(_T("用户密码不能为空"));
		return;
	}
	if (m_userPwdConfirm.IsEmpty())
	{
		AfxMessageBox(_T("确认密码"));
		return;
	}

	if (m_userPwd != m_userPwdConfirm)
	{
		AfxMessageBox(_T("两次面貌不一致"));
		return;
	}

	//查询用户是否存在
	CString sql;
	sql.Format(TEXT("account = '%s'"), m_userId);

	userSet->m_strFilter = sql;

	userSet->Requery();
	if (userSet->GetRecordCount() > 0) 
	{
		AfxMessageBox(_T("用户ID已存在"));
		return;
	}

	sql.Format(TEXT("name = '%s'"), m_userName);
	userSet->m_strFilter = sql;

	userSet->Requery();
	if (userSet->GetRecordCount() > 0)
	{
		AfxMessageBox(_T("用户名已存在"));
		return;
	}

	userSet->AddNew();
	userSet->m_account = m_userId;
	userSet->m_name = m_userName;
	userSet->m_password = m_userPwd;
	userSet->m_classification = userType;

	BOOL ret = userSet->Update();
	if (ret)
	{
		AfxMessageBox(_T("添加成功"));
		userSet->Requery();
		
		m_userId.Empty();
		m_userName.Empty();
		m_userPwd.Empty();
		m_userPwdConfirm.Empty();
		UpdateData(FALSE);

		//找到树视图
		CUserTreeView *treeView = NULL;

		POSITION pos = pDoc->GetFirstViewPosition();
		while (pos != NULL)
		{
			CView *view = pDoc->GetNextView(pos);
			if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
			{
				treeView = (CUserTreeView*)view;
				break;
			}
		}

		if (treeView == NULL)
		{
			return;
		}
		treeView->LoadUserInfo();
	}
	else
	{
		AfxMessageBox(_T("添加失败"));
	}
}


BOOL CUserRegisterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_userType.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
