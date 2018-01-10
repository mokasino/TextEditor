//DrawingVisitor.cpp

#include "DrawingVisitor.h"
#include "Glyph.h"
#include "Paper.h"
#include "Row.h"
#include "Font.h"
#include "SmartPointer.h"
#include <afxwin.h>

DrawingVisitor::DrawingVisitor(CDC *dc, Font *font) {
	this->dc = dc;
	this->font = font;
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
		dc->TextOut(0, i * -this->font->GetLogFont().lfHeight, (CString)(str.c_str()));
		i++;
	}
}
void DrawingVisitor::Visit(Row *row) {
	string str = row->MakeString();
	dc->TextOut(0, 0, (CString)(str.c_str()));
}