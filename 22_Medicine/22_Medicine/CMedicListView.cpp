// CMedicListView.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CMedicListView.h"


// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序
