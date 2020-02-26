#include "stdafx.h"
#include "UdpSocketClient.h"
#include "UdpDlg.h"

UdpSocketClient::UdpSocketClient(CUdpDlg * dlg)
{
	this->m_dlg = dlg;
}

UdpSocketClient::~UdpSocketClient()
{
}


void UdpSocketClient::OnReceive(int nErrorCode)
{

	TCHAR buf[4096];
	int len =sizeof(buf);
	int read;
	ZeroMemory(buf, len);
	
	CString ip;
	UINT port;

	read = ReceiveFrom(buf, 4096, ip, port);
	if (read == SOCKET_ERROR)
	{
		return;
	}
	buf[read] = _T('\0');
	CString ret(buf);
	m_dlg->OnReceive(ret, ip);

	CSocket::OnReceive(nErrorCode);
}
