﻿
// 19_ArchiveTestDoc.h: CMy19ArchiveTestDoc 类的接口
//


#pragma once


class CMy19ArchiveTestDoc : public CDocument
{
protected: // 仅从序列化创建
	CMy19ArchiveTestDoc() noexcept;
	DECLARE_DYNCREATE(CMy19ArchiveTestDoc)

// 特性
public:
	CPoint m_pt[200];
	int m_num;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy19ArchiveTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};