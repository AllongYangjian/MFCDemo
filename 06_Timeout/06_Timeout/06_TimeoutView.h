
// 06_TimeoutView.h: CMy06TimeoutView 类的接口
//

#pragma once


class CMy06TimeoutView : public CView
{
protected: // 仅从序列化创建
	CMy06TimeoutView() noexcept;
	DECLARE_DYNCREATE(CMy06TimeoutView)

// 特性
public:
	CMy06TimeoutDoc* GetDocument() const;

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
	virtual ~CMy06TimeoutView();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CString m_Str;
	CSize m_Size;
	int left;
	int top;
	int m_Width;
};

#ifndef _DEBUG  // 06_TimeoutView.cpp 中的调试版本
inline CMy06TimeoutDoc* CMy06TimeoutView::GetDocument() const
   { return reinterpret_cast<CMy06TimeoutDoc*>(m_pDocument); }
#endif

