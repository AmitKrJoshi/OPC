#include<exception>
#include<iostream>
#include<cstdlib>
using namespace std;

void terminator(){
	cout << "I'll be Back !\n";
	exit(0);
}

void (*old_terminator)() = set_terminate(terminate);

class Botch{
public:
	class Fruit{};
	void f(){
		cout << "Botch::f()\n";
		throw Fruit();
	}
	~Botch(){
		cout << "~Botch\n";
		throw 'c';
	}
};

int main(){
	try{
		Botch b;
		b.f();
	}catch(...){
		cout << "Inside Catch\n";
	}
	//system("pause");
}