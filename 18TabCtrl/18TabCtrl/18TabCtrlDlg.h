
// 18TabCtrlDlg.h: 头文件
//

#pragma once
#include "CDialog1.h"
#include "CDialog2.h"
#include "CDialog3.h"
#include "TabSheet.h"

// CMy18TabCtrlDlg 对话框
class CMy18TabCtrlDlg : public CDialogEx
{
// 构造
public:
	CMy18TabCtrlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY18TABCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	void InitTabCtrlView();
public:
//	CTabCtrl c_tabCtrl;
private:
	CTabSheet m_tabCtrl;
	CDialog1 m_lc_dlg1; 
	CDialog2 m_lc_dlg2;
	CDialog3 m_lc_dlg3;
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
