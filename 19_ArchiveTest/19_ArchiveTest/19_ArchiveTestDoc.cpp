
// 19_ArchiveTestDoc.cpp: CMy19ArchiveTestDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "19_ArchiveTest.h"
#endif

#include "19_ArchiveTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy19ArchiveTestDoc

IMPLEMENT_DYNCREATE(CMy19ArchiveTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy19ArchiveTestDoc, CDocument)
END_MESSAGE_MAP()


// CMy19ArchiveTestDoc 构造/析构

CMy19ArchiveTestDoc::CMy19ArchiveTestDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CMy19ArchiveTestDoc::~CMy19ArchiveTestDoc()
{
}

//创建窗口时调用，之后每次新建窗口都会调用
BOOL CMy19ArchiveTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy19ArchiveTestDoc 序列化

void CMy19ArchiveTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_num;
		CString str;
		for (int x = 0; x < m_num; x++)
		{
			ar << m_pt[x];
		}
	}
	else
	{
		ar >> m_num;
		for (int x = 0; x < m_num; x++)
		{
			ar >> m_pt[x];
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy19ArchiveTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy19ArchiveTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMy19ArchiveTestDoc::SetSearchContent(const CString& value)
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

// CMy19ArchiveTestDoc 诊断

#ifdef _DEBUG
void CMy19ArchiveTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy19ArchiveTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy19ArchiveTestDoc 命令

//创建窗口时调用，主要用来释放资源
void CMy19ArchiveTestDoc::DeleteContents()
{
	
	memset(&m_pt, 0, sizeof(m_pt));
	m_num = 0;
	CDocument::DeleteContents();
}
