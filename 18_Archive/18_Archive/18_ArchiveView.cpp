
// 18_ArchiveView.cpp: CMy18ArchiveView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "18_Archive.h"
#endif

#include "18_ArchiveDoc.h"
#include "18_ArchiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy18ArchiveView

IMPLEMENT_DYNCREATE(CMy18ArchiveView, CView)

BEGIN_MESSAGE_MAP(CMy18ArchiveView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy18ArchiveView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy18ArchiveView 构造/析构

CMy18ArchiveView::CMy18ArchiveView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy18ArchiveView::~CMy18ArchiveView()
{
}

BOOL CMy18ArchiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy18ArchiveView 绘图

void CMy18ArchiveView::OnDraw(CDC* /*pDC*/)
{
	CMy18ArchiveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy18ArchiveView 打印


void CMy18ArchiveView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy18ArchiveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy18ArchiveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy18ArchiveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy18ArchiveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy18ArchiveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy18ArchiveView 诊断

#ifdef _DEBUG
void CMy18ArchiveView::AssertValid() const
{
	CView::AssertValid();
}

void CMy18ArchiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy18ArchiveDoc* CMy18ArchiveView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy18ArchiveDoc)));
	return (CMy18ArchiveDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy18ArchiveView 消息处理程序
