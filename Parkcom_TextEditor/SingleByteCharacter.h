//SingleByteCharacter.h
/*
파 일 명 : SingleByteCharacter.h
기    능 : 영문, 기호 등 싱글바이트에 대한 처리
작 성 자 : 조수환
작성일자 : 2017-12-26
*/
#ifndef _SINGLEBYTECHARACTER_H
#define _SINGLEBYTECHARACTER_H

#include "Character.h"
#include <string>
using namespace std;

class SingleByteCharacter : public Character{
public:
	SingleByteCharacter();
	SingleByteCharacter(char content);
	SingleByteCharacter(const SingleByteCharacter& source);
	~SingleByteCharacter();
	SingleByteCharacter& operator = (const SingleByteCharacter& source);
	bool operator == (const SingleByteCharacter& source);
	bool operator != (const SingleByteCharacter& source);
	virtual Glyph* Clone();
	virtual string MakeString();
	char GetContent() const;
private:
	char content;
};
inline char SingleByteCharacter::GetContent() const {
	return this->content;
}

#endif // !_SINGLEBYTECHARACTER_H