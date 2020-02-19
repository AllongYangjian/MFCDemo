
// 05_EditorView.h: CMy05EditorView 类的接口
//

#pragma once


class CMy05EditorView : public CView
{
protected: // 仅从序列化创建
	CMy05EditorView() noexcept;
	DECLARE_DYNCREATE(CMy05EditorView)

// 特性
public:
	CMy05EditorDoc* GetDocument() const;

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
	virtual ~CMy05EditorView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_curPoint;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	CString m_str;
};

#ifndef _DEBUG  // 05_EditorView.cpp 中的调试版本
inline CMy05EditorDoc* CMy05EditorView::GetDocument() const
   { return reinterpret_cast<CMy05EditorDoc*>(m_pDocument); }
#endif

