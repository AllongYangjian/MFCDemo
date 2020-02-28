
// AdoView.h: CAdoView 类的接口
//

#pragma once
#include "UserAddDialog.h"
#include "AdoDoc.h"

class CAdoView : public CFormView
{
protected: // 仅从序列化创建
	CAdoView() noexcept;
	DECLARE_DYNCREATE(CAdoView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ADO_FORM };
#endif

// 特性
public:
	CAdoDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CAdoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	_ConnectionPtr m_connection;
	void ConnectSqlServer();
	afx_msg void OnBnClickedButtonAdd();
private:
	UserAddDialog m_userDlg;
public:
	afx_msg void OnBnClickedButtonQuery();
private:
	CListCtrl m_stuList;
//	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
};

#ifndef _DEBUG  // AdoView.cpp 中的调试版本
inline CAdoDoc* CAdoView::GetDocument() const
   { return reinterpret_cast<CAdoDoc*>(m_pDocument); }
#endif

