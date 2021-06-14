#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    stringstream ss("this is a string\n");

    string str(ss.str());

    const char* cstr1 = str.c_str();
	//stringstream.str() returns a temporary string object that's destroyed at the end of the full expression. 
	//If you get a pointer to a C string from that (stringstream.str().c_str()), 
	//it will point to a string which is deleted where the statement ends. 
	//That's why your code prints garbage.
    const char* cstr2 = ss.str().c_str();

    cout << cstr1	// Prints correctly
    	<< cstr2;	// ERROR, prints out garbage

	//Uncomment
	/*cout << cstr1	// Prints correctly
	<< ss.str().c_str()
   	<< cstr2;	// ERROR, prints out garbage
	*/

    system("PAUSE");

    return 0;
}