//Local new and delete overloading

#include<cstddef>
#include<fstream>
#include<iostream>
using namespace std;
ofstream out("Framis.out");

class Framis{
	enum {
		sz = 10
	};
	char c[sz];
	static unsigned char pool[];
	static bool alloc_map[];
public:
	enum {psize = 100 };
	Framis(){ out << "Framis()\n"; }
	~Framis(){ out << "~Framis()\n"; }

	void* operator new(size_t) throw (bad_alloc);
	void operator delete(void*);
};

unsigned char Framis::pool[psize*sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

void* Framis::operator new(size_t) throw(bad_alloc){
	for(int i = 0; i< psize; i++){
		if(!alloc_map[i]){
			out << "Using block " << i << "...";
			alloc_map[i] = true;
			return pool + i*sizeof(Framis);
		}
	}
	out << "Out of Memory\n";
	throw bad_alloc();
}

void Framis::operator delete(void* m){
	if(!m)
		return;

	unsigned long block = (unsigned long)m - (unsigned long)pool;
	block /= sizeof(Framis);
	out << "Freeing Memory " << block << endl;
	alloc_map[block] = false;
}

int main(){
	Framis *fp[Framis::psize];
	try{
		for(int i = 0; i<Framis::psize; i++)
			fp[i] = new Framis;
		new Framis;		// Causes Out of Memory
	}catch(bad_alloc){
		cerr << "Out of Memory\n";
	}
	delete fp[10];
	fp[10] = 0;
	Framis *x = new Framis;
	delete x;
	for(int i =0; i < Framis::psize; i++)
		delete fp[i];
	system("pause");
}