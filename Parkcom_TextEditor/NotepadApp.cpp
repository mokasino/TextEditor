//AppNotepad.cpp

#include "Notepad.h"
#include "NotepadApp.h"

BOOL NotepadApp::InitInstance() {
	Notepad *notepad = new Notepad;

	notepad->Create(NULL, "Notepad"); //CFrameWnd 꺼 갖다쓰는듯??
	notepad->ShowWindow(SW_MAXIMIZE);
	notepad->UpdateWindow();
	this->m_pMainWnd = notepad;

	return TRUE;
}

NotepadApp notepadApp;