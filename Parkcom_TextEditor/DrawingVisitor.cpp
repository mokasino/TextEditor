//DrawingVisitor.cpp

#include "DrawingVisitor.h"
#include "Glyph.h"
#include "Paper.h"
#include "Row.h"
#include "SmartPointer.h"
#include <afxwin.h>

DrawingVisitor::DrawingVisitor(CDC *dc) {
	this->dc = dc;
}
DrawingVisitor::DrawingVisitor(const DrawingVisitor& drawingVisitor) {
}
DrawingVisitor::~DrawingVisitor() {
}
void DrawingVisitor::Visit(Paper *paper) {
	string str;
	Long i = 0;
	SmartPointer<Glyph*>iterator = paper->CreateIterator();
	for (iterator->First();!iterator->IsDone();iterator->Next()) {
		Glyph *row = iterator->CurrentItem();
		str = row->MakeString();
		dc->TextOut(0, i * MulDiv(32, GetDeviceCaps(*this->dc, LOGPIXELSY), 72), (CString)(str.c_str()));
		i++;
	}
}
void DrawingVisitor::Visit(Row *row) {
	string str = row->MakeString();
	dc->TextOut(0, 0, (CString)(str.c_str()));
}