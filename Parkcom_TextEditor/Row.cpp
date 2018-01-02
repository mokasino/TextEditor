//Row.cpp

#include "Row.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include <iostream>
using namespace std;

Row::Row(Long capacity) : Composite(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Row::Row(const Row& source) : Composite(source.capacity) {
	this->glyphs = source.glyphs;
	this->capacity = source.capacity;
	this->length = source.length;
}

Row::~Row() {
}

Glyph* Row::Clone() {
	return new Row(*this);
}

string Row::MakeString() {
	string str("");
	Long i = 0;
	while (i < this->length) {
		str += this->glyphs[i]->MakeString();
		i++;
	}
	return str;
}

Row& Row::operator = (const Row& source) {
	Composite::operator=(source);
	return *this;
}

//int main(int argc, char *argv[]) {
//	Row row;
//	Long i = row.Add(0, SingleByteCharacter('a').Clone());
//	i = row.Add(i + 1, SingleByteCharacter('b').Clone());
//	i=row.Add(i + 1, SingleByteCharacter('c').Clone());
//	i=row.Add(i + 1, SingleByteCharacter('d').Clone());
//	i=row.Add(i + 1, SingleByteCharacter('e').Clone());
//
//	cout << row.GetCapacity() << endl;
//	cout << row.GetLength() << endl;
//	cout << row.MakeString() << endl;
//
//	i = row.Add(i + 1, DoubleByteCharacter("가").Clone());
//	i = row.Add(i + 1, DoubleByteCharacter("나").Clone());
//	i = row.Add(i + 1, DoubleByteCharacter("다").Clone());
//	i = row.Add(i + 1, DoubleByteCharacter("라").Clone());
//	i = row.Add(i + 1, DoubleByteCharacter("마").Clone());
//
//	cout << row.GetCapacity() << endl;
//	cout << row.GetLength() << endl;
//	cout << row.MakeString() << endl;
//}