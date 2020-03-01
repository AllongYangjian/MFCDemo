
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
	// TODO: 在此添加命令处理程序代码
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


void CMainFrame::OnSearchUser()
{
	// TODO: 在此添加命令处理程序代码
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
