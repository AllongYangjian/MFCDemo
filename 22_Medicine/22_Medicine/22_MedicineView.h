
// 22_MedicineView.h: CMy22MedicineView 类的接口
//

#pragma once


class CMy22MedicineView : public CFormView
{
protected: // 仅从序列化创建
	CMy22MedicineView() noexcept;
	DECLARE_DYNCREATE(CMy22MedicineView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY22_MEDICINE_FORM };
#endif

// 特性
public:
	CMy22MedicineDoc* GetDocument() const;

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
	virtual ~CMy22MedicineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 22_MedicineView.cpp 中的调试版本
inline CMy22MedicineDoc* CMy22MedicineView::GetDocument() const
   { return reinterpret_cast<CMy22MedicineDoc*>(m_pDocument); }
#endif

