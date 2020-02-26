
// 21_DatabaseView.cpp: CMy21DatabaseView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "21_Database.h"
#endif

#include "21_DatabaseDoc.h"
#include "21_DatabaseView.h"
#include <mysql.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy21DatabaseView

IMPLEMENT_DYNCREATE(CMy21DatabaseView, CView)

BEGIN_MESSAGE_MAP(CMy21DatabaseView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy21DatabaseView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy21DatabaseView 构造/析构

CMy21DatabaseView::CMy21DatabaseView() noexcept
{
	// TODO: 在此处添加构造代码
	

}

CMy21DatabaseView::~CMy21DatabaseView()
{
}

BOOL CMy21DatabaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy21DatabaseView 绘图

void CMy21DatabaseView::OnDraw(CDC* /*pDC*/)
{
	CMy21DatabaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy21DatabaseView 打印


void CMy21DatabaseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy21DatabaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy21DatabaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy21DatabaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy21DatabaseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy21DatabaseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy21DatabaseView 诊断

#ifdef _DEBUG
void CMy21DatabaseView::AssertValid() const
{
	CView::AssertValid();
}

void CMy21DatabaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy21DatabaseDoc* CMy21DatabaseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy21DatabaseDoc)));
	return (CMy21DatabaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy21DatabaseView 消息处理程序
