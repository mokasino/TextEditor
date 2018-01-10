//Visitor.h
/*
�� �� �� : Visitor.h
��    �� : �湮�� �߻�Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2018-1-5
*/
#ifndef _VISITOR_H
#define _VISITOR_H

class Paper;
class Row;

class Visitor {
public:
	virtual ~Visitor() = 0;
	virtual void Visit(Paper *paper) {}
	virtual void Visit(Row *row) {}
protected:
	Visitor();
	Visitor(const Visitor& visitor);
};

#endif // !_VISITOR_H
