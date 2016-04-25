#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

void* operator new(size_t sz){
	//cout << "Operator new: " << sz << " Bytes\n";
	printf("Operator new: %d Bytes\n", sz);
	void * m  = malloc(sz);
	if(!m)
		puts("Out of memory");
	return m;
}

void operator delete(void* m){
	puts("Operator delete");
	free(m);
}

class S{
	int i[100];
public:
	S(){
		puts("S::S()");
	}
	~S(){
		puts("S::~S()");
	}
};

int main(){
	puts("Creating & Destroying a int");
	int* p = new int[4];
	delete p;
	S *s = new S;
	delete s;
	S *sa = new S[10];
	delete []sa;
	system("pause");
}