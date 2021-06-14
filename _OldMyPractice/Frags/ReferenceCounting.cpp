#include<iostream>
#include <string>
using namespace std;

class Dog{
	string nm;
	int refCount;
	Dog(const string& name) : nm(name), refCount(1){
		cout << "Creating Dog Object: " <<*this << endl;
	}
	//Prevent Assignment
	Dog& operator= (const Dog& rv);
public:
	//Creating Dog on the heap
	static Dog* make(const string& name){
		return new Dog(name);
	}
	Dog(const Dog& d): nm(d.nm + " copy_ctor"), refCount(1){
		cout << "Dog copy_ctor: " << *this << endl;
	}
	~Dog(){
		cout << "Deleting Dog : " << *this << endl;
	}
	void attach(){
		++refCount;
		cout << "Attach Dog: " << *this << endl;
	}
	void detach(){
		if(refCount != 0){
			cout<< "Detaching Dog: " << *this << endl;
			//We will destroy obj if no one is using it
			if(--refCount == 0)
				delete this;
		}
	}
	// Conditionally Copy
	// Have to call this function before doing any modification on the Dog.
	// Assign the resuting pointer to Dog
	// Unalias : To prevent the modificatin of a Aliased Dog
	// Aliased Dog : A Dog with more than one 'DogHouse' obj pointing to it.
	Dog* unalias(){
		cout << "Unaliassing Dog : " << *this << endl;
		//if not aliased [refCount = 1] Do not duplicate
		if(refCount == 1)
			return this;
		//else decrease the reference count and duplicate the Dog
		--refCount;
		return new Dog(*this);
	}
	void rename(const string& newName){
		nm = newName;
		cout << "Dog renamed to : " << *this << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& d){
		os << "[" << d.nm << "], refCount = " << d.refCount;
		return os;
	}
};

class DogHouse{
	Dog *p;
	string houseName;
public:
	DogHouse(Dog * pDog, const string& house) : p(pDog), houseName(house){
		cout << "Created DogHouse : " << *this << endl;
	}
	// Copy ctor instead of creating it's own memory, assigns Dog to the Dog of THE SOURCE Obj.
	// Than, because there is a now an additional object using that block of memory, 
	// We will increment the refCount by callinng attach()
	DogHouse(const DogHouse& dh): p(dh.p), houseName(dh.houseName + " copy_ctor"){
		p->attach();
		cout << "DogHouse copy_Ctor: " << *this << endl;
	}
	// operator = is dealing with an object that has alreadt been created on the left side
	// of the =, so we must first clean that up by calling detach() for that Dog, which will
	// destroy the old Dog IF no one is using it.  
	DogHouse& operator=(const DogHouse& dh){
		//First always Check for self assignment
		if(&dh != this){
			houseName = dh.houseName + " Assigned";
			// Now clean up first what we are using
			p->detach();
			p = dh.p;
			p->attach();
		}
		cout << "DogHouse operator = : " << *this << endl;
		return *this;
	}
	// Decrement refCout, Conditionally destroy
	~DogHouse(){
		cout << "DogHouse D_tor : " << *this << endl;
		p->detach();
	}
	void renameHouse(const string& newName){
		houseName = newName;
	}
	void unalias(){
		p = p->unalias();
	}

	// COW
	// Anytime we modify the contents of the Pointer, we must first unalias it...
	void renameDog(const string& newName){
		unalias();
		p->rename(newName);
	}
	// ... OR if we allow someone else access
	Dog* getDog(){
		unalias();
		return p;
	}
	friend ostream& operator<< (ostream& os, const DogHouse& dh){
		return os << "[" << dh.houseName << "] contains " << *dh.p; 
	}
};



int main(){
	DogHouse fidos (Dog::make("Fido"), "Fido_House"),  spots(Dog::make("Spot"), "Spot_House");
	cout << "Entering Copy_Ctor\n";
	DogHouse bobs (fidos);
	cout << " After copy ctor bobs\n";
	cout << " fidos: " << fidos << endl;
	cout << " spots: " << spots << endl;
	cout << " bobs: " << bobs << endl;
	cout << " Entering spots = fidos\n";
	spots = fidos;
	cout << " After spots = fidos\n";
	cout << " spots: " << spots << endl;
	cout << " Entering Self Assignment\n";
	bobs = bobs;
	cout << " After Self Assignment\n";
	cout << " bobs: " << bobs << endl;
	cout << " Entering rename(\"Bob\")" << endl;
	bobs.getDog()->rename("Bob");
	cout << " After rename(\"Bob\")" << endl;
	cout << " bobs: " << bobs << endl;
	system("pause");
}