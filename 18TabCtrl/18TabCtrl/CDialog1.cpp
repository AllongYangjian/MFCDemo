// CDialog1.cpp: 实现文件
//

#include "stdafx.h"
#include "18TabCtrl.h"
#include "CDialog1.h"
#include "afxdialogex.h"


// CDialog1 对话框

IMPLEMENT_DYNAMIC(CDialog1, CDialogEx)

CDialog1::CDialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
END_MESSAGE_MAP()


// CDialog1 消息处理程序


BOOL CDialog1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetBackgroundColor(RGB(255, 0, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
