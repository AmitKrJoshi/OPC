#include<iostream>
using namespace std;

class Value{
	int a, b;
	float c;
public:
	Value(int aa =0, int bb =0, float cc =0) : a(aa), b(bb), c(cc){}
	Value&  operator=(const Value& rv){
		a = rv.a;
		b = rv.b;
		c = rv.c;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Value& val){
		return out << "a = " << val.a << " b = " << val.b << " c = "<< val.c<<endl;
	}
};

int main(){
	Value a, b(1,2,3.5);
	cout << a;
	cout << b;
	a = b;
	cout << "After Assignment\n" << a << endl;
	system("pause");
}
//There is a flaw in this program. We are not checking for Self Assignment before actual assignment
//See CopyingWithPointers.cpp Program