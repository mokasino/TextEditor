//Composite.h
/*
�� �� �� : Composite.h
��    �� : Composite���� ������ ���� Composite �߻�Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "Array.h"
#include "Glyph.h"
#include <string>
using namespace std;
typedef signed long int Long;

class Composite : public Glyph {
public:
	Composite(Long capacity = 100000);
	Composite(const Composite& source);
	virtual ~Composite() = 0;
	Composite& operator = (const Composite& source);
	virtual Long Add(Glyph *glyph);
	virtual Long Remove(Long index);
	virtual Glyph* GetAt(Long index);
	virtual Long GetCapacity() const;
	virtual Long GetLength() const;
protected:
	Array<Glyph*> glyphs;
	Long capacity;
	Long length;
};
inline Long Composite::GetCapacity() const {
	return this->capacity;
}
inline Long Composite::GetLength() const {
	return this->length;
}

#endif // !_COMPOSITE_H