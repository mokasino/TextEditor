//Character.h
/*
�� �� �� : Character.h
��    �� : �̱۹���Ʈ�� �������Ʈ�� ���ÿ� ���� �� �ִ� �߻�Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Glyph.h"

class Character : public Glyph{
public:
	Character();
	Character(const Character& source);
	virtual ~Character() = 0;
};

#endif // !_CHARACTER_H
