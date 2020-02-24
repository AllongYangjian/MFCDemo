
// 18_ArchiveView.h: CMy18ArchiveView 类的接口
//

#pragma once


class CMy18ArchiveView : public CView
{
protected: // 仅从序列化创建
	CMy18ArchiveView() noexcept;
	DECLARE_DYNCREATE(CMy18ArchiveView)

// 特性
public:
	CMy18ArchiveDoc* GetDocument() const;

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
	virtual ~CMy18ArchiveView();
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

#ifndef _DEBUG  // 18_ArchiveView.cpp 中的调试版本
inline CMy18ArchiveDoc* CMy18ArchiveView::GetDocument() const
   { return reinterpret_cast<CMy18ArchiveDoc*>(m_pDocument); }
#endif

