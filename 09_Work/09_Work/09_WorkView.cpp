
// 09_WorkView.cpp: CMy09WorkView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "09_Work.h"
#endif

#include "09_WorkDoc.h"
#include "09_WorkView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy09WorkView

IMPLEMENT_DYNCREATE(CMy09WorkView, CView)

BEGIN_MESSAGE_MAP(CMy09WorkView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CMy09WorkView::OnRestart)
END_MESSAGE_MAP()

// CMy09WorkView 构造/析构

CMy09WorkView::CMy09WorkView() noexcept
{

	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);
	
	x1 = x2 = x3 = x4 = 30;
	y1 = y2 = y3 = y4 = 30;

}

CMy09WorkView::~CMy09WorkView()
{
}

BOOL CMy09WorkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy09WorkView 绘图

void CMy09WorkView::OnDraw(CDC* pDC)
{
	CMy09WorkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->DrawIcon(x1, y1, icon[0]);
	pDC->DrawIcon(x2, y1+60, icon[1]);
	pDC->DrawIcon(x3, y1+120, icon[2]);
	pDC->DrawIcon(x4, y1+190, icon[3]);
}


// CMy09WorkView 打印

BOOL CMy09WorkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy09WorkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy09WorkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy09WorkView 诊断

#ifdef _DEBUG
void CMy09WorkView::AssertValid() const
{
	CView::AssertValid();
}

void CMy09WorkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy09WorkDoc* CMy09WorkView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy09WorkDoc)));
	return (CMy09WorkDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy09WorkView 消息处理程序


int CMy09WorkView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(1, 500, NULL);

	return 0;
}


void CMy09WorkView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		x1 += 50;
		x2 += 70;
		x3 += 80;
		x4 += 90;


		CRect rect;
		GetClientRect(&rect);

		if (x1 > rect.Width()) 
		{
			x1 = 30;
		}

		if (x2 > rect.Width())
		{
			x2 = 30;
		}

		if (x3 > rect.Width())
		{
			x3 = 30;
		}

		if (x4 > rect.Width())
		{
			x4 = 30;
		}

		Invalidate();//通知界面更新
	}

	CView::OnTimer(nIDEvent);
}


void CMy09WorkView::OnRestart()
{
	x1 = x2 = x3 = x4 = 30;
}
