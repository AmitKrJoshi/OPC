#include<iostream>

class Number{
	int i;
	
public:
	Number(int i ): i(i){}
	const Number operator+ (const Number& n)const{
		return Number(i + n.i);
	}
};

int main(){
	Number a(47), b(11);
	a + 1;
}