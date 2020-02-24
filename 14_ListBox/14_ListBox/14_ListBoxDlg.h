
// 14_ListBoxDlg.h: 头文件
//

#pragma once


// CMy14ListBoxDlg 对话框
class CMy14ListBoxDlg : public CDialogEx
{
// 构造
public:
	CMy14ListBoxDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY14_LISTBOX_DIALOG };
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
	CString m_str;
	CListBox m_listBox;
	afx_msg void OnBnClickedButton1Add();
	afx_msg void OnLbnSelchangeListBox();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonEdit();
private:
	CComboBox m_comboBox;
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	CScrollBar m_scrollBar;
	int m_pos;
public:
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
};
