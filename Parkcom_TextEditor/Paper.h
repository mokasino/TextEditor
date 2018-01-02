//Paper.h
/*
파 일 명 : Paper.h
기    능 : 줄 단위의 상위 단위 클래스
작 성 자 : 조수환
작성일자 : 2017-12-26
*/
#ifndef _PAPER_H
#define _PAPER_H

#include "Composite.h"
#include <string>
using namespace std;
typedef signed long int Long;

class Glyph;

class Paper : public Composite {
public:
	Paper(Long capacity = 10);
	Paper(const Paper& source);
	~Paper();
	Paper& operator = (const Paper& source);
	virtual Glyph* Clone();
	virtual string MakeString();
};

#endif // !_PAPER_H