//SingleByteCharacter.cpp

#include "SingleByteCharacter.h"
#include <iostream>
using namespace std;

SingleByteCharacter::SingleByteCharacter() {
	this->content = ' ';
}

SingleByteCharacter::SingleByteCharacter(char content) {
	this->content = content;
}

SingleByteCharacter::SingleByteCharacter(const SingleByteCharacter& source) {
	this->content = source.content;
}

SingleByteCharacter::~SingleByteCharacter() {
	cout << "SingleByteCharacter Destructor" << endl;
}

Glyph* SingleByteCharacter::Clone() {
	return new SingleByteCharacter(*this);
}

string SingleByteCharacter::MakeString() {
	char temp[9];
	if (this->content != '\t') {
		temp[0] = this->content;
		temp[1] = '\0';
	}
	else {
		for (int i = 0;i < 8;i++) {
			temp[i] = ' ';
		}
		temp[8] = '\0';
	}
	string str = temp;

	return str;
}

SingleByteCharacter& SingleByteCharacter::operator = (const SingleByteCharacter& source) {
	this->content = source.content;
	return *this;
}

bool SingleByteCharacter::operator == (const SingleByteCharacter& source) {
	bool ret = false;
	if (this->content == source.content) {
		ret = true;
	}
	return ret;
}

bool SingleByteCharacter::operator != (const SingleByteCharacter& source) {
	bool ret = false;
	if (this->content != source.content) {
		ret = true;
	}
	return ret;
}

//int main(int argc, char* argv[]) {
//	//Default Constructor
//	SingleByteCharacter a;
//	cout << a.GetContent() << endl;
//	
//	//Constructor parameter1
//	SingleByteCharacter b('b');
//	cout << b.GetContent() << endl;
//
//	//MakeString
//	SingleByteCharacter c('c');
//	string str = c.MakeString();
//	cout << str << endl;
//
//	//copy Constructor
//	SingleByteCharacter d(b);
//	cout << d.GetContent() << endl;
//
//	//Destructor
//	SingleByteCharacter e('e');
//	cout << e.GetContent() << endl;
//
//	//치환연산자
//	SingleByteCharacter f = e;
//	cout << f.GetContent() << endl;
//}