//Notepad.h
/*
�� �� �� : Notepad.h
��    �� : ȭ�� ��¿� ���� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-29
*/
#ifndef _NOTEPAD_H
#define _NOTEPAD_H

#include <afxwin.h>
using namespace std;

typedef signed long int Long;

class Glyph;
class Notepad : public CFrameWnd {
public:
	Notepad();
private:
	Glyph *paper;
	Glyph *row;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nflags);
	afx_msg LRESULT OnImeChar(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeStartComposition(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};

#endif // _LASTCLASS_H