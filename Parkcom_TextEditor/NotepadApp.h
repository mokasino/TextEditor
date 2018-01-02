//AppNotepad.h
/*
파 일 명 : Notepad.h
기    능 : 프레임 윈도우를 생성하기 위한 클래스
작 성 자 : 조수환
작성일자 : 2017-12-29
*/
#ifndef _NOTEPADAPP_H
#define _NOTEPADAPP_H

#include <afxwin.h>

class NotepadApp : public CWinApp {
public:
	BOOL InitInstance();
};

#endif // _NOTEPADAPP_H