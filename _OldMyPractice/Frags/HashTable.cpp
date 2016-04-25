#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main(){
	unordered_map<string,string> hashtable;
	//hashtable.emplace("1st Example","1024");
	hashtable.insert(make_pair("www.newark.com", "184.51.50.121"));
	cout << "Ist Examaple code no " << hashtable["www.newark.com"]<<endl;

	for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++)
	{
		cout << (*itr).first << ": " << (*itr).second << endl;
	}

	for (auto &itr : hashtable)
	{
		cout << itr.first << ": " << itr.second << endl;
	}
	system("pause");
	return 0;
}