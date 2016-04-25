#include<exception>
#include<iostream>
#include<cstdio>
using namespace std;

//Exception Class
class A{};
class B{};

//Own version of Terminate handler
void my_terminate(){
	cout << "Terminate called\n";
}

void my_unexpected(){
	cout << "unexpected called\n";
	throw A();
}

void my_unexpected_2(){
	cout << "Don't throw anything\n";
	throw ;
}

void t(){
	throw B();
}

void f() throw(A){
	//throw A();
	t();
}

int main(){
	set_terminate(my_terminate);
	set_unexpected(my_unexpected);
	try{
		f();
	}
	catch(A&){
		cout << "Caught A\n";
	}
	
	system("pause");
}