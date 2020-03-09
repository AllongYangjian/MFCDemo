#pragma once
#include "MedicSet.h"
class CMedicSearch
{
public:
	CMedicSearch();
	virtual ~CMedicSearch();

	void SetMedicSet(CMedicSet* set);

	void SetListCtrl(CListCtrl *ctrl);
	
	//int SearchByType(CString type = TEXT("所有类型"));

	int SearchMedic(const CString sql  =TEXT(""),BOOL expire = FALSE);

private:
	CMedicSet *m_set;
	CListCtrl *m_listCtrl;
};

