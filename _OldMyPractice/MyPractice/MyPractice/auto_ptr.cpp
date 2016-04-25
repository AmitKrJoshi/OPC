#include<iostream>
#include<memory>
using namespace std;

class TraceHeap{
	int i;
public:
	 void* operator new(size_t sz){
		void *p = ::operator new(sz);
		cout << "Allocating TraceHeap object on the heap at address " << p << endl;
		return p;
	}
	 void operator delete(void *p){
		cout << "DeAllocating TraceHeap object on the heap at address " << p << endl;
		::operator delete(p);
	}
	TraceHeap(int i) : i(i){}
	int getval () const{
		return i;
	}
};

int main(){
	auto_ptr<TraceHeap> pObj(new TraceHeap(5));
	cout << pObj->getval() << endl;
	system("pause");

}