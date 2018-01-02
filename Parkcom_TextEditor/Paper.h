//Paper.h
/*
�� �� �� : Paper.h
��    �� : �� ������ ���� ���� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _PAPER_H
#define _PAPER_H

#include "Composite.h"
#include <string>
using namespace std;
typedef signed long int Long;

class Glyph;

class Paper : public Composite {
public:
	Paper(Long capacity = 10);
	Paper(const Paper& source);
	~Paper();
	Paper& operator = (const Paper& source);
	virtual Glyph* Clone();
	virtual string MakeString();
};

#endif // !_PAPER_H