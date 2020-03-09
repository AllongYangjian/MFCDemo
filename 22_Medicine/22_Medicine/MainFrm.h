
// MainFrm.h: CMainFrame 类的接口
//

#pragma once
#include "CUserTreeView.h"
#include "CMedicListView.h"
#include "22_MedicineDoc.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)
private:
	//CMy22MedicineDoc *pDoc;//不能作为成员变量
// 特性
public:
	//CMy22MedicineDoc* GetDocument();
	BOOL CheckUserPermission();
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	CSplitterWnd m_sWnd;//拆分窗口对象
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnUpdateAddUser(CCmdUI *pCmdUI);
	afx_msg void OnChangePwd();
	afx_msg void OnAddUser();
	afx_msg void OnUpdateDeleteUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSearchUser(CCmdUI *pCmdUI);
	afx_msg void OnDeleteUser();
	afx_msg void OnSearchUser();
	afx_msg void OnByType();
	afx_msg void OnById();
	afx_msg void OnByName();
	afx_msg void OnSearchAll();
	afx_msg void OnSearchZero();
	afx_msg void OnExitSystem();
	afx_msg void OnChangeUser();
};


