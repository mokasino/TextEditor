//SmartPointer.h
/*
�� �� �� : SmartPointer.h
��    �� : �ݺ��� ���� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-27
*/
#ifndef _SMARTPOINTER_H
#define _SMARTPOINTER_H

#include "Iterator.h"

template<typename T>
class SmartPointer {
public:
	SmartPointer(Iterator<T>* i) :_i(i) {}
	~SmartPointer() { delete _i; }
	Iterator<T>* operator->() { return _i; }
	Iterator<T>& operator*() { return *_i; }
private:
	// _i�� ���� �� �����ϴ� ���� �����ϱ� ���ؼ�
	// ����� �Ҵ��� ������� �ʽ��ϴ�.
	SmartPointer(const SmartPointer&) {}
	SmartPointer& operator = (const SmartPointer&) {}
private:
	Iterator<T>* _i;
};

#endif // !_SMARTPOINTER_H