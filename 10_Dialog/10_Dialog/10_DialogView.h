
// 10_DialogView.h: CMy10DialogView 类的接口
//

#pragma once


class CMy10DialogView : public CView
{
protected: // 仅从序列化创建
	CMy10DialogView() noexcept;
	DECLARE_DYNCREATE(CMy10DialogView)

// 特性
public:
	CMy10DialogDoc* GetDocument() const;

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
	virtual ~CMy10DialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 10_DialogView.cpp 中的调试版本
inline CMy10DialogDoc* CMy10DialogView::GetDocument() const
   { return reinterpret_cast<CMy10DialogDoc*>(m_pDocument); }
#endif

