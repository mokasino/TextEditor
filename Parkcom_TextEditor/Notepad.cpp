//Notepad.cpp

#include "Notepad.h"
#include "Paper.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include "Row.h"
#include "Character.h"
#include "Composite.h"
#include "Glyph.h"
#include "GlyphFactory.h"
#include "DrawingVisitor.h"
#include "Font.h"
#include <afxdlgs.h>

#define IDM_FONT 10000

BEGIN_MESSAGE_MAP(Notepad, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_CHAR, OnImeChar)
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	ON_MESSAGE(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDM_FONT, OnFontMenuClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

Notepad::Notepad() {
}

void Notepad::Load() {

}

int Notepad::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);

	GlyphFactory glyphFactory;
	this->paper = glyphFactory.Create();
	this->row = glyphFactory.Create("\r\n");
	this->paper->Add(this->row);
	this->isComposition = TRUE;
	this->font = new Font("새굴림", 32, GetDC());
	return 0;
}

void Notepad::OnPaint() {
	CPaintDC dc(this);
	
	HFONT hFont = this->font->Create();
	CFont *cFont;
	cFont = cFont->FromHandle(hFont);
	CFont *oldFont = dc.SelectObject(cFont);
	DrawingVisitor visitor(&dc, this->font);
	this->paper->Accept(&visitor);
	dc.SelectObject(oldFont);
}

void Notepad::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar >= 32 || nChar == VK_RETURN || nChar == VK_TAB) {
		GlyphFactory glyphFactory;
		if (nChar != VK_RETURN) {
			char buffer = nChar;
			Glyph *singleByteCharacter = glyphFactory.Create(&buffer);
			this->row->Add(singleByteCharacter);
		}
		else if (nChar == VK_RETURN) {
			this->row = glyphFactory.Create("\r\n");
			this->paper->Add(this->row);
		}
	}
	Invalidate();
}

LRESULT Notepad::OnImeChar(WPARAM wParam, LPARAM lParam) {
	GlyphFactory glyphFactory;
	char buffer[2] = { 0, };

	if (IsDBCSLeadByte((BYTE)(wParam >> 8)) == TRUE) { //더블바이트 입력 처리
		buffer[0] = HIBYTE(LOWORD(wParam));
		buffer[1] = LOBYTE(LOWORD(wParam));
	}
	else { //스페이스(' ') 입력 처리
		buffer[0] = (char)wParam;
	}
	this->row->Remove(this->row->GetLength() - 1);
	this->row->Add(glyphFactory.Create(buffer));
	this->isComposition = FALSE;
	Invalidate();
	return 0;//::DefWindowProc(this->m_hWnd, WM_IME_CHAR, wParam, lParam);
}

LRESULT Notepad::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	GlyphFactory glyphFactory;
	char buffer[2] = { 0, };
	buffer[0] = HIBYTE(LOWORD(wParam));
	buffer[1] = LOBYTE(LOWORD(wParam));
	if (lParam & GCS_COMPSTR) {
		if (this->row->GetLength() > 0 && this->isComposition == TRUE) {
			this->row->Remove(this->row->GetLength() - 1);
		}
		this->row->Add(glyphFactory.Create(buffer));
		this->isComposition = TRUE;
	}
	Invalidate();
	return ::DefWindowProc(this->m_hWnd, WM_IME_COMPOSITION, wParam, lParam);
}

LRESULT Notepad::OnImeStartComposition(WPARAM wParam, LPARAM lParam) {
	return 0;
}

void Notepad::OnContextMenu(CWnd *pWnd, CPoint cPoint) {
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenu(MF_STRING | MF_ENABLED, IDM_FONT, "글꼴");
	menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, cPoint.x, cPoint.y, this);
	menu.DestroyMenu();
}

void Notepad::OnFontMenuClicked() {
	LOGFONT lf = this->font->GetLogFont();
	CFontDialog dlg(&lf);
	if (dlg.DoModal() == IDOK) {
		if (this->font != NULL) {
			delete this->font;
		}
		dlg.GetCurrentFont(&lf);
		this->font = new Font(lf);
	}
	Invalidate();
}

void Notepad::Save() {

}

void Notepad::OnClose() {
	if (this->font != NULL) {
		delete this->font;
	}
	if (this->paper != NULL) {
		delete this->paper;
	}
	CFrameWnd::OnClose();
}