//AppNotepad.cpp

#include "Notepad.h"
#include "NotepadApp.h"

BOOL NotepadApp::InitInstance() {
	Notepad *notepad = new Notepad;

	notepad->Create(NULL, "Notepad"); //CFrameWnd �� ���پ��µ�??
	notepad->ShowWindow(SW_MAXIMIZE);
	notepad->UpdateWindow();
	this->m_pMainWnd = notepad;

	return TRUE;
}

NotepadApp notepadApp;