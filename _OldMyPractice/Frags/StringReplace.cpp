#include<iostream>
#include<string>
#include<cassert>
using namespace std;

#define P(A) cout << #A << " = " << A <<endl; 


void replaceChars(string&, const string&, const string&);
string& replaceAll(string&, const string&, const string&);

int main(){
	string s ("A piece of test");
	P(s);
	string tag("$tag$");
	P(tag);
	s.insert(8,tag+' ');
	P(s);
	assert(s == "A piece $tag$ of test");
	int start= s.find(tag);
	P(string::npos);
	P(start);
	s.replace(start,tag.size(),"hello there");
	P(s);

	cout << " ---- $$$$ ----\n";
	string bigNews = "I thought I saw elvis in a UFO. I have been working too hard. ";
	string replacement ("wig");
	string findMe("UFO");
	replaceChars(bigNews, findMe, replacement);
	cout << " ---- $$ REPLACE ALL $$ ----\n";
	string text = "a man, a plan, a canal, panama";
	P(text);
	replaceAll(text, "an", "XXX");
	P(text);
	system("pause");
}

void replaceChars(string& modify, const string& find, const string& newS){
	size_t i = modify.find(find,0);
	P(i);
	P(string::npos);
	modify.replace(i,newS.size(),newS);
	P(modify);
}

string& replaceAll(string& modify, const string& from, const string& to){
	P(modify);
	P(from);
	P(to);
	size_t lookHere =0;
	size_t foundHere = 0;
	while((foundHere = modify.find(from,lookHere)) != string::npos){
		modify.replace(foundHere,from.size(),to);
		P(modify);
		P(foundHere);
		lookHere = foundHere + to.size();
	}
	return modify;
}