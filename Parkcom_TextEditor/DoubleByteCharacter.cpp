//DoubleByteCharacter.cpp

#include "DoubleByteCharacter.h"

#include <iostream>
using namespace std;

DoubleByteCharacter::DoubleByteCharacter() {
	this->contents[0] = ' ';
	this->contents[1] = ' ';
}

DoubleByteCharacter::DoubleByteCharacter(char (*contents)) {
	this->contents[0] = contents[0];
	this->contents[1] = contents[1];
}

DoubleByteCharacter::DoubleByteCharacter(const DoubleByteCharacter& source) {
	this->contents[0] = source.contents[0];
	this->contents[1] = source.contents[1];
}

DoubleByteCharacter::~DoubleByteCharacter() {
	cout << "DoubleByteCharacter Destructor" << endl;
}

Glyph* DoubleByteCharacter::Clone() {
	return new DoubleByteCharacter(*this);
}

string DoubleByteCharacter::MakeString() {
	char temp[3];
	temp[0] = this->contents[0];
	temp[1] = this->contents[1];
	temp[2] = '\0';
	string str = temp;

	return str;
}

DoubleByteCharacter& DoubleByteCharacter::operator = (const DoubleByteCharacter& source) {
	this->contents[0] = source.contents[0];
	this->contents[1] = source.contents[1];

	return *this;
}

bool DoubleByteCharacter::operator == (const DoubleByteCharacter& source) {
	bool ret = false;
	if (this->contents[0] == source.contents[0] &&
		this->contents[1] == source.contents[1]) {
		ret = true;
	}
	return ret;
}

bool DoubleByteCharacter::operator != (const DoubleByteCharacter& source) {
	bool ret = false;
	if (this->contents[0] != source.contents[0] ||
		this->contents[1] != source.contents[1]) {
		ret = true;
	}
	return ret;
}

//int main(int argc, char* argv[]) {
//	//Default Constructor
//	DoubleByteCharacter a;
//	string str(a.GetContents(),2);
//	cout << str << endl;
//
//	//Constructor parameter1
//	DoubleByteCharacter b("가");
//	string str2(b.GetContents(),2);
//	cout << str2 << endl;
//
//	//MakeString
//	DoubleByteCharacter c("나");
//	string str3 = c.MakeString();
//	cout << str3 << endl;
//
//	//copy Constructor
//	DoubleByteCharacter d(b);
//	string str4(d.GetContents(),2);
//	cout << str4 << endl;
//
//	//Destructor
//	DoubleByteCharacter e("다");
//	string str5(e.GetContents(),2);
//	cout << str5 << endl;
//
//	//치환연산자
//	DoubleByteCharacter f = e;
//	string str6(f.GetContents(),2);
//	cout << str6 << endl;
//}