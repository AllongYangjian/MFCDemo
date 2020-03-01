// CMedicIDDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CMedicIDDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include"22_MedicineDoc.h"

// CMedicIDDlg 对话框

IMPLEMENT_DYNAMIC(CMedicIDDlg, CDialogEx)

CMedicIDDlg::CMedicIDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BY_ID, pParent)
	, m_str(_T(""))
{

}

CMedicIDDlg::~CMedicIDDlg()
{
}

void CMedicIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(CMedicIDDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMedicIDDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMedicIDDlg 消息处理程序


void CMedicIDDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


BOOL CMedicIDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMedicIDDlg::OnBnClickedButton1()
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
	sql.Format(TEXT("id = '%s'"), m_str);

	int ret = pSearch->SearchMedic(sql);
	
	if (ret == 0)
	{
		AfxMessageBox(_T("查询成功"));
	}
}
