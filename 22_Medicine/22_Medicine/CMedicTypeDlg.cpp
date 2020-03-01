// CMedicTypeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CMedicTypeDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "22_MedicineDoc.h"
#include "CMedicListView.h"


// CMedicTypeDlg 对话框

IMPLEMENT_DYNAMIC(CMedicTypeDlg, CDialogEx)

CMedicTypeDlg::CMedicTypeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BY_TYPE, pParent)
{

}

CMedicTypeDlg::~CMedicTypeDlg()
{
}

void CMedicTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_uiCombo);
}


BEGIN_MESSAGE_MAP(CMedicTypeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMedicTypeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMedicTypeDlg 消息处理程序


void CMedicTypeDlg::OnBnClickedButton1()
{
	
	int post = m_uiCombo.GetCurSel();
	CString type;
	m_uiCombo.GetLBText(post, type);

	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();

	CMedicSearch* pSearch = pDoc->GetMedicSearch();

	//CMedicSet* medicSet = pDoc->GetMedicSet();
	//pSearch->SetMedicSet(medicSet);

	//获取列表视图
	//找到树视图
	//CMedicListView *listView = NULL;

	//POSITION pos = pDoc->GetFirstViewPosition();
	//while (pos != NULL)
	//{
	//	CView *view = pDoc->GetNextView(pos);
	//	if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
	//	{
	//		listView = (CMedicListView*)view;
	//		break;
	//	}
	//}

	//if (listView == NULL)
	//{
	//	return;
	//} 
	//CListCtrl* listCtrl = &listView->GetListCtrl();

	//pSearch->SetListCtrl(listCtrl);
	CString sql;
	if (type == _T("所有类型"))
	{
		sql = _T("");
	}
	else
	{
		sql.Format(TEXT("classification = '%s'"), type);
	}

	pSearch->SearchMedic(sql);

}


BOOL CMedicTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_uiCombo.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMedicTypeDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	
}
