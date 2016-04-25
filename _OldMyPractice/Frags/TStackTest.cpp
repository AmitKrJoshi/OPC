#include"TStack.h"
#include<iostream>
#include<fstream>
#include<string>
#include"require.h"
using namespace std;

class X {
public:
	virtual ~X(){
		cout << "~X " << endl;
	}
};

int main(){
	ifstream in("TStackTest.cpp");
	Stack<string> textline;
	string line;
	while(getline(in,line)){
		textline.push(new string (line));
	} 
	string* s;
	for(int i=0; i< 10; i++){
		if((s = (string*) textline.pop()) == 0 )
			break;
		cout << *s << endl;
		delete s;
	}
	Stack<X> xx;
	for(int j =0; j< 10;j++)
		xx.push(new X);

	system("pause");
}