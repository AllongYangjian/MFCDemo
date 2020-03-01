#pragma once


// CDeleteDlg 对话框

class CDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDlg)

public:
	CDeleteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDeleteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DEL_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_uiCombo;
	CString m_strAccount;
	CListCtrl m_userList;
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCbnSelchangeCombo1();
	void LoadUser();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonDelUser();
};
