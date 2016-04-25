#include "PStash.h"
#include "require.h"
#include <iostream>
#include <cstring>
using namespace std;

int PStash::add(void* element){
	const int inflateSize = 10;
	if(next >= quantity)
		inflate(inflateSize);
	storage[next++] = element;
	return(next-1);
}

// No ownership
PStash::~PStash(){
	for(int i= 0; i< next; i++){
		if(storage[i]!=0){
			cout << "PStash not cleaned up!\n";
		}
		else
			delete []storage;
	}
}

void* PStash::operator[](int index)const{
	require(index>=0, "PStash::operator[] index -ve");
	if(index >= next)
		return 0; // To indicate end
	return storage[index];
}

void* PStash::remove(int index){
	void* v = operator[](index);
	if(v!=0)
		storage[index] = 0;		//Remove the pointer
	return v;
}

void PStash::inflate(int increase){
	const int psz = sizeof(void*);
	cout << "Size of void* :  " << psz << endl;
	void ** st = new void*[quantity + increase];
	memset(st, 0, (quantity+increase)*psz);
	memcpy(st, storage, quantity*psz);
	quantity += increase;
	delete []storage;
	storage = st;
}