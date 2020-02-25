
// 19_ArchiveTestView.cpp: CMy19ArchiveTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "19_ArchiveTest.h"
#endif

#include "19_ArchiveTestDoc.h"
#include "19_ArchiveTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy19ArchiveTestView

IMPLEMENT_DYNCREATE(CMy19ArchiveTestView, CView)

BEGIN_MESSAGE_MAP(CMy19ArchiveTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy19ArchiveTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy19ArchiveTestView 构造/析构

CMy19ArchiveTestView::CMy19ArchiveTestView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy19ArchiveTestView::~CMy19ArchiveTestView()
{
}

BOOL CMy19ArchiveTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy19ArchiveTestView 绘图

void CMy19ArchiveTestView::OnDraw(CDC* pDC)
{
	CMy19ArchiveTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int x = 0; x < pDoc->m_num; x++)
	{
		pDC->Ellipse(pDoc->m_pt[x].x - 5, pDoc->m_pt[x].y - 5,
			pDoc->m_pt[x].x + 5, pDoc->m_pt[x].y + 5);
	}
}


// CMy19ArchiveTestView 打印


void CMy19ArchiveTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy19ArchiveTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy19ArchiveTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy19ArchiveTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy19ArchiveTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy19ArchiveTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy19ArchiveTestView 诊断

#ifdef _DEBUG
void CMy19ArchiveTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMy19ArchiveTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy19ArchiveTestDoc* CMy19ArchiveTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy19ArchiveTestDoc)));
	return (CMy19ArchiveTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy19ArchiveTestView 消息处理程序

//鼠标左键事件
void CMy19ArchiveTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMy19ArchiveTestDoc* pDc = GetDocument();
	if (pDc->m_num > 200)
	{
		pDc->m_num = 200;
		return;
	}
	pDc->m_pt[pDc->m_num] = point;
	pDc->m_num++;

	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
