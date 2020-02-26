#pragma once
class CUdpDlg;
#include <afxsock.h>
class UdpSocketClient :
	public CSocket
{
public:
	UdpSocketClient(CUdpDlg* dlg);
	~UdpSocketClient();
	virtual void OnReceive(int nErrorCode);
	CUdpDlg* m_dlg;
};

