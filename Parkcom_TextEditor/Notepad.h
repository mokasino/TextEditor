//Notepad.h
/*
파 일 명 : Notepad.h
기    능 : 화면 출력에 대한 클래스
작 성 자 : 조수환
작성일자 : 2017-12-29
*/
#ifndef _NOTEPAD_H
#define _NOTEPAD_H

#include <afxwin.h>

typedef signed long int Long;

class Glyph;
class Font;

class Notepad : public CFrameWnd {
public:
	Notepad();
private:
	Glyph *paper;
	Glyph *row;
	BOOL isComposition;
	Font *font;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeChar(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeStartComposition(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnContextMenu(CWnd *pWnd, CPoint cPoint);
	afx_msg void OnFontMenuClicked();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};

#endif // _LASTCLASS_H