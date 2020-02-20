
// 07_MenuView.h: CMy07MenuView 类的接口
//

#pragma once


class CMy07MenuView : public CView
{
protected: // 仅从序列化创建
	CMy07MenuView() noexcept;
	DECLARE_DYNCREATE(CMy07MenuView)

// 特性
public:
	CMy07MenuDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy07MenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 07_MenuView.cpp 中的调试版本
inline CMy07MenuDoc* CMy07MenuView::GetDocument() const
   { return reinterpret_cast<CMy07MenuDoc*>(m_pDocument); }
#endif

