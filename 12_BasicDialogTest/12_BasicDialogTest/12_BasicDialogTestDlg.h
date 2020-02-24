
// 12_BasicDialogTestDlg.h: 头文件
//

#pragma once


// CMy12BasicDialogTestDlg 对话框
class CMy12BasicDialogTestDlg : public CDialogEx
{
// 构造
public:
	CMy12BasicDialogTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY12_BASICDIALOGTEST_DIALOG };
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
	CString m_strSource;
	CString m_strDest;
public:
	afx_msg void OnBnClickedButtonCopy();
	afx_msg void OnBnClickedButtonClose();
};
