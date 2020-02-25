
// 20_ArchiveTestView.h: CMy20ArchiveTestView 类的接口
//

#pragma once


class CMy20ArchiveTestView : public CFormView
{
protected: // 仅从序列化创建
	CMy20ArchiveTestView() noexcept;
	DECLARE_DYNCREATE(CMy20ArchiveTestView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY20_ARCHIVETEST_FORM };
#endif

// 特性
public:
	CMy20ArchiveTestDoc* GetDocument() const;

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
	virtual ~CMy20ArchiveTestView();
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
private:
	CButton m_btnPrev;
	CButton m_btnNext;
	CButton m_btnAdd;
	int m_id;
	CString m_name;
	int m_age;
	int m_score;
public:
	afx_msg void OnBnClickedRadioEdit();
	afx_msg void OnBnClickedRadioView();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonPrev();
	afx_msg void OnBnClickedButtonNext();
};

#ifndef _DEBUG  // 20_ArchiveTestView.cpp 中的调试版本
inline CMy20ArchiveTestDoc* CMy20ArchiveTestView::GetDocument() const
   { return reinterpret_cast<CMy20ArchiveTestDoc*>(m_pDocument); }
#endif

