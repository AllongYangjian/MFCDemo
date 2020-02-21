
// 09_WorkView.h: CMy09WorkView 类的接口
//

#pragma once


class CMy09WorkView : public CView
{
protected: // 仅从序列化创建
	CMy09WorkView() noexcept;
	DECLARE_DYNCREATE(CMy09WorkView)

// 特性
public:
	CMy09WorkDoc* GetDocument() const;

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
	virtual ~CMy09WorkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	HICON icon[4];
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRestart();
};

#ifndef _DEBUG  // 09_WorkView.cpp 中的调试版本
inline CMy09WorkDoc* CMy09WorkView::GetDocument() const
   { return reinterpret_cast<CMy09WorkDoc*>(m_pDocument); }
#endif

