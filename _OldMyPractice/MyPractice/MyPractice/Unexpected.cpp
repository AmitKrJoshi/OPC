#include<exception>
#include<stdexcept>	//For runtime_error
#include<iostream>

using namespace std;

class Up : public runtime_error{
public:
	Up(const string& msg="") : runtime_error(msg){}
};

class Fit : public runtime_error{
public:
	Fit(const string& msg="") : runtime_error(msg){}
};

void g();

void f(int i) throw (Up, Fit){
	switch(i){
	case 1: throw Up("Up caught");
	case 2: throw Fit("Fit caught");
	}
	g();
}

//void g(){}   // Uncomment this to see different behaviour
void g(){ throw 47; } 

void my_unexpected(){
	cout << "Unexpected exception thrown\n";
	exit(0);
}

int main(){
	cout << "In main\n";
	set_unexpected(my_unexpected);
	for(int i =1; i<=3; i++)
		try{
			f(i);
		}
		catch(Up& u){
			cout << u.what() << endl;
		}catch(Fit& f){
			cout << f.what() << endl;
		}	
	system("pause");
}