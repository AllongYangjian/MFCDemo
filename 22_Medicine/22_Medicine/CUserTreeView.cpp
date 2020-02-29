// CUserTreeView.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CUserTreeView.h"


// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序
