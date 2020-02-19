
// 05_EditorView.cpp: CMy05EditorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "05_Editor.h"
#endif

#include "05_EditorDoc.h"
#include "05_EditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy05EditorView

IMPLEMENT_DYNCREATE(CMy05EditorView, CView)

BEGIN_MESSAGE_MAP(CMy05EditorView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy05EditorView 构造/析构

CMy05EditorView::CMy05EditorView() noexcept :m_curPoint(0)
{
	// TODO: 在此处添加构造代码

}

CMy05EditorView::~CMy05EditorView()
{
}

BOOL CMy05EditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy05EditorView 绘图

void CMy05EditorView::OnDraw(CDC* /*pDC*/)
{
	CMy05EditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy05EditorView 打印

BOOL CMy05EditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy05EditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy05EditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy05EditorView 诊断

#ifdef _DEBUG
void CMy05EditorView::AssertValid() const
{
	CView::AssertValid();
}

void CMy05EditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy05EditorDoc* CMy05EditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy05EditorDoc)));
	return (CMy05EditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy05EditorView 消息处理程序

//窗口创建后调用
int CMy05EditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CClientDC dc(this);

	TEXTMETRIC tm;

	dc.GetTextMetrics(&tm);

	CreateSolidCaret(tm.tmAveCharWidth, tm.tmHeight);
	ShowCaret();
	return 0;
}


void CMy05EditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	SetCaretPos(point);
	m_curPoint = point;
	m_str.Empty(); 
	CView::OnLButtonDown(nFlags, point);
}


void CMy05EditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	CClientDC dc(this);
	
	//换行和退格处理
	if (nChar == VK_RETURN)
	{	
		m_str.Empty();

		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		m_curPoint.y += tm.tmHeight;
	}
	else if (nChar == VK_BACK) 
	{
		COLORREF color = dc.GetBkColor();//取出背景色
		COLORREF oldColor = dc.SetTextColor(color);//设置字体颜色为背景色
		
		//覆盖原来的字体
		dc.TextOutW(m_curPoint.x, m_curPoint.y, m_str);
		//将字体减去一
		m_str = m_str.Left(m_str.GetLength() - 1);
		dc.SetTextColor(oldColor);
		
	}
	else
	{
		m_str += (TCHAR)nChar;
	}
	CSize size = dc.GetTextExtent(m_str);
	int x = m_curPoint.x + size.cx;
	int y = m_curPoint.y;
	SetCaretPos(CPoint(x, y));
	ShowCaret();

	//不能更改写字的起始位置
	dc.TextOutW(m_curPoint.x, m_curPoint.y, m_str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
