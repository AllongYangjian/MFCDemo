#pragma once


// CChangePwdDlg 对话框

class CChangePwdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePwdDlg)

public:
	CChangePwdDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChangePwdDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHANGE_PWD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_uiAccount;
	CString m_uiOldPwd;
	CString m_uiNewPwd;
	CString m_uiNewConfirmPwd;
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedButtonChangePwdEdit();
	afx_msg void OnBnClickedButtonChangePwdClose();
};
