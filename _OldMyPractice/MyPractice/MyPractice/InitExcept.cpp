#include<iostream>
using namespace std;

class Base{
	int i;
public:
	class BaseExcept{};
	Base(int i):i(i){
		cout << "Base :: i" << i << endl;
		throw BaseExcept();
	}
};

class Derived : public Base{
public:
	class DerivedExcept{
		const char* msg;
	public:
		DerivedExcept(const char* mesg):msg(mesg){}
		const char* what() const{
			return msg;
		}
	};

	Derived(int j)
		try
		:Base(j){
			cout << "Let's see if this prints\n";
		}
		catch(BaseExcept&){
			throw DerivedExcept("Base subObject threw");
		}
};

int main(){
	try{
		Derived d(3);
	}
	catch(Derived::DerivedExcept& d){
		cout << d.what() << endl;
	}
	system("pause");
}