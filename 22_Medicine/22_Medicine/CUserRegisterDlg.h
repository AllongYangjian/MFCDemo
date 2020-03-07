#pragma once


// CUserRegisterDlg 对话框

class CUserRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserRegisterDlg)

public:
	CUserRegisterDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUserRegisterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USER_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_userType;
	CString m_userId;
	CString m_userName;
	CString m_userPwd;
	CString m_userPwdConfirm;
public:
	afx_msg void OnBnClickedButtonUserRegister();
	virtual BOOL OnInitDialog();
};
