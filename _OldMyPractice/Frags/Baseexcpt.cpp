#include<iostream>
using namespace std;

class X{
public:
	class Trouble{};
	class Small : public Trouble{};
	class Big : public Trouble{};
	void f(){
		throw Big();
	}
};

int main(){
	X x;
	try{
		x.f();
	}catch(X::Trouble&){
		cout << "Caught Trouble\n";
	}catch(X::Small&){
		cout << "Caught Small\n";
	}catch(X::Big&){
		cout << "Caught Big\n";
	}
	system("pause");
}