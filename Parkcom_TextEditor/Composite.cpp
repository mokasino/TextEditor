//Composite.cpp

#include "Composite.h"

Composite::Composite(Long capacity) : glyphs(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(const Composite& source) 
: glyphs(source.capacity) {
	this->glyphs = source.glyphs;
	this->capacity = source.capacity;
	Long i = 0;
	while (i < source.length) {
		Glyph *glyph = const_cast<Composite&>(source).glyphs.GetAt(i);
		if (glyph != 0) {
			this->glyphs.Modify(i, glyph->Clone());
		}
		i++;
	}
	this->length = source.length;
}

Composite::~Composite() {
	Long i = 0;
	while (this->length > 0 && i < this->length) {
		delete this->glyphs[i];
		i++;
	}
	this->length = 0;
}

Long Composite::Add(Glyph *glyph) {
	Long index = -1;
	if (this->length < this->capacity) {
		index = this->glyphs.Store(this->length, glyph);
	}
	else {
		index = this->glyphs.AppendFromRear(glyph);
		this->capacity++;
	}
	this->length++;
	return index;
}

Long Composite::Remove(Long index) {
	if (this->glyphs[index] != 0) {
		delete this->glyphs[index];
		this->length--;
	}
	return -1;
}

Glyph* Composite::GetAt(Long index) {
	return this->glyphs[index];
}

GlyphIterator<Glyph*>* Composite::CreateIterator() {
	return new GlyphIterator<Glyph*>(&this->glyphs);
}

Composite& Composite::operator = (const Composite& source) {
	Long i = 0;
	this->glyphs = source.glyphs;
	this->capacity = source.capacity;
	while (i < source.length) {
		Glyph *glyph = const_cast<Composite&>(source).glyphs.GetAt(i);
		if (glyph != 0) {
			this->glyphs.Modify(i, glyph->Clone());
		}
		i++;
	}
	this->length = source.length;
	return *this;
}