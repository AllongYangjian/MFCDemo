
// AdoView.cpp: CAdoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ado.h"
#endif

#include "AdoDoc.h"
#include "AdoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAdoView

IMPLEMENT_DYNCREATE(CAdoView, CFormView)

BEGIN_MESSAGE_MAP(CAdoView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CAdoView 构造/析构

CAdoView::CAdoView() noexcept
	: CFormView(IDD_ADO_FORM)
{
	// TODO: 在此处添加构造代码

}

CAdoView::~CAdoView()
{
}

void CAdoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CAdoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CAdoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	ConnectSqlServer();
}


// CAdoView 打印

BOOL CAdoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CAdoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CAdoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CAdoView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}


// CAdoView 诊断

#ifdef _DEBUG
void CAdoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAdoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

void CAdoView::ConnectSqlServer()
{
	try
	{
		m_connection.CreateInstance(__uuidof(Connection));

		m_connection->Mode = adModeUnknown;
		m_connection->ConnectionTimeout = 5;
		m_connection->CommandTimeout = 5;
		m_connection->ConnectionString = _T("Data Source=127.0.0.1;Provider= SQLOLEDB.1;Initial Catalog=ado");

		HRESULT hr = m_connection->Open(_T(""), _T("sa"), _T("allong"), adConnectUnspecified);
		if (FAILED(hr))
		{
			AfxMessageBox(_T("连接失败"));
			m_connection->Close();
			return;
		}

		CString sql;
		sql.Format(TEXT("insert into student([name],[age],[score]) values ('%s',%d,%d)"), _T("yj"), 18, 20);
		_variant_t vRecordsAffected;
		long lOptions = adCmdText;
		m_connection->Execute((_bstr_t)sql, &vRecordsAffected, lOptions);

		if (m_connection->State) 
		{
			m_connection->Close();
			m_connection = NULL;
		}
		
		AfxMessageBox(_T("添加成功"));

	}
	catch (_com_error &e)
	{
		AfxMessageBox(e.ErrorMessage());
	}
	
}

CAdoDoc* CAdoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdoDoc)));
	return (CAdoDoc*)m_pDocument;
}
#endif //_DEBUG


// CAdoView 消息处理程序
