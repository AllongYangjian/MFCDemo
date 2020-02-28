
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
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAdoView::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CAdoView::OnBnClickedButtonQuery)
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
	DDX_Control(pDX, IDC_LIST1, m_stuList);
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


	//设置整体样式
	m_stuList.SetExtendedStyle(m_stuList.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//设置报表风格样式
	CString head[] = { TEXT("ID"),TEXT("姓名"),TEXT("年龄"),TEXT("分数") };
	m_stuList.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_stuList.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_stuList.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_stuList.InsertColumn(2, head[3], LVCFMT_CENTER, 100);

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

CAdoDoc* CAdoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdoDoc)));
	return (CAdoDoc*)m_pDocument;
}
#endif //_DEBUG


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
		m_userDlg.SetConnection(m_connection);
		OnBnClickedButtonQuery();

		//方式一添加数据
		//* 1、定义_ConnectionPtr对象
		//2、创建_ConnectionPtr对象
		//3、连接数据库
		//4、添加sql语句
		///5、执行slq操作
		//6、判断操作是否操做成功，
		//7、关闭数据库
			/*CString sql;
		sql.Format(TEXT("insert into student([name],[age],[score]) values ('%s',%d,%d)"), _T("yj"), 18, 20);
		_variant_t vRecordsAffected;
		long lOptions = adCmdText;
		m_connection->Execute((_bstr_t)sql, &vRecordsAffected, lOptions);
		if (vRecordsAffected.intVal == 1)
		{
			AfxMessageBox(_T("添加成功"));
		}
		if (m_connection->State)
		{
			m_connection->Close();
			m_connection = NULL;
		}*/

		//方式二 使用command
		/*
		* 1、定义_ConnectionPtr对象
		2、创建_ConnectionPtr对象
		3、连接数据库
		4、定义_CommandPtr变量
		5、创建Command对象 CreateInstance
		6、创建并添加参数
		7、执行修改
		8、判断是否修改成功
		9、关闭数据库
		*
		*/
		//_CommandPtr pCommand;
		//pCommand.CreateInstance(__uuidof(Command));
		//pCommand->ActiveConnection = m_connection;
		//pCommand->CommandText = _T("insert into student([name],[age],[score]) values(?,?,?)");
		//pCommand->CommandTimeout = 5;

		//_variant_t vRecordAffected;
		//
		////初始化参数
		//CString name = _T("lwh");
		//int age = 10;
		//int score = 50;

		//_ParameterPtr p1 = pCommand->CreateParameter(_bstr_t("name"), adBSTR, adParamInput, name.GetLength(), _variant_t(name));
		//_ParameterPtr p2 = pCommand->CreateParameter(_bstr_t("age"), adInteger, adParamInput, sizeof(age), _variant_t(age));
		//_ParameterPtr p3 = pCommand->CreateParameter(_bstr_t("score"), adInteger, adParamInput, sizeof(score), _variant_t(score));

		//pCommand->Parameters->Append(p1);
		//pCommand->Parameters->Append(p2);
		//pCommand->Parameters->Append(p3);

		//pCommand->Execute(&vRecordAffected, NULL, adCmdText);
		//if (vRecordAffected.intVal == 1)
		//{
		//	AfxMessageBox(_T("添加成功"));
		//}
		//if (m_connection->State)
		//{
		//	m_connection->Close();
		//	m_connection = NULL;
		//}
	}
	catch (_com_error &e)
	{
		AfxMessageBox(e.ErrorMessage());
	}

}

// CAdoView 消息处理程序


void CAdoView::OnBnClickedButtonAdd()
{
	m_userDlg.DoModal();
}

//查询用户
void CAdoView::OnBnClickedButtonQuery()
{
	_RecordsetPtr pRecordSet = NULL;
	try
	{
		pRecordSet.CreateInstance(__uuidof(Recordset));

		HRESULT hr = pRecordSet->Open(_T("select * from student"),
			m_connection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
		if (FAILED(hr)) {
			AfxMessageBox(_T("查询失败"));
		}
		else
		{
			int row = 0;
			while (!pRecordSet->adoEOF)
			{
				CString v_id = (TCHAR*)(_bstr_t)pRecordSet->Fields->GetItem("id")->Value;
				CString v_name = (TCHAR*)(_bstr_t)pRecordSet->Fields->GetItem("name")->Value;
				_variant_t v_age = (TCHAR*)(_bstr_t)pRecordSet->Fields->GetItem("age")->Value;
				_variant_t v_score = (TCHAR*)(_bstr_t)pRecordSet->Fields->GetItem("score")->Value;
				
				//AfxMessageBox(v_name);

				m_stuList.InsertItem(row, v_id);//添加行
				m_stuList.SetItemText(row, 1, v_name);//添加列
				m_stuList.SetItemText(row, 2, v_age.bstrVal);//添加列
				m_stuList.SetItemText(row, 3, v_score.bstrVal);//添加列
				row++;
				pRecordSet->MoveNext();
			}
		}
	}
	catch (_com_error &e)
	{
		AfxMessageBox(e.ErrorMessage());
	}

	if (pRecordSet != NULL)
	{
		pRecordSet->Close();
		pRecordSet = NULL;
	}

}


//void CAdoView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
//{
//	AfxMessageBox(_T("OnActivateView"));
//
//	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
//}
