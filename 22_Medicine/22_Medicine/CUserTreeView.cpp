// CUserTreeView.cpp: 实现文件
//

#include "stdafx.h"
#include "22_Medicine.h"
#include "CUserTreeView.h"
#include "22_MedicineDoc.h"
#include "CLoginDlg.h"
#include "CUser.h"

// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	//创建CImageList
	imgList.Create(30, 30, ILC_COLOR32, 4,4);

	HICON icon[4];
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON_MAN);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON_NOR);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON_SALE);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON1_DOC);
	for (int x = 0; x < 4; x++)
	{
		imgList.Add(icon[0]);
		imgList.Add(icon[1]);
		imgList.Add(icon[2]);
		imgList.Add(icon[3]);
	}
	//获取树控件
	CTreeCtrl& treeCtrl = this->GetTreeCtrl();
	//树控件设置图像列表
	treeCtrl.SetImageList(&imgList, TVSIL_NORMAL);

	//treeCtrl.InsertItem(_T("测试"), 0, 0, NULL);

	CMy22MedicineDoc *pDoc = (CMy22MedicineDoc *)GetDocument();
	
	CUserSet *userSet = pDoc->GetUserSet();

	if (!userSet->IsOpen()) 
	{
		userSet->Open();
	}

	CLoginDlg dlg;
	dlg.DoModal();

	userSet->m_strFilter = _T("");

	//获取当前用户信息
	CUser* currentUser = pDoc->GetUser();

	CString type[] = { _T("医生"),_T("管理员"),_T("售药员") };
	int length = sizeof(type) / sizeof(type[0]);
	for (int x = 0; x < length; x++)
	{
		HTREEITEM root = treeCtrl.InsertItem(type[x], 0, 0, NULL);
		
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type[x]);
		userSet->m_strFilter = sql;

		userSet->Requery();
		HTREEITEM loginUserCur = NULL;
		for (int y = 0; y < userSet->GetRecordCount(); y++)
		{
			if (currentUser->GetAccount() == userSet->m_account)
			{
				CString str;
				str.Format(TEXT("%s(%s)"), userSet->m_account, _T("登录用户"));
				loginUserCur = treeCtrl.InsertItem(str, x + 1, x + 1, root);
			}
			else
			{
				treeCtrl.InsertItem(userSet->m_account, x + 1, x + 1, root);
			}
			
			userSet->MoveNext();
		}
		if (loginUserCur != NULL)
		{
			treeCtrl.SelectItem(loginUserCur);
		
		}
	}


}
