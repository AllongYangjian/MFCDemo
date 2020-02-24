
// 16_ExerciseDlg.h: 头文件
//

#pragma once


// CMy16ExerciseDlg 对话框
class CMy16ExerciseDlg : public CDialogEx
{
// 构造
public:
	CMy16ExerciseDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY16_EXERCISE_DIALOG };
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
	CStatic *m_static;
public:
private:
	CButton m_btnPrev;
	CButton m_btnNext;
	CButton m_btnAuto;
	int m_width;
	int m_height;
public:
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonAuto();
	afx_msg void OnBnClickedButtonNext();
private:
	int m_index;
	bool m_auto;
	void loadBitmap(int idx);
	void initDlgView();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
