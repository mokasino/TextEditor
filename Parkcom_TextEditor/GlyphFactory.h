//GlyphFactory.h
/*
�� �� �� : GlyphFactory.h
��    �� : ��������(Class Creational) Factory Method
�� �� �� : ����ȯ
�ۼ����� : 2017-12-27
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