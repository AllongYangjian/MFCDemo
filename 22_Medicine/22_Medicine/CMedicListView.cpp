// CMedicListView.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CMedicListView.h"
#include "22_MedicineDoc.h"

// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序


void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	CListCtrl& listCtrl = this->GetListCtrl();

	//设置表格样式
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	//设置模型
	listCtrl.ModifyStyle(0, LVS_REPORT);

	CString titles[] =
	{
		_T("药品代号"),
		_T("药品名称"),
		_T("药品类别"),
		_T("库存数量"),
		_T("出厂公司"),
		_T("场地"),
		_T("出厂时间"),
		_T("保质期(月)"),
		_T("单价(元)"),
		_T("数量")
	};
	int size = sizeof(titles) / sizeof(titles[0]);
	for (int x = 0; x < size; x++)
	{
		listCtrl.InsertColumn(x, titles[x], LVCFMT_CENTER, 120);
	}

	CMy22MedicineDoc *pDoc = (CMy22MedicineDoc *)GetDocument();

	CMedicSet *medicSet = pDoc->GetMedicSet();

	if (!medicSet->IsOpen())
	{
		medicSet->Open();
	}

	CMedicSearch* pSearch = pDoc->GetMedicSearch();
	pSearch->SetMedicSet(medicSet);
	pSearch->SetListCtrl(&listCtrl);

	pSearch->SearchMedic();

	//medicSet->Requery();//查询结果



	/*for (int x = 0; x < medicSet->GetRecordCount(); x++)
	{
		CString str;
		int j = 1;
		listCtrl.InsertItem(x, medicSet->m_id);

		listCtrl.SetItemText(x, j++, medicSet->m_name);

		listCtrl.SetItemText(x, j++, medicSet->m_classification);

		CTime time = medicSet->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d"));
		listCtrl.SetItemText(x, j++, str);

		listCtrl.SetItemText(x, j++, medicSet->m_producePlace);

		listCtrl.SetItemText(x, j++, medicSet->m_discription);

		listCtrl.SetItemText(x, j++, medicSet->m_produceCompany);

		str.Format(TEXT("%d"), medicSet->m_quelityAssurance);
		listCtrl.SetItemText(x, j++, str);

		str.Format(TEXT("%d"), medicSet->m_unitPrice);
		listCtrl.SetItemText(x, j++, str);

		str.Format(TEXT("%d"), medicSet->m_number);
		listCtrl.SetItemText(x, j++, str);

		medicSet->MoveNext();
	}*/
	
}
