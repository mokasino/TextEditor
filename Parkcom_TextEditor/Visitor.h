//Visitor.h
/*
파 일 명 : Visitor.h
기    능 : 방문자 추상클래스
작 성 자 : 조수환
작성일자 : 2018-1-5
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
