#ifndef OWNERSTACK_H
#define OWNERSTACK_H

template<class T>
class Stack{
	struct Link{
		T* data;
		Link* next;
		Link(T* dat, Link* nxt) : data(dat), next(nxt)
	}
};
#endif