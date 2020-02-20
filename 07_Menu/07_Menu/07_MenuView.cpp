﻿
// 07_MenuView.cpp: CMy07MenuView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "07_Menu.h"
#endif

#include "07_MenuDoc.h"
#include "07_MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07MenuView

IMPLEMENT_DYNCREATE(CMy07MenuView, CView)

BEGIN_MESSAGE_MAP(CMy07MenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy07MenuView 构造/析构

CMy07MenuView::CMy07MenuView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy07MenuView::~CMy07MenuView()
{
}

BOOL CMy07MenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy07MenuView 绘图

void CMy07MenuView::OnDraw(CDC* /*pDC*/)
{
	CMy07MenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy07MenuView 打印

BOOL CMy07MenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy07MenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy07MenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy07MenuView 诊断

#ifdef _DEBUG
void CMy07MenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMy07MenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy07MenuDoc* CMy07MenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy07MenuDoc)));
	return (CMy07MenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy07MenuView 消息处理程序


int CMy07MenuView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	

	return 0;
}


void CMy07MenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	//右键获取菜单,不能通过获取菜单的方式加载
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu *subMenu = menu.GetSubMenu(0);
	ClientToScreen(&point);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this);
	CView::OnRButtonDown(nFlags, point);
}
