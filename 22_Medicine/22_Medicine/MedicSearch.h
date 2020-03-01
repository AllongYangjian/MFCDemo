#pragma once
#include "MedicSet.h"
class CMedicSearch
{
public:
	CMedicSearch();
	virtual ~CMedicSearch();

	void SetMedicSet(CMedicSet* set);

	void SetListCtrl(CListCtrl *ctrl);
	
	//int SearchByType(CString type = TEXT("��������"));

	int SearchMedic(CString sql  =TEXT(""));

private:
	CMedicSet *m_set;
	CListCtrl *m_listCtrl;
};

