#pragma once


// CMedicIDDlg 对话框

class CMedicIDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMedicIDDlg)

public:
	CMedicIDDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMedicIDDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BY_ID};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
private:
	CString m_str;
public:
	afx_msg void OnBnClickedButton1();
};
