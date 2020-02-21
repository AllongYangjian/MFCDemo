
// 10_DialogView.cpp: CMy10DialogView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "10_Dialog.h"
#endif

#include "10_DialogDoc.h"
#include "10_DialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10DialogView

IMPLEMENT_DYNCREATE(CMy10DialogView, CView)

BEGIN_MESSAGE_MAP(CMy10DialogView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy10DialogView 构造/析构

CMy10DialogView::CMy10DialogView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy10DialogView::~CMy10DialogView()
{
}

BOOL CMy10DialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy10DialogView 绘图

void CMy10DialogView::OnDraw(CDC* /*pDC*/)
{
	CMy10DialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy10DialogView 打印

BOOL CMy10DialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy10DialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy10DialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy10DialogView 诊断

#ifdef _DEBUG
void CMy10DialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMy10DialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10DialogDoc* CMy10DialogView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10DialogDoc)));
	return (CMy10DialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy10DialogView 消息处理程序
