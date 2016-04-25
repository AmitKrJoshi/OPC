#include<iostream>
using namespace std;

class Object{
	void *data;
	const int size;
	const char id;
public:
	Object(int sz, char c): size(sz), id(c){
		data = new char[size];
		cout << "Constructing Object " << id << " Size " << size <<endl;
	}
	~Object(){
		cout << "Destructing Object " << id << " Size " << size << endl;
		delete []data;
	}
};

int main(){
	Object* a = new Object(40,'a');
	delete a;
	void *b = new Object(50,'b');
	delete b;
	system("pause");
}