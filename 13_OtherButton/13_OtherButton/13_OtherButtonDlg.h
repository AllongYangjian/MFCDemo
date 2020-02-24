
// 13_OtherButtonDlg.h: 头文件
//

#pragma once


// CMy13OtherButtonDlg 对话框
class CMy13OtherButtonDlg : public CDialogEx
{
// 构造
public:
	CMy13OtherButtonDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY13_OTHERBUTTON_DIALOG };
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
public:
	afx_msg void OnBnClickedCurrentSex();
	afx_msg void OnBnClickedButtonFruit();
};
