
// TextEditorView.cpp : implementation of the CTextEditorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TextEditor.h"
#endif

#include "TextEditorDoc.h"
#include "TextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextEditorView

IMPLEMENT_DYNCREATE(CTextEditorView, CView)

BEGIN_MESSAGE_MAP(CTextEditorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTextEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTextEditorView construction/destruction

CTextEditorView::CTextEditorView()
{
	// TODO: add construction code here

}

CTextEditorView::~CTextEditorView()
{
}

BOOL CTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTextEditorView drawing

void CTextEditorView::OnDraw(CDC* /*pDC*/)
{
	CTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTextEditorView printing


void CTextEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTextEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTextEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTextEditorView diagnostics

#ifdef _DEBUG
void CTextEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CTextEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextEditorDoc* CTextEditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextEditorDoc)));
	return (CTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextEditorView message handlers
