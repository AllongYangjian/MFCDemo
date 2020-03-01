#include "stdafx.h"
#include "CUser.h"


CUser::CUser()
{
	m_userSet = NULL;
}


CUser::~CUser()
{
}

void CUser::SetAllMember(CString account, CString pwd, CString type, CString name)
{
	m_account = account;
	m_password = pwd;
	m_classification = type;
	m_name = name;

}

void CUser::SetUserSet(CUserSet * pSet)
{
	m_userSet = pSet;
}

int CUser::Login()
{
	if (m_userSet == NULL)
	{
		return -1;
	}

	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_account, m_password, m_classification);
	m_userSet->m_strFilter = sql;

	m_userSet->Requery();

	if (m_userSet->GetRecordCount() == 0)
	{
		return -2;
	}
	return 0;
}

int CUser::ChangePwd(CString newPwd)
{
	if (m_userSet == NULL)
	{
		return -1;
	}


	CString sql;
	sql.Format(TEXT("account = '%s' and password = '%s' and classification = '%s'"), m_account, m_password, m_classification);
	m_userSet->m_strFilter = sql;

	m_userSet->Requery();

	if (m_userSet->GetRecordCount() == 0)
	{
		return -2;
	}

	m_userSet->Edit();
	m_userSet->m_password = newPwd;
	if (m_userSet->CanUpdate())
	{
		if (m_userSet->Update())
		{
			m_password = newPwd;
			return 0;
		}
		else
		{
			return -3;
		}
	}
	
	return -4;
}
