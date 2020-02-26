
// UdpDlg.h: 头文件
//

#pragma once
#include "UdpSocketClient.h"

struct SocketAddress
{
	CString ip;
	UINT port;
};

// CUdpDlg 对话框
class CUdpDlg : public CDialogEx
{
// 构造
public:
	CUdpDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UDP_DIALOG };
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
	int m_port;
	CString m_content;
	CListBox m_listContent;
	CString m_ip;
public:
	UdpSocketClient* m_client;
	SocketAddress m_addr;
	afx_msg void OnBnClickedButtonSend();
	void OnReceive(LPCTSTR szText, LPCTSTR szIp);
};
