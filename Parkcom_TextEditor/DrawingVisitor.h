//DrawingVisitor.h
/*
�� �� �� : DrawingVisitor.h
��    �� : �湮��Ŭ������ ��ӹ޴� ��ũ��Ʈ �湮�� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2018-1-8
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
