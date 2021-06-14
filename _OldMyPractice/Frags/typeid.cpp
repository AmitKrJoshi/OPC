#include<typeinfo>
#include<iostream>
#include<string>
using namespace std;

template<class T>
void foo(T x){
	cout << typeid(x).name()<<endl;
	string str;
	if((typeid(x).name()) != (typeid(str).name())){
		cout << "Hola\n";
		T temp;
		temp = x*x;
		cout << temp << endl;
	}
	else{
		cout << "Wrong Input\n";
		return;
	}
}

int main(){
	string str = "test";
	foo(str);
	system("pause");
	return 0;
}