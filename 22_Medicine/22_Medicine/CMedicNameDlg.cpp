// CMedicNameDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CMedicNameDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "22_MedicineDoc.h"
// CMedicNameDlg 对话框

IMPLEMENT_DYNAMIC(CMedicNameDlg, CDialogEx)

CMedicNameDlg::CMedicNameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BY_NAME, pParent)
	, m_str(_T(""))
{

}

CMedicNameDlg::~CMedicNameDlg()
{
}

void CMedicNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(CMedicNameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMedicNameDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMedicNameDlg 消息处理程序


void CMedicNameDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (m_str.IsEmpty())
	{
		AfxMessageBox(_T("请输入代号"));
		return;
	}

	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();

	CMedicSearch* pSearch = pDoc->GetMedicSearch();

	CString sql;
	sql.Format(TEXT("name like '%%%s%%'"), m_str);//模糊查询

	int ret = pSearch->SearchMedic(sql);

	if (ret == 0)
	{
		AfxMessageBox(_T("查询成功"));
	}
}
