//SingleByteCharacter.h
/*
�� �� �� : SingleByteCharacter.h
��    �� : ����, ��ȣ �� �̱۹���Ʈ�� ���� ó��
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
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