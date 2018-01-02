//Row.h
/*
�� �� �� : Row.h
��    �� : ���ڴ����� ���� ���� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-26
*/
#ifndef _ROW_H
#define _ROW_H

#include "Composite.h"
#include <string>
using namespace std;
typedef signed long int Long;

class Glyph;

class Row : public Composite {
public:
	Row(Long capacity = 100000);
	Row(const Row& source);
	~Row();
	Row& operator = (const Row& source);
	virtual Glyph* Clone();
	virtual string MakeString();
};

#endif // !_ROW_H