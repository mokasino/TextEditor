//Font.h
/*
�� �� �� : Font.h
��    �� : ��Ʈ���� ũ�⸦ �Է¹޾� ��Ʈ�� ����� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2018-1-4
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
