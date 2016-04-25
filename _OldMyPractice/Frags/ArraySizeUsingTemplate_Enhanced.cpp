#include<iostream>
using namespace std;

template <typename T, size_t N>
char ( &_ArraySize( T (&arr)[N] ))[N];	//Why we are returning char here because char has size 1
				//_ArraySize is a function that returns a reference (note the &) to a char array of 'N' elements
				//	Function Parameter   T (&array)[N]  -> a reference to a T array of N elements.

#define countof(arr) (sizeof( _ArraySize(arr)))

template <typename T, size_t size>
int asz(T (&arr)[size]){
	return size;
}

int main() {
	int a[12], b[20];
	int y[2*countof(a)];	// IMPORTANT : Notice how we are creating a array at compile time
	const int sz1 = asz(a);
	cout << sz1<<endl;
	const int sz2 = asz(b);
	cout << sz2<<endl;
	//int c[sz1], d[sz2];	//This will not work as asz is a functino not a macro . See above 'y' array
	cout << asz(y)<<endl;
	
	system("pause");
}


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

This countof works very well and you cannot fool it by giving it a pointer.  However, it is a function, not a macro.
This means you cannot use it where a compile time constant is expected.  In particular, you cannot write something like:
	int x[10];
	int y[ 2*countof(x) ]; // twice as big as x


BUT --- >>
 it doesn’t work with types defined inside a function.  
 That’s because the template function _ArraySizeHelper expects a type that is accessible in the global scope.
*/