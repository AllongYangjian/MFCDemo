#pragma once


// CMedicNameDlg 对话框

class CMedicNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMedicNameDlg)

public:
	CMedicNameDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMedicNameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BY_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_str;
public:
	afx_msg void OnBnClickedButton1();
};
