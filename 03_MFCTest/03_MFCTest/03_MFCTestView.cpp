
// 03_MFCTestView.cpp: CMy03MFCTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "03_MFCTest.h"
#endif

#include "03_MFCTestDoc.h"
#include "03_MFCTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03MFCTestView

IMPLEMENT_DYNCREATE(CMy03MFCTestView, CView)

BEGIN_MESSAGE_MAP(CMy03MFCTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy03MFCTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy03MFCTestView 构造/析构

CMy03MFCTestView::CMy03MFCTestView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03MFCTestView::~CMy03MFCTestView()
{
}

BOOL CMy03MFCTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03MFCTestView 绘图

void CMy03MFCTestView::OnDraw(CDC* /*pDC*/)
{
	CMy03MFCTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03MFCTestView 打印


void CMy03MFCTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy03MFCTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03MFCTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03MFCTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy03MFCTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy03MFCTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy03MFCTestView 诊断

#ifdef _DEBUG
void CMy03MFCTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMy03MFCTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03MFCTestDoc* CMy03MFCTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03MFCTestDoc)));
	return (CMy03MFCTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03MFCTestView 消息处理程序
