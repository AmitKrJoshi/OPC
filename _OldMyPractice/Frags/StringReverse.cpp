#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define P(s) cout << #s << " -> " << s <<endl;

int main(){
	// The ';' characters will be delimiters
	string s("now.;sense;make;to;going;is;This");
	P(s);
	// To store the words:
	vector<string> strings;
	// The last element of the string:
	int last = s.size();
	P(last);
	// The beginning of the current word:
	int current = s.rfind(';');	
	// Walk backward through the string:
	while(current != string::npos){
		P(current);
		P(last - current);
		// Push each word into the vector. Current is incremented before copying to
		// avoid copying the delimiter.
		P(s.substr(current,last - current));
		strings.push_back(s.substr(++current,last - current));
		for(int j = 0; j < strings.size(); j++)
			cout << j << "->"<<strings[j] << "\n ";
		// Back over the delimiter we just found,
		// and set last to the end of the next word
		current	-= 2;
		P(current);
		last = current+1;
		// Find the next delimiter
		current = s.rfind(';', current);
	}
	// Pick up the first word - it's not preceded by a delimiter
	strings.push_back(s.substr(0, last - current));
	// Print them in the new order:
	for(int j = 0; j < strings.size(); j++)
		cout << j << "->"<<strings[j] << " ";
	system("pause");
}