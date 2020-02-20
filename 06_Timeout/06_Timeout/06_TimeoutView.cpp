
// 06_TimeoutView.cpp: CMy06TimeoutView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "06_Timeout.h"
#endif

#include "06_TimeoutDoc.h"
#include "06_TimeoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy06TimeoutView

IMPLEMENT_DYNCREATE(CMy06TimeoutView, CView)

BEGIN_MESSAGE_MAP(CMy06TimeoutView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy06TimeoutView 构造/析构

CMy06TimeoutView::CMy06TimeoutView() noexcept
{

}

CMy06TimeoutView::~CMy06TimeoutView()
{
}

BOOL CMy06TimeoutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy06TimeoutView 绘图

void CMy06TimeoutView::OnDraw(CDC* /*pDC*/)
{
	CMy06TimeoutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy06TimeoutView 打印

BOOL CMy06TimeoutView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy06TimeoutView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy06TimeoutView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy06TimeoutView 诊断

#ifdef _DEBUG
void CMy06TimeoutView::AssertValid() const
{
	CView::AssertValid();
}

void CMy06TimeoutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy06TimeoutDoc* CMy06TimeoutView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy06TimeoutDoc)));
	return (CMy06TimeoutDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy06TimeoutView 消息处理程序


int CMy06TimeoutView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CClientDC dc(this);
	m_Width = 0;
	left = 30;
	top = 30;
	m_Str = TEXT("塑造自己的过程很疼、但是你可以得到一个更好的自己");
	m_Size = dc.GetTextExtent(m_Str);

	// 1表示ID
	//500 表示时间间隔，单位为毫秒
	SetTimer(1, 100, NULL);

	return 0;
}

//系统提供的回调函数
void CMy06TimeoutView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		CClientDC dc(this);
		m_Width+=5;
	
		if (m_Width > m_Size.cx)
		{
			m_Width = 0;
			Invalidate();
		}
		
		dc.TextOutW(left,top, m_Str);

		dc.SetTextColor(RGB(255, 0, 0));
		CRect rect(left,top,left+m_Width,top+m_Size.cy);
		dc.DrawText(m_Str, rect, DT_LEFT);
	}
	CView::OnTimer(nIDEvent);
	
}
