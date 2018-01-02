//Composite.cpp

#include "Composite.h"

Composite::Composite() : glyphs(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(Long capacity) : glyphs(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(const Composite& source) 
: glyphs(source.capacity) {
	Long i = 0;
	while (i < source.length) {
		Glyph *glyph = const_cast<Composite&>(source).glyphs.GetAt(i);
		if (glyph != 0) {
			this->glyphs.Modify(i, glyph->Clone());
		}
		i++;
	}
}

Composite::~Composite() {
	Long i = 0;
	while (this->length > 0 && i < this->length) {
		delete this->glyphs[i];
		i++;
	}
}

Long Composite::Add(Glyph *glyph) {
	Long ret = -1;
	if (this->length < this->capacity) {
		ret = this->glyphs.Store(this->length, glyph);
	}
	else {
		ret = this->glyphs.AppendFromRear(glyph);
		this->capacity++;
	}
	this->length++;
	return ret;
}

Glyph* Composite::GetAt(Long index) {
	return this->glyphs[index];
}

Composite& Composite::operator = (const Composite& source) {
	Long i = 0;
	this->glyphs = source.glyphs;
	this->capacity = source.capacity;
	this->length = source.length;
	while (i < source.length) {
		Glyph *glyph = const_cast<Composite&>(source).glyphs.GetAt(i);
		if (glyph != 0) {
			this->glyphs.Modify(i, glyph->Clone());
		}
		i++;
	}
	return *this;
}