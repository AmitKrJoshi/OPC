#include "PStash.h"
#include "require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	PStash intStash;
	for(int i= 0; i< 25; i++)
		intStash.add(new int(i));
	for(int j= 0; j< intStash.count(); j++)
		cout << "IntStash[" << j <<"] = " << *(int*)intStash[j]<<endl;
	//CleanUp
	for(int j= 0; j< intStash.count(); j++)
		delete intStash.remove(j);

	ifstream in("PStashTest.cpp");
	assure(in, "PStashTest.cpp");
	PStash stringStash;
	string line;
	while(getline(in, line)){
		stringStash.add(new string(line));
	}
	for(int j= 0; stringStash[j]; j++)
		cout << "StringStash[" << j <<"] = " << *(string*)stringStash[j]<<endl;
	//CleanUp
	for(int j= 0; j< stringStash.count(); j++)
		delete (string*)stringStash.remove(j);
	system("pause");
}