
// DatabaseView.h: CDatabaseView 类的接口
//

#pragma once


class CDatabaseView : public CFormView
{
protected: // 仅从序列化创建
	CDatabaseView() noexcept;
	DECLARE_DYNCREATE(CDatabaseView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DATABASE_FORM };
#endif

// 特性
public:
	CDatabaseDoc* GetDocument() const;

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
	virtual ~CDatabaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DatabaseView.cpp 中的调试版本
inline CDatabaseDoc* CDatabaseView::GetDocument() const
   { return reinterpret_cast<CDatabaseDoc*>(m_pDocument); }
#endif

