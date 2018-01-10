//Font.cpp

#include "Font.h"
#include <string.h>

Font::Font() {
	this->lf.lfHeight = 11;//-MulDiv(11, GetDeviceCaps(*dc, LOGPIXELSY), 72);
	this->lf.lfWidth = 0;
	this->lf.lfEscapement = 0;
	this->lf.lfOrientation = 0;
	this->lf.lfWeight = FW_NORMAL;
	this->lf.lfItalic = FALSE;
	this->lf.lfUnderline = FALSE;
	this->lf.lfStrikeOut = FALSE;
	this->lf.lfCharSet = DEFAULT_CHARSET;
	this->lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
	this->lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
	this->lf.lfQuality = DEFAULT_QUALITY;
	this->lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy(this->lf.lfFaceName, _T("¹ÙÅÁÃ¼"));
}

Font::Font(LOGFONT _logFont) {
	this->lf = _logFont;
}

Font::Font(string name, Long size, CDC *dc) {
	this->lf.lfHeight = -MulDiv(size, GetDeviceCaps(*dc, LOGPIXELSY), 72);
	this->lf.lfWidth = 0;
	this->lf.lfEscapement = 0;
	this->lf.lfOrientation = 0;
	this->lf.lfWeight = FW_NORMAL;
	this->lf.lfItalic = FALSE;
	this->lf.lfUnderline = FALSE;
	this->lf.lfStrikeOut = FALSE;
	this->lf.lfCharSet = DEFAULT_CHARSET;
	this->lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
	this->lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
	this->lf.lfQuality = DEFAULT_QUALITY;
	this->lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy(this->lf.lfFaceName, _T(name.c_str()));
}

Font::Font(const Font& source) {
}

Font::~Font() {
}

HFONT Font::Create() { 
	return ::CreateFontIndirect(&this->lf);
}