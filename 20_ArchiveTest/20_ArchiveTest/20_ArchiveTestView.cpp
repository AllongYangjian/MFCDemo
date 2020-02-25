
// 20_ArchiveTestView.cpp: CMy20ArchiveTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "20_ArchiveTest.h"
#endif

#include "20_ArchiveTestDoc.h"
#include "20_ArchiveTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20ArchiveTestView

IMPLEMENT_DYNCREATE(CMy20ArchiveTestView, CFormView)

BEGIN_MESSAGE_MAP(CMy20ArchiveTestView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20ArchiveTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_RADIO_EDIT, &CMy20ArchiveTestView::OnBnClickedRadioEdit)
	ON_BN_CLICKED(IDC_RADIO_VIEW, &CMy20ArchiveTestView::OnBnClickedRadioView)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy20ArchiveTestView::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_PREV, &CMy20ArchiveTestView::OnBnClickedButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CMy20ArchiveTestView::OnBnClickedButtonNext)
END_MESSAGE_MAP()

// CMy20ArchiveTestView 构造/析构

CMy20ArchiveTestView::CMy20ArchiveTestView() noexcept
	: CFormView(IDD_MY20_ARCHIVETEST_FORM)
{
	// TODO: 在此处添加构造代码

}

CMy20ArchiveTestView::~CMy20ArchiveTestView()
{
}

void CMy20ArchiveTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_PREV, m_btnPrev);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
}

BOOL CMy20ArchiveTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMy20ArchiveTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CheckRadioButton(IDC_RADIO_EDIT, IDC_RADIO_VIEW, IDC_RADIO_EDIT);
	OnBnClickedRadioEdit();
	
	m_id = 0;
	m_age = 0;
	m_score = 0;
	UpdateData(FALSE);
}


// CMy20ArchiveTestView 打印


void CMy20ArchiveTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20ArchiveTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy20ArchiveTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy20ArchiveTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy20ArchiveTestView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}

void CMy20ArchiveTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20ArchiveTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20ArchiveTestView 诊断

#ifdef _DEBUG
void CMy20ArchiveTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20ArchiveTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20ArchiveTestDoc* CMy20ArchiveTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20ArchiveTestDoc)));
	return (CMy20ArchiveTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20ArchiveTestView 消息处理程序


void CMy20ArchiveTestView::OnBnClickedRadioEdit()
{
	m_btnPrev.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);

	m_btnAdd.EnableWindow(TRUE);
}


void CMy20ArchiveTestView::OnBnClickedRadioView()
{
	m_btnPrev.EnableWindow(TRUE);
	m_btnNext.EnableWindow(TRUE);

	m_btnAdd.EnableWindow(FALSE);
}


void CMy20ArchiveTestView::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
	Student *stu = new Student(m_id, m_name, m_age, m_score);

	CMy20ArchiveTestDoc* pDoc = GetDocument();

	pDoc->m_list.AddTail(stu);
	pDoc->m_pos = pDoc->m_list.GetTailPosition();
	
	m_id = 0;
	m_age = 0;
	m_score = 0;
	m_name.Empty();
	UpdateData(FALSE);
}


void CMy20ArchiveTestView::OnBnClickedButtonPrev()
{
	CMy20ArchiveTestDoc* pDoc = GetDocument();
	if (pDoc->m_list.GetCount() == 0)
	{
		return;
	}
	//获取上一个元素后，pDoc->m_pos会自动往上移动
	pDoc->m_list.GetPrev(pDoc->m_pos);
	if (pDoc->m_pos == NULL)
	{
		pDoc->m_pos = pDoc->m_list.GetTailPosition();
	}

	Student *stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_id = stu->m_id;
	m_name = stu->m_name;
	m_age = stu->m_age;
	m_score = stu->m_score;

	UpdateData(FALSE);
}


void CMy20ArchiveTestView::OnBnClickedButtonNext()
{
	CMy20ArchiveTestDoc* pDoc = GetDocument();
	if (pDoc->m_list.GetCount() == 0)
	{
		return;
	}
	//获取上一个元素后，pDoc->m_pos会自动往上移动
	pDoc->m_list.GetNext(pDoc->m_pos);
	if (pDoc->m_pos == NULL)
	{
		pDoc->m_pos = pDoc->m_list.GetHeadPosition();
	}

	Student *stu = pDoc->m_list.GetAt(pDoc->m_pos);

	m_id = stu->m_id;
	m_name = stu->m_name;
	m_age = stu->m_age;
	m_score = stu->m_score;

	UpdateData(FALSE);		
}
