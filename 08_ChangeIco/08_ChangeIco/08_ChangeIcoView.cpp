
// 08_ChangeIcoView.cpp: CMy08ChangeIcoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "08_ChangeIco.h"
#endif

#include "08_ChangeIcoDoc.h"
#include "08_ChangeIcoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy08ChangeIcoView

IMPLEMENT_DYNCREATE(CMy08ChangeIcoView, CView)

BEGIN_MESSAGE_MAP(CMy08ChangeIcoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy08ChangeIcoView 构造/析构

CMy08ChangeIcoView::CMy08ChangeIcoView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy08ChangeIcoView::~CMy08ChangeIcoView()
{
}

BOOL CMy08ChangeIcoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy08ChangeIcoView 绘图

void CMy08ChangeIcoView::OnDraw(CDC* /*pDC*/)
{
	CMy08ChangeIcoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy08ChangeIcoView 打印

BOOL CMy08ChangeIcoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy08ChangeIcoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy08ChangeIcoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy08ChangeIcoView 诊断

#ifdef _DEBUG
void CMy08ChangeIcoView::AssertValid() const
{
	CView::AssertValid();
}

void CMy08ChangeIcoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy08ChangeIcoDoc* CMy08ChangeIcoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy08ChangeIcoDoc)));
	return (CMy08ChangeIcoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy08ChangeIcoView 消息处理程序
