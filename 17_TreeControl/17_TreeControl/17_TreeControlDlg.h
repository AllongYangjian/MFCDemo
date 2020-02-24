
// 17_TreeControlDlg.h: 头文件
//

#pragma once


// CMy17TreeControlDlg 对话框
class CMy17TreeControlDlg : public CDialogEx
{
// 构造
public:
	CMy17TreeControlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY17_TREECONTROL_DIALOG };
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
	CImageList m_imgList;
	CTreeCtrl m_treeCtrl;
};
