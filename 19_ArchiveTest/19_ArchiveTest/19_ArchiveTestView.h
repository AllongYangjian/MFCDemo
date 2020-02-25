
// 19_ArchiveTestView.h: CMy19ArchiveTestView 类的接口
//

#pragma once


class CMy19ArchiveTestView : public CView
{
protected: // 仅从序列化创建
	CMy19ArchiveTestView() noexcept;
	DECLARE_DYNCREATE(CMy19ArchiveTestView)

// 特性
public:
	CMy19ArchiveTestDoc* GetDocument() const;

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
	virtual ~CMy19ArchiveTestView();
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 19_ArchiveTestView.cpp 中的调试版本
inline CMy19ArchiveTestDoc* CMy19ArchiveTestView::GetDocument() const
   { return reinterpret_cast<CMy19ArchiveTestDoc*>(m_pDocument); }
#endif

