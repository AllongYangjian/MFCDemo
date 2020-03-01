#pragma once


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonClose();
private:
	CComboBox m_uiCom;
	CString m_uiAccount;
	CString m_uiPassword;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonLogin();
};
