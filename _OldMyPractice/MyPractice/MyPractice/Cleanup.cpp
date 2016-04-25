#include<iostream>
using namespace std;

class Trace{
	static int count;
	int objid;
public:
	Trace(){
		objid = count++;
		cout << "Construct Trace #" << objid << endl;
		if(objid == 3)
			throw 3;
	}
	~Trace(){
		cout << "De-Construct Trace #" << objid << endl;
	}
};

int Trace::count = 0;

int main(){
	try{
		Trace t1;
		Trace t2[5];
		Trace t3;
	}catch(int i){
		cout<< "Caught " << i << endl;
	}
	system("pause");
}