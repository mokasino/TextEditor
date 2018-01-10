//DoubleByteCharacter.h
/*
�� �� �� : DoubleByteCharacter.h
��    �� : �ѱ�, Ư������ �� �������Ʈ�� ���� ó��
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _DOUBLEBYTECHARACTER_H
#define _DOUBLEBYTECHARACTER_H

#include "Character.h"
#include <string>

using namespace std;

class DoubleByteCharacter : public Character {
public:
	DoubleByteCharacter();
	DoubleByteCharacter(char (*contents));
	DoubleByteCharacter(const DoubleByteCharacter& source);
	~DoubleByteCharacter();
	DoubleByteCharacter& operator = (const DoubleByteCharacter& source);
	bool operator == (const DoubleByteCharacter& source);
	bool operator != (const DoubleByteCharacter& source);
	virtual Glyph* Clone();
	virtual string MakeString();
	char* GetContents() const;
private:
	char contents[2];
};
inline char* DoubleByteCharacter::GetContents() const {
	return const_cast<char*>(this->contents);
}

#endif // !_DOUBLEBYTECHARACTER_H
