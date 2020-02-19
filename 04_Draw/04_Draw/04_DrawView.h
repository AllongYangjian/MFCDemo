
// 04_DrawView.h: CMy04DrawView 类的接口
//

#pragma once


class CMy04DrawView : public CView
{
protected: // 仅从序列化创建
	CMy04DrawView() noexcept;
	DECLARE_DYNCREATE(CMy04DrawView)

// 特性
public:
	CMy04DrawDoc* GetDocument() const;

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
	virtual ~CMy04DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_myPoint;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	bool m_isPress;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 04_DrawView.cpp 中的调试版本
inline CMy04DrawDoc* CMy04DrawView::GetDocument() const
   { return reinterpret_cast<CMy04DrawDoc*>(m_pDocument); }
#endif

