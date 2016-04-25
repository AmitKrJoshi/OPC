//: C03:ArraySize.cpp
// The return value of the template function
// asz() is a compile-time constant

#include<iostream>
using namespace std;
template<typename T, int size>
int asz(T (&arr)[size]){
	return size;
}

int main() {
	int a[12], b[20];
	const int sz1 = asz(a);
	cout << sz1<<endl;
	const int sz2 = asz(b);
	cout << sz2<<endl;
	//int c[sz1], d[sz2];	//This will not work as asz is a functino not a macro . See Program "ArraySizeUsingTemplate_Enhanced.cpp"
	system("pause");
} ///:~


/*
http://blogs.msdn.com/b/the1/archive/2004/05/07/128242.aspx
C++ treats an array parameter the same as a pointer parameter.

So Def1 and Def2 both are same :
Def1 -> 
template <typename T, size_t N>
size_t countof( T array[N] )
{
    return N;
}
Def2->
template <typename T, size_t N>
size_t countof( T * array )
{
    return N;
}
From Def2 It now becomes obvious that the function body has no way of knowing what N is.

However, if a function expects an array reference, then the compiler does make sure that the size of the actual parameter matches the declaration.
template <typename T, size_t N>
size_t countof( T (&array)[N] )
{
    return N;
}

This countof works very well and you cannot fool it by giving it a pointer.  However, it is a function, not a macro.  This means you cannot use it where a compile time constant is expected.  In particular, you cannot write something like:
	int x[10];
	int y[ 2*countof(x) ]; // twice as big as x

*/