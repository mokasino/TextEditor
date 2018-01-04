//Glyph.h
/*
�� �� �� : Glyph.h
��    �� : Composite���� ������ ���� Component �߻�Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _GLYPH_H
#define _GLYPH_H

#include <string>
using namespace std;
typedef signed long int Long;

class Glyph {
public:
	Glyph();
	Glyph(const Glyph& source);
	virtual ~Glyph() = 0;
	virtual Long Add(Glyph *glyph) { return -1; }
	virtual Long Remove(Long index) { return -1; }
	virtual Glyph* GetAt(Long index) { return 0; }
	virtual Glyph* Clone() = 0;
	virtual string MakeString() = 0;
	virtual Long GetCapacity() const { return 0; }
	virtual Long GetLength() const { return -1; }
};

#endif // !_GLYPH_H