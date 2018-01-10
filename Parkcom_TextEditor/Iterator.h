//Iterator.h
/*
�� �� �� : Iterator.h
��    �� : �ݺ��� ���� Ŭ����
�� �� �� : ����ȯ
�ۼ����� : 2017-12-27
*/
#ifndef _ITERATOR_H
#define _ITERATOR_H

template <typename T>
class Iterator {
public:
	virtual void First() = 0;
	virtual void Previous() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual T CurrentItem() = 0;
	//virtual void SkipTo() = 0;
	virtual ~Iterator() = 0;
protected:
	Iterator();
};

template <typename T>
Iterator<T>::Iterator() {
}

template <typename T>
Iterator<T>::~Iterator() {
}

#endif // !_ITERATOR_H
