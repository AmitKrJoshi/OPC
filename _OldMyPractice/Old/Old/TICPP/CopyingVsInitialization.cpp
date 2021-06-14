#include<iostream>

class Fi{
	Fi(){}
};

class Fee{
public:
	Fee(int){}
	Fee(const Fi&){}
};

int main(){
	Fee fee = 1;	// Fee(int)
	Fi fi;
	Fee fum = fi;	//Fee(Fi);
}