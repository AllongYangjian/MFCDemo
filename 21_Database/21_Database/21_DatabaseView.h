
// 21_DatabaseView.h: CMy21DatabaseView 类的接口
//

#pragma once


class CMy21DatabaseView : public CView
{
protected: // 仅从序列化创建
	CMy21DatabaseView() noexcept;
	DECLARE_DYNCREATE(CMy21DatabaseView)

// 特性
public:
	CMy21DatabaseDoc* GetDocument() const;

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
	virtual ~CMy21DatabaseView();
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

#ifndef _DEBUG  // 21_DatabaseView.cpp 中的调试版本
inline CMy21DatabaseDoc* CMy21DatabaseView::GetDocument() const
   { return reinterpret_cast<CMy21DatabaseDoc*>(m_pDocument); }
#endif

