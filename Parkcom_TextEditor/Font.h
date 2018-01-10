//Font.h
/*
파 일 명 : Font.h
기    능 : 폰트모양과 크기를 입력받아 폰트를 만드는 클래스
작 성 자 : 조수환
작성일자 : 2018-1-4
*/
#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <afxwin.h>

typedef signed long int Long;
using namespace std;

class Font {
public:
	Font();
	Font(LOGFONT lf);
	Font(string name, Long size, CDC *dc);
	Font(const Font& source);
	~Font();
	HFONT Create();
	LOGFONT GetLogFont();
private:
	LOGFONT lf;
};

inline LOGFONT Font::GetLogFont() {
	return this->lf;
}

#endif // !_FONT_H
