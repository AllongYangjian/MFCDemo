#include "stdafx.h"
#include "MedicSearch.h"


CMedicSearch::CMedicSearch()
{
	m_set = NULL;
	m_listCtrl = NULL;
}


CMedicSearch::~CMedicSearch()
{
}

void CMedicSearch::SetMedicSet(CMedicSet * set)
{
	m_set = set;
}

void CMedicSearch::SetListCtrl(CListCtrl * ctrl)
{
	m_listCtrl = ctrl;
}

//int CMedicSearch::SearchByType(CString type)
//{
//	if (m_set == NULL || m_listCtrl == NULL)
//	{
//		AfxMessageBox(_T("数据库指针或列表控件指针为空"));
//		return -1;
//	}
//
//	m_listCtrl->DeleteAllItems();
//
//	if (type == _T("所有类型"))
//	{
//		m_set->m_strFilter = _T("");
//	}
//	else
//	{
//		CString sql;
//		sql.Format(TEXT("classification = '%s'"), type);
//		m_set->m_strFilter = sql;
//	}
//
//	m_set->Requery();
//
//	for (int x = 0; x < m_set->GetRecordCount(); x++)
//	{
//		CString str;
//		int j = 1;
//		m_listCtrl->InsertItem(x, m_set->m_id);
//
//		m_listCtrl->SetItemText(x, j++, m_set->m_name);
//
//		m_listCtrl->SetItemText(x, j++, m_set->m_classification);
//
//		CTime time = m_set->m_produceDate;
//		str = time.Format(TEXT("%Y-%m-%d"));
//		m_listCtrl->SetItemText(x, j++, str);
//
//		m_listCtrl->SetItemText(x, j++, m_set->m_producePlace);
//
//		m_listCtrl->SetItemText(x, j++, m_set->m_discription);
//
//		m_listCtrl->SetItemText(x, j++, m_set->m_produceCompany);
//
//		str.Format(TEXT("%d"), m_set->m_quelityAssurance);
//		m_listCtrl->SetItemText(x, j++, str);
//
//		str.Format(TEXT("%d"), m_set->m_unitPrice);
//		m_listCtrl->SetItemText(x, j++, str);
//
//		str.Format(TEXT("%d"), m_set->m_number);
//		m_listCtrl->SetItemText(x, j++, str);
//
//		m_set->MoveNext();
//	}
//
//	return 0;
//}

int CMedicSearch::SearchMedic(CString sql,BOOL expire)
{
	if(m_set == NULL || m_listCtrl == NULL)
	{
		AfxMessageBox(_T("数据库指针或列表控件指针为空"));
		return -1;
	}

	m_listCtrl->DeleteAllItems();
	m_set->m_strFilter = sql;
	m_set->Requery();

	for (int x = 0; x < m_set->GetRecordCount(); x++)
	{
		CString str;
		int j = 1;
		m_listCtrl->InsertItem(x, m_set->m_id);

		m_listCtrl->SetItemText(x, j++, m_set->m_name);

		m_listCtrl->SetItemText(x, j++, m_set->m_classification);

		CTime time = m_set->m_produceDate;
		str = time.Format(TEXT("%Y-%m-%d"));
		m_listCtrl->SetItemText(x, j++, str);

		//添加时间判断
		

		m_listCtrl->SetItemText(x, j++, m_set->m_producePlace);

		m_listCtrl->SetItemText(x, j++, m_set->m_discription);

		m_listCtrl->SetItemText(x, j++, m_set->m_produceCompany);

		str.Format(TEXT("%d"), m_set->m_quelityAssurance);
		m_listCtrl->SetItemText(x, j++, str);

		str.Format(TEXT("%d"), m_set->m_unitPrice);
		m_listCtrl->SetItemText(x, j++, str);

		str.Format(TEXT("%d"), m_set->m_number);
		m_listCtrl->SetItemText(x, j++, str);

		m_set->MoveNext();
	}
	return 0;
}
