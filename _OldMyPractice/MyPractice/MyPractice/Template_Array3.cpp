#include<iostream>
using namespace std;

template<class T, int size = 20>
class Array{
	T arr[size];
public:
	T& operator[](int index){
		if(index < 0 || index > size){
			cout << "Index size is wrong\n";
			exit(0x02);
		}
		return arr[index];
	}
	int length(){
		return size;
	}
};

template <class T, int size=20>
class Holder{
	Array<T,size>* np;
public:
	Holder():np(0){}
	~Holder(){
		delete np;
	}
	T& operator[](int index){
		if(index < 0 || index > size){
			cout << "Index size is wrong\n";
			exit(0x02);
		}
		if(!np)
			np = new Array<T, size>;
		return np->operator[](index);	
	}
	int length(){
		return size;
	}
};

class Number{
	float f;
public:
	Number(float ff = 0.0f): f(ff){}
	Number& operator= (const Number& nm){
		f = nm.f;
		return *this;
	}
	operator float() const {
		return f;
	}

	friend ostream& operator<< (ostream& os, const Number& x){
		return os << x.f;
	}
};

template <class T, int size = 20>
class HoldNum{
	Array<T, size> *np;
public:
	HoldNum():np(0){}
	~HoldNum(){
		delete np;
	}
	T& operator[](int index){
		if(index < 0 || index > size){
			cout << "Index size is wrong\n";
			exit(0x02);
		}
		if(!np){
			np = new Array<T, size>;
		}
		return np->operator[](index);
	}
	int length(){
		return size;
	}
};

int main(){
	Holder<int> h;
	for(int i = 0 ; i < 20; i++)
		h[i] = i;
	for(int i = 0; i < 20; i++)
		cout << h[i] << endl;

	HoldNum<Number> num;
	for(int i = 0 ; i < 20; i++)
		num[i] = (float)i;
	for(int i = 0; i < 20; i++)
		cout << num[i] << endl;
	system("pause");
}