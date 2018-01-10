//Paper.cpp

#include "Paper.h"
#include "Row.h"
#include "Visitor.h"
#include <iostream>
using namespace std;

Paper::Paper(Long capacity) : Composite(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Paper::Paper(const Paper& source) : Composite(source.capacity) {
	this->glyphs = source.glyphs;
	this->capacity = source.capacity;
	this->length = source.length;
}

Paper::~Paper() {
}

Glyph* Paper::Clone(){
	return new Paper(*this);
}

string Paper::MakeString() {
	string str;
	Long i = 0;
	while (i < this->GetLength()) {
		str += static_cast<Row*>(this->glyphs[i])->MakeString();
		i++;
	}
	return str;
}

void Paper::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

Paper& Paper::operator = (const Paper& source) {
	Composite::operator=(source);
	return *this;
}

//#include "SingleByteCharacter.h"
//#include "DoubleByteCharacter.h"
//int main(int argc, char *argv[]) {
//	Glyph *paper = new Paper;
//	Long index = paper->Add(new Row);
//	Glyph *row = paper->GetAt(index);
//	row->Add(new SingleByteCharacter('a'));
//	row->Add(new SingleByteCharacter('b'));
//	row->Add(new SingleByteCharacter('c'));
//	row->Add(new SingleByteCharacter('d'));
//	row->Add(new SingleByteCharacter('e'));
//	row->Add(new DoubleByteCharacter("가"));
//	row->Add(new DoubleByteCharacter("나"));
//	row->Add(new DoubleByteCharacter("다"));
//	row->Add(new DoubleByteCharacter("라"));
//	row->Add(new DoubleByteCharacter("마"));
//
//
//	cout << paper->GetCapacity() << endl;
//	cout << paper->GetLength() << endl;
//	cout << paper->MakeString() << endl;
//
//	if (paper != 0) {
//		delete paper;
//	}
//
//	return 0;
//}