#include <algorithm>
#include <cstddef>  //For size_t
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "**********Copying Ints Start**********\n";
	int a[] = {10, 20, 30};
	const size_t SIZE = sizeof a / sizeof a[0];
	int b[SIZE];
	copy(a, a+SIZE , b);
	for(int i=0; i< SIZE; i++)
		cout << b[i] << endl;
	for(int i=0; i< SIZE; i++)
		assert(a[i] == b[i]);
	cout << "**********Copying Ints Done**********\n";
	cout << "********Copying Strings Start********\n";
	string str_a[] = {"read", "my", "lips"};
	const size_t SIZE_S = sizeof str_a / sizeof str_a[0];
	string str_b[SIZE_S];
	copy(str_a, str_a + SIZE_S, str_b);
	for(int i=0; i< SIZE_S; i++)
		cout << str_b[i] << endl;
	assert(equal(str_a, str_a + SIZE_S, str_b));
	cout << "********Copying Strings Done*********\n";
	system("pause");
}