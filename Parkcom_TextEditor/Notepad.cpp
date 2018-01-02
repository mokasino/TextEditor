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

using namespace std;

BEGIN_MESSAGE_MAP(Notepad, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_CHAR, OnImeChar)
	//ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	ON_MESSAGE(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

Notepad::Notepad() {
}

int Notepad::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct); //코드재사용 오버라이딩 //상속에서

	GlyphFactory glyphFactory;
	this->paper = glyphFactory.Create();
	this->row = glyphFactory.Create("\r\n");
	this->paper->Add(this->row);

	return 0;
}

void Notepad::OnPaint() {
	CPaintDC cdc(this);

	Long rows = this->paper->GetLength();
	Long i = 0;
	while (rows > 0 && i < rows) {
		Glyph *row = this->paper->GetAt(i);
		string str = row->MakeString();
		cdc.TextOut(0, i*25, (CString)(str.c_str()));
		i++;
	}
}

void Notepad::OnChar(UINT nChar, UINT nRepCnt, UINT nflags) {
	if (nChar >= 32 || nChar == VK_BACK || nChar == VK_RETURN || nChar == VK_TAB) {
		GlyphFactory glyphFactory;
		if (nChar != VK_RETURN) {
			char buffer = nChar;
			Glyph *single = glyphFactory.Create(&buffer);
			this->row->Add(single);
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

	if (IsDBCSLeadByte((BYTE)(wParam >> 8)) == TRUE) { // 더블바이트 입력 처리
		buffer[0] = HIBYTE(LOWORD(wParam));
		buffer[1] = LOBYTE(LOWORD(wParam));
	}
	else { // 스페이스 입력 처리
		buffer[0] = (char)wParam;
	}

	this->paper->GetAt(0)->Add(glyphFactory.Create(buffer));
	Invalidate();
	return 0;//::DefWindowProc(this->m_hWnd, WM_IME_CHAR, wParam, lParam);
}

LRESULT Notepad::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	/*if (lParam & GCS_COMPSTR) {
		GlyphFactory glyphFactory;
		HIMC hImc = ImmGetContext(GetSafeHwnd());
		char buffer[2] = { 0, };
		Long nLength = ImmGetCompositionString(hImc, GCS_RESULTSTR, NULL, 0);
		if (nLength > 0) {
			ImmGetCompositionString(hImc, GCS_RESULTSTR, buffer, nLength);
			this->paper->GetAt(0)->Add(glyphFactory.Create(buffer));
		}
		ImmReleaseContext(GetSafeHwnd(), hImc);
	}
	Invalidate();*/
	return ::DefWindowProc(this->m_hWnd, WM_IME_CHAR, wParam, lParam);
}

LRESULT Notepad::OnImeStartComposition(WPARAM wParam, LPARAM lParam) {
	return 0;
}

void Notepad::OnClose() {
	if (this->paper != NULL) {
		delete this->paper;
	}
	CFrameWnd::OnClose();
}