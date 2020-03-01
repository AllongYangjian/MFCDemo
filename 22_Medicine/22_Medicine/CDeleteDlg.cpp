// CDeleteDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CDeleteDlg.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include "22_MedicineDoc.h"
// CDeleteDlg 对话框

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialogEx)

CDeleteDlg::CDeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DEL_USER, pParent)
	, m_strAccount(_T(""))
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCombo);
	DDX_Text(pDX, IDC_EDIT1, m_strAccount);
	DDX_Control(pDX, IDC_LIST1, m_userList);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDeleteDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CDeleteDlg::OnBnClickedButtonClose)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDeleteDlg::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_DEL_USER, &CDeleteDlg::OnBnClickedButtonDelUser)
END_MESSAGE_MAP()


// CDeleteDlg 消息处理程序


BOOL CDeleteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	m_uiCombo.SetCurSel(0);


	//设置表格样式
	m_userList.SetExtendedStyle(m_userList.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	//设置模型
	//m_userList.ModifyStyle(0, LVS_REPORT);

	CString titles[] =
	{
		_T("账号"),
		_T("姓名"),
		_T("类别")
	};
	int size = sizeof(titles) / sizeof(titles[0]);
	for (int x = 0; x < size; x++)
	{
		m_userList.InsertColumn(x, titles[x], LVCFMT_CENTER, 150);
	}

	
	LoadUser();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDeleteDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CDeleteDlg::OnCbnSelchangeCombo1()
{
	LoadUser();
}

void CDeleteDlg::LoadUser()
{

	m_userList.DeleteAllItems();
	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();
	//获取用户数据指针
	CUserSet* userSet = pDoc->GetUserSet();

	CString type;
	int index = m_uiCombo.GetCurSel();
	m_uiCombo.GetLBText(index, type);

	//CString str;
	//str.Format(TEXT("%d"), index);
	//AfxMessageBox(str);

	CString sql;
	sql.Format(TEXT("classification = '%s'"), type);
	if (index == 0)
	{
		userSet->m_strFilter = _T("");
	}
	else
	{
		userSet->m_strFilter = sql;
	}
	userSet->Requery();

	if (userSet->GetRecordCount() == 0)
	{
		AfxMessageBox(_T("未查询到用户"));
	}
	else
	{
		for (int x = 0; x < userSet->GetRecordCount(); x++)
		{
			m_userList.InsertItem(x, userSet->m_account);
			int j = 1;
			m_userList.SetItemText(x, j++, userSet->m_name);
			m_userList.SetItemText(x, j++, userSet->m_classification);

			userSet->MoveNext();
		}
	}
}


void CDeleteDlg::OnBnClickedButtonClose()
{
	CDialogEx::OnOK();
}


//列表点击事件
void CDeleteDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	NM_LISTVIEW *pList = (NM_LISTVIEW*)pNMHDR;
	//获取所在行
	int i = pList->iItem;
	int j = 0;//定义选取列

	//获取数据
	m_strAccount = m_userList.GetItemText(i, j);
	UpdateData(FALSE);
}


void CDeleteDlg::OnBnClickedButtonDelUser()
{
	UpdateData(TRUE);
	if (m_strAccount.IsEmpty())
	{
		AfxMessageBox(_T("请选择要删除的用户"));
		return;
	}

	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();

	CUser *user = pDoc->GetUser();
	int ret = user->DeleteUser(m_strAccount);
	if (ret == 0)
	{
		m_strAccount.Empty();
		UpdateData(FALSE);
		AfxMessageBox(_T("删除成功"));
		LoadUser();
	}
	else if(ret == -1)
	{
		AfxMessageBox(_T("未设置数据线连接"));
	}
	else if (ret == -2)
	{
		AfxMessageBox(_T("删除用户不能是单前账户"));
	}
	else
	{
		AfxMessageBox(_T("删除的用户不存在"));
	}

}
