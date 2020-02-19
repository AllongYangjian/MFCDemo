
// 04_DrawView.cpp: CMy04DrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "04_Draw.h"
#endif

#include "04_DrawDoc.h"
#include "04_DrawView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04DrawView

IMPLEMENT_DYNCREATE(CMy04DrawView, CView)

BEGIN_MESSAGE_MAP(CMy04DrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy04DrawView 构造/析构

CMy04DrawView::CMy04DrawView() noexcept :m_myPoint(0),m_isPress(false)
{
	// TODO: 在此处添加构造代码

}

CMy04DrawView::~CMy04DrawView()
{
}

BOOL CMy04DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04DrawView 绘图

void CMy04DrawView::OnDraw(CDC* pDC)
{
	CMy04DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//定义画家
	CPaintDC dc(this);
	 CPen pen(PS_DASH,1,RGB(255,0,0));
	//把画笔画刷交给画家
	 CPen *oldPen = pDC->SelectObject(&pen);//返回设置前状态
	pDC->MoveTo(10, 10);
	pDC->LineTo(120, 10);

	//定义画笔画刷
	pDC->SelectObject(oldPen);
	CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(brush);
	pDC->Ellipse(20, 20, 120, 120);

	CBitmap bitmap;
	bitmap.LoadBitmapW(ID_APPLICATION);
	CBrush brush2(&bitmap);
	pDC->SelectObject(brush2);
	pDC->Ellipse(140, 20, 300,300);

	//创建字体
	CFont font;
	font.CreatePointFont(200, TEXT("宋体"));
	pDC->SelectObject(font);
	pDC->TextOutW( 10, 200, TEXT("Hello"));

}


// CMy04DrawView 打印

BOOL CMy04DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04DrawView 诊断

#ifdef _DEBUG
void CMy04DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMy04DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04DrawDoc* CMy04DrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04DrawDoc)));
	return (CMy04DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy04DrawView 消息处理程序


void CMy04DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_isPress = true;
	m_myPoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy04DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
#if 0
	CClientDC dc(this);

	dc.MoveTo(m_myPoint);
	dc.LineTo(point);
#endif

	m_isPress =false;

	CView::OnLButtonUp(nFlags, point);
}


void CMy04DrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_isPress)
	{
		CClientDC dc(this);
		dc.MoveTo(m_myPoint);
		dc.LineTo(point);

		m_myPoint = point;
	}

	CView::OnMouseMove(nFlags, point);
}
