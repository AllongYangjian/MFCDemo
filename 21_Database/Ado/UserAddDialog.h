#pragma once


// UserAddDialog 对话框

class UserAddDialog : public CDialogEx
{
	DECLARE_DYNAMIC(UserAddDialog)

public:
	UserAddDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UserAddDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonClose();
	virtual BOOL OnInitDialog();
	void SetConnection(_ConnectionPtr connection);
	void SaveStudentInfo();
private:
	_ConnectionPtr m_connection;
	CString m_name;
	int m_age;
	int m_score;
};
