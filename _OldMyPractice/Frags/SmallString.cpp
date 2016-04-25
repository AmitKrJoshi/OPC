#include<iostream>
#include<string>
#include<cassert>
using namespace std;

#define P(A) cout << #A << " = " << A <<endl; 

#define Q(A) cout << "---- "<< A <<" ----\n";\
	P(bigNews);\
	P(bigNews.size());\
	P(bigNews.capacity());

int main(){
	string s1 = ("This is string s1");
	P(s1);
	string s2 = ("This is string s2");
	P(s2);
	string s3 (s1.begin(), s1.end());
	P(s3);
	string s4 = s1.substr(0,4) + s2.substr(4,3) + s3.substr(7,8) + "s4";
	P(s4);
	string s5 (s1,0,4);
	P(s5);
	assert(s3 == s1);
	
	string ok (5,'a');
	//assert(ok != "aaaaa");

	string bigNews ("I saw Elvis in a UFO");
	P(bigNews);
	cout << "---- How much Data we have actually Got ? ----\n";
	P(bigNews.size());
	cout << "---- How much Can we Store without reallocating ----\n";
	P(bigNews.capacity());
	cout << "---- Insert this string \" thought I\" in bigNews before bigNews[1]\n";
	P(bigNews.insert(1," thought I"));
	Q("Now");
	cout << "---- Appending ----\n";
	bigNews.append(" I've been working very hard");
	Q("New");
	cout << "---- Reserve some cappcity ----\n";
	bigNews.reserve(500);
	Q("Ok");
	system("pause");
}