//GlyphFactory.cpp

#include "GlyphFactory.h"
#include "Paper.h"
#include "Row.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"
#include <string.h>

GlyphFactory::GlyphFactory() {
}
GlyphFactory::GlyphFactory(const GlyphFactory& source) {
}
GlyphFactory::~GlyphFactory() {
}

#include <iostream>
#include <string>
using namespace std;

Glyph* GlyphFactory::Create(const char (*characters)) {
	Glyph *glyph = 0;
	if (characters == 0) {
		glyph = new Paper;
		cout << "Create Paper" << endl;
	}
	else if (characters[0] == '\r' && characters[1] == '\n') {
		glyph = new Row;
		cout << "Create Row" << endl;
	}
	else if ((*characters & 0x80)) {
		glyph = new DoubleByteCharacter(const_cast<char*>(characters));
		cout << "Create DoubleByteCharacter" << endl;
	}
	else if (!(*characters & 0x80)) {
		glyph = new SingleByteCharacter(characters[0]);
		cout << "Create SingleByteCharacter" << endl;
	}
	return glyph;
}

//int main(int argc, char *argv[]) {
//	GlyphFactory factory;
//	Glyph *paper = factory.Create();
//	Long index = paper->Add(new Row);
//	Glyph *row = paper->GetAt(index);
//	string str = "ParkCom학원입니다.\r\n123";
//	string temp = { 0, };
//
//	Long i = 0;
//	Long j = 0;
//	while (i < 1) {
//		while (j < str.length() && str.at(j) != '\0') {
//			temp = str.at(j);
//			cout << temp.c_str() << endl;
//			row->Add(factory.Create(temp.c_str()));
//			j++;
//		}
//		index = paper->Add(factory.Create(temp.c_str()));
//		row = paper->GetAt(index);
//		i++;
//	}
//	return 0;
//}