//SmartPointer.h
/*
파 일 명 : SmartPointer.h
기    능 : 반복자 패턴 클래스
작 성 자 : 조수환
작성일자 : 2017-12-27
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
	// _i를 여러 번 삭제하는 것을 방지하기 위해서
	// 복사와 할당을 허용하지 않습니다.
	SmartPointer(const SmartPointer&) {}
	SmartPointer& operator = (const SmartPointer&) {}
private:
	Iterator<T>* _i;
};

#endif // !_SMARTPOINTER_H