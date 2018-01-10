//DrawingVisitor.h
/*
파 일 명 : DrawingVisitor.h
기    능 : 방문자클래스를 상속받는 콘크리트 방문자 클래스
작 성 자 : 조수환
작성일자 : 2018-1-8
*/
#ifndef _DRAWINGVISITOR_H
#define _DRAWINGVISITOR_H

#include "Visitor.h"
class CDC;

class DrawingVisitor : public Visitor {
public:
	DrawingVisitor(CDC *dc = 0);
	~DrawingVisitor();
	virtual void Visit(Paper *paper);
	virtual void Visit(Row *row);
protected:
	DrawingVisitor(const DrawingVisitor& drawingVisitor);
	CDC *dc;
};

#endif // !_DRAWINGVISITOR_H
