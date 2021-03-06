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

int CUser::DeleteUser(CString user)
{
	if (m_userSet == NULL)
	{
		AfxMessageBox(_T("未设置数据线连接"));
		return -1;
	}

	if (m_account == user)
	{
		AfxMessageBox(_T("删除用户不能是单前账户"));
		return -2;
	}

	CString sql;
	sql.Format(TEXT("account = '%s'"), user);
	m_userSet->m_strFilter = sql;

	m_userSet->Requery();

	if (m_userSet->GetRecordCount() == 0)
	{
		AfxMessageBox(_T("删除的用户不存在"));
		return -3;
	}

	m_userSet->Delete();

	return 0;
}
