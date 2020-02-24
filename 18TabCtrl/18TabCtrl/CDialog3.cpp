// CDialog3.cpp: 实现文件
//

#include "stdafx.h"
#include "18TabCtrl.h"
#include "CDialog3.h"
#include "afxdialogex.h"


// CDialog3 对话框

IMPLEMENT_DYNAMIC(CDialog3, CDialogEx)

CDialog3::CDialog3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDialog3::~CDialog3()
{
}

void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog3, CDialogEx)
END_MESSAGE_MAP()


// CDialog3 消息处理程序
