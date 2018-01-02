//GlyphFactory.h
/*
파 일 명 : GlyphFactory.h
기    능 : 생성패턴(Class Creational) Factory Method
작 성 자 : 조수환
작성일자 : 2017-12-27
*/
#ifndef _GLYPHFACTORY_H
#define _GLYPHFACTORY_H

typedef unsigned long int ULong;

class Glyph;

class GlyphFactory {
public:
	GlyphFactory();
	GlyphFactory(const GlyphFactory& source);
	virtual ~GlyphFactory();

	virtual Glyph* Create(const char(*characters) = 0);
};

#endif // !_GLYPHFACTORY_H