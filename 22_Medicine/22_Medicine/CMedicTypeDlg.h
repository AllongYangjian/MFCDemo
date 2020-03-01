#pragma once


// CMedicTypeDlg 对话框

class CMedicTypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMedicTypeDlg)

public:
	CMedicTypeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMedicTypeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BY_TYPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_uiCombo;
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
