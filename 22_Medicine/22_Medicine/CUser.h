#pragma once
#include "UserSet.h"
class CUser
{
public:
	CUser();
	virtual ~CUser();
	void SetAllMember(CString account, CString pwd, CString type, CString name = _T(""));
	CString GetAccount()
	{
		return m_account;
	}
	CString GetPassowrd()
	{
		return m_password;
	}
	CString GetName() {
		return m_name;
	}
	CString GetClassification()
	{
		return m_classification;
	}

	void SetUserSet(CUserSet* pSet);

	int Login();

	int ChangePwd(CString newPwd);
private:
	CStringW	m_account;
	CStringW	m_password;
	CStringW	m_name;
	CStringW	m_classification;

	CUserSet* m_userSet;
};

