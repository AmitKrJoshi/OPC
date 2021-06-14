// Taking the address of a function generated
// from a template.
#include<iostream>
using namespace std;

template<typename T>
void f(T*){
	cout <<"1\n";
}

void h(void (*pf)(int*)){
	cout <<"2\n";
}

template<class T>
void g(void (*pf)(T*)){	
	cout <<"3\n";
}

int main(){
	h(&f<int>);
	h(&f);

	g<int>(&f<int>);
	g<int>(&f);
	g(&f<int>);
	//g(&f);
	//'void g(void (__cdecl *)(T *))' : cannot use function template 'void f(T *)' as a function argument
    // 'void g(void (__cdecl *)(T *))' : could not deduce template argument for 'overloaded function type' from 'overloaded function type'

	system("pause");
}