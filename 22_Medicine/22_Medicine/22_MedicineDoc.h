
// 22_MedicineDoc.h: CMy22MedicineDoc 类的接口
//


#pragma once
#include "MedicSet.h"
#include "UserSet.h"
#include "CUser.h"

class CMy22MedicineDoc : public CDocument
{
private:
	CMedicSet m_set;
	CUserSet m_userSet;
	CUser m_user;
protected: // 仅从序列化创建
	CMy22MedicineDoc() noexcept;
	DECLARE_DYNCREATE(CMy22MedicineDoc)

// 特性
public:
	CMedicSet* GetMedicSet()
	{
		return &m_set;
	}
	
	CUserSet* GetUserSet()
	{
		return &m_userSet;
	}

	CUser* GetUser()
	{
		return &m_user;
	}

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
	virtual ~CMy22MedicineDoc();
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
};
