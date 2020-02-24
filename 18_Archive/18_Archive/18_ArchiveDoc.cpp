﻿
// 18_ArchiveDoc.cpp: CMy18ArchiveDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "18_Archive.h"
#endif

#include "18_ArchiveDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy18ArchiveDoc

IMPLEMENT_DYNCREATE(CMy18ArchiveDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy18ArchiveDoc, CDocument)
END_MESSAGE_MAP()


// CMy18ArchiveDoc 构造/析构

CMy18ArchiveDoc::CMy18ArchiveDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CMy18ArchiveDoc::~CMy18ArchiveDoc()
{
}

BOOL CMy18ArchiveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy18ArchiveDoc 序列化

void CMy18ArchiveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// 保存时调用
		CString str = _T("abc");
		int a = 10;

		ar << str << a;
	}
	else
	{
		//加载时调用
		CString str;
		int a;
		ar >> str >> a;
		CString buf;
		buf.Format(TEXT("%s,%d"), str, a);
		AfxMessageBox(buf);

	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy18ArchiveDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMy18ArchiveDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMy18ArchiveDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy18ArchiveDoc 诊断

#ifdef _DEBUG
void CMy18ArchiveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy18ArchiveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy18ArchiveDoc 命令
