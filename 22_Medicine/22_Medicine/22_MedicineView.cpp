
// 22_MedicineView.cpp: CMy22MedicineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "22_Medicine.h"
#endif

#include "22_MedicineDoc.h"
#include "22_MedicineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy22MedicineView

IMPLEMENT_DYNCREATE(CMy22MedicineView, CFormView)

BEGIN_MESSAGE_MAP(CMy22MedicineView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy22MedicineView 构造/析构

CMy22MedicineView::CMy22MedicineView() noexcept
	: CFormView(IDD_MY22_MEDICINE_FORM)
{
	// TODO: 在此处添加构造代码

}

CMy22MedicineView::~CMy22MedicineView()
{
}

void CMy22MedicineView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMy22MedicineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMy22MedicineView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy22MedicineView 打印

BOOL CMy22MedicineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy22MedicineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy22MedicineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy22MedicineView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}


// CMy22MedicineView 诊断

#ifdef _DEBUG
void CMy22MedicineView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy22MedicineView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy22MedicineDoc* CMy22MedicineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy22MedicineDoc)));
	return (CMy22MedicineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy22MedicineView 消息处理程序
