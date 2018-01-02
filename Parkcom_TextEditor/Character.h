//Character.h
/*
파 일 명 : Character.h
기    능 : 싱글바이트와 더블바이트를 동시에 갖을 수 있는 추상클래스
작 성 자 : 조수환
작성일자 : 2017-12-26
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
