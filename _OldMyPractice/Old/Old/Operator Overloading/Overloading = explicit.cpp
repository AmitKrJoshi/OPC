/*
Assignment operators, must be members function. It can not be friend function

1. Bcoz For those operators that can be declared as standalone functions, 
declaring both member version and standalone version leads to ambiguity.
I.e.  If the assignment happens outside of the class scope, then there would be ambiguity and the compiler would fail.

2. Because the default operator= provided by the compiler would always take precedence.
I.e. your friend operator= would never be called.
I.e. If the assignment was performed inside a class method, because of the lookup rules, the member function (in this case generated by the compiler)
would take precedence and hide the namespace scope operator=
*/
#include"header.h"

class num{
	private:
		int x;
	public:
		num(int x);
		void show();
		void operator = (num obj);
};

num::num(int a){
	x = a ;	
	
}

void num::show(){
	cout << " = " <<x<<endl;
}

void num::operator = (num objA){
	x = objA.x;
}

void main(){
	num A(2),B(3);
	cout << "Before overloading = operator : ";
	cout << "\n A=";
	A.show();
	cout << "\n B=";
	B.show();
	cout << "\n******************\n";
	cout << "After EXPLICIT overloading = operator : ";
	//B = A;			//IMPLICIT CALL
	B.operator=(A);		//EXPLICIT CALL
	cout << "\n A=";
	A.show();
	cout << "\n B=";
	B.show();
	cout << "\n******************\n";
	A = 9;
	B = 7;
	cout << "\n A=";
	A.show();
	cout << "\n B=";
	B.show();
	cout << "\n******************\n";
	system("pause");
}