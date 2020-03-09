
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "22_Medicine.h"

#include "MainFrm.h"
#include "CChangePwdDlg.h"
#include "CDeleteDlg.h"
#include "CMedicTypeDlg.h"
#include "CMedicIDDlg.h"
#include "CMedicNameDlg.h"
#include "MedicSearch.h"
#include "CUserRegisterDlg.h"
#include "CUserTreeView.h"
#include "CLoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ADD_USER, &CMainFrame::OnUpdateAddUser)
	ON_COMMAND(ID_CHANGE_PWD, &CMainFrame::OnChangePwd)
	ON_COMMAND(ID_ADD_USER, &CMainFrame::OnAddUser)
	ON_UPDATE_COMMAND_UI(ID_DELETE_USER, &CMainFrame::OnUpdateDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_SEARCH_USER, &CMainFrame::OnUpdateSearchUser)
	ON_COMMAND(ID_DELETE_USER, &CMainFrame::OnDeleteUser)
	ON_COMMAND(ID_SEARCH_USER, &CMainFrame::OnSearchUser)
	ON_COMMAND(ID_BY_TYPE, &CMainFrame::OnByType)
	ON_COMMAND(ID_BY_ID, &CMainFrame::OnById)
	ON_COMMAND(ID_BY_NAME, &CMainFrame::OnByName)
	ON_COMMAND(ID_SEARCH_ALL, &CMainFrame::OnSearchAll)
	ON_COMMAND(ID_SEARCH_ZERO, &CMainFrame::OnSearchZero)
	ON_COMMAND(ID_EXIT_SYSTEM, &CMainFrame::OnExitSystem)
	ON_COMMAND(ID_CHANGE_USER, &CMainFrame::OnChangeUser)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//pDoc = (CMy22MedicineDoc*)GetActiveDocument();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//拆分窗口
	m_sWnd.CreateStatic(this, 1, 2);//在框架上创建一个一行两列的窗口
	//设置窗口视图
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUserTreeView), CSize(230, 600), pContext);
	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView), CSize(720, 600), pContext);
	return TRUE;
}

//添加用户菜单更新事件
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(CheckUserPermission());
}

//修改用户密码
void CMainFrame::OnChangePwd()
{
	CChangePwdDlg dlg;
	dlg.DoModal();
}

//添加用户
void CMainFrame::OnAddUser()
{
	CUserRegisterDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnUpdateDeleteUser(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(CheckUserPermission());
}


void CMainFrame::OnUpdateSearchUser(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(CheckUserPermission());
}

BOOL CMainFrame::CheckUserPermission()
{
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)GetActiveDocument();

	CUser *currentUser = pDoc->GetUser();

	if (currentUser->GetClassification() == TEXT("管理员"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


void CMainFrame::OnDeleteUser()
{
	CDeleteDlg dlg;
	dlg.DoModal();
}

//查询用户
void CMainFrame::OnSearchUser()
{
	//获取框架
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//获取全局文档
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)frame->GetActiveDocument();
	//添加查询用户的代码
	//找到树视图
	CUserTreeView *treeView = NULL;
	
	POSITION pos = pDoc->GetFirstViewPosition();
	while (pos!=NULL)
	{
		CView *view = pDoc->GetNextView(pos);
		if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			treeView = (CUserTreeView*)view;
			break;
		}
	}
	if (treeView != NULL)
	{
		treeView->LoadUserInfo();
	}
}

//按药品类型查询
void CMainFrame::OnByType()
{
	CMedicTypeDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnById()
{
	CMedicIDDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnByName()
{
	CMedicNameDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnSearchAll()
{
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)GetActiveDocument();
	CMedicSearch *pSearch = pDoc->GetMedicSearch();
	pSearch->SearchMedic();

}


void CMainFrame::OnSearchZero()
{
	CMy22MedicineDoc* pDoc = (CMy22MedicineDoc*)GetActiveDocument();
	CMedicSearch *pSearch = pDoc->GetMedicSearch();
	CString sql;
	sql.Format(TEXT("number =%d"), 0);
	pSearch->SearchMedic(sql);
}


void CMainFrame::OnExitSystem()
{
	exit(1);
}


void CMainFrame::OnChangeUser()
{
	CLoginDlg dlg;
	dlg.DoModal();
	
	CMy22MedicineDoc *pDoc =  (CMy22MedicineDoc *)GetActiveDocument();

	POSITION pos = pDoc->GetFirstViewPosition();

	CUserTreeView *treeview = NULL;

	while (pos!=NULL)
	{
		CView *view = pDoc->GetNextView(pos);
		if (view->IsKindOf(RUNTIME_CLASS(CUserTreeView))) {

			treeview = (CUserTreeView*)view;
			break;
		}
	}
	if(treeview!=NULL)
	{
		treeview->LoadUserInfo();
	}

}
