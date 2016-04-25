#include<iostream>
using namespace std;

template<class T, int SZ = 1>
class PWrap{
	T* ptr;
public:
	class RangeError{};
	PWrap(){
		ptr = new T[SZ];
		cout << "PWrap Ctor\n";
	}
	~PWrap(){
		delete []ptr;
		cout << "PWrap Dtor\n";
	}
	T& operator[](int i) throw (RangeError){
		if(i>=0 && i < SZ)
			return ptr[i]
		throw RangeError();
	}
};

class Cat{
public:
	Cat(){ cout << "Cat()\n"; }
	~Cat(){ cout << "~Cat()\n"; }
	void g(){}
};

class Dog{
public:
	void* operator new[] (size_t){
		cout << "Allocating a Dog\n";
		throw 47;
	}
	void operator delete[](void* p){
		cout << "Deallocating a Dog\n";
		::operator delete(p);
	}
};

class UseResources{
	PWrap<Cat, 3> cats;
	PWrap<Dog> dog;
public:
	UseResources(){
		cout << "UseResources()\n";
	}
	~UseResources(){
		cout << "~UseResources()\n";
	}
};


int main(){
	try{
		UseResources ur;
	}
	catch(int){
		cout << "In side Handler\n";
	}
	catch(...){
		cout << "Inside catch(...)\n";
	}
	system("pause");
}