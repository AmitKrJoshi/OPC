#include <iostream>
#include <string>
using namespace std;

class Dog{
	string nm;
public:
	Dog(const string& name): nm(name){
		cout << "Creating Dog :" << *this << endl;
		cout << *this << endl;
	}
	//Creating Dog From Dog Pointer
	Dog(const Dog* dp, const string& msg) : nm(dp->nm + msg){
		cout << "Copied dog " << *this << " from " << *dp << endl;
	}
	~Dog(){
		cout << "Deleting Dog : " << *this << endl;
	}
	void rename(const string& newName){
		nm = newName;
		cout << "Dog renamed to: " << *this << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& d){
		return os << "[" <<d.nm << "]";
	}
};

class DogHouse{
	Dog* p;
	string houseName;
public:
	DogHouse(Dog * dog, const string house) : p(dog), houseName(house){}
	DogHouse(const DogHouse& dh): p(new Dog(dh.p, "Copy_Ctor")), houseName(dh.houseName + "Copy_Ctor"){}
	DogHouse& operator=(const DogHouse& dh){
		if(&dh != this){
			p = new Dog(dh.p, "Assigned");
			houseName = dh.houseName + "Assigned";
		}
		return *this;
	}
	void renameHouse(const string& newName){
		houseName = newName;
	}
	Dog* getDog() const{
		return p;
	}
	~DogHouse(){
		delete p;
	}
	friend ostream& operator<<(ostream& os, const DogHouse& dh){
		return os << "[" << dh.houseName << "] contains " << *dh.p;
	}
};

int main(){
	DogHouse fidos(new Dog("Fido"), "FidoHouse");
	cout << fidos << endl;
	DogHouse fidos2 = fidos;
	cout << fidos2 << endl;
	fidos2.getDog()->rename("Spot");
	fidos2.renameHouse("SpotHosse");
	cout << fidos2 << endl;
	fidos = fidos2;
	cout << fidos << endl;
	fidos.getDog()->rename("Max");
	fidos2.renameHouse("Max House");
	system("pause");
}

//There is a flaw in this Program.
//In copy ctor and operator= we are making a new copy of what pointer points to and destructor deletes it.
//See Program ReferenceCounting.cpp [You will Learn COW also in this program] To enahance this program