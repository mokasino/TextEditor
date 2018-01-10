//GlyphIterator.h
/*
파 일 명 : GlyphIterator.h
기    능 : 반복자 패턴 서브클래스
작 성 자 : 조수환
작성일자 : 2017-12-27
*/
#ifndef _GLYPHITERATOR_H
#define _GLYPHITERATOR_H

#include "Iterator.h"
#include "Array.h"

typedef signed long int Long;

template <typename T>
class GlyphIterator :public Iterator<T> {
public:
	GlyphIterator();
	GlyphIterator(Array<T>* aGlyph);
	virtual void First();
	virtual void Previous();
	virtual void Next();
	virtual bool IsDone() const;
	virtual T CurrentItem();
	//virtual void SkipTo();
private:
	Array<T>* _glyph;
	Long _current;
};
template <typename T>
GlyphIterator<T>::GlyphIterator() : _glyph(0), _current(0) {
}
template <typename T>
GlyphIterator<T>::GlyphIterator( Array<T>* aGlyph) : _glyph(aGlyph), _current(0) {
}
template <typename T>
void GlyphIterator<T>::First() {
	_current = 0;
}
template <typename T>
void GlyphIterator<T>::Previous() {
	_current--;
}
template <typename T>
void GlyphIterator<T>::Next() {
	_current++;
}
template <typename T>
bool GlyphIterator<T>::IsDone() const {
	return _current >= this->_glyph->GetLength();
}
template <typename T>
T GlyphIterator<T>::CurrentItem() {
	if (IsDone()) {
		//throw IteratorOutOfBounds;
	}
	return this->_glyph->GetAt(_current);
}

#endif // !_GLYPHITERATOR_H
