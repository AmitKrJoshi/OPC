#include<iostream>
#include<string>

using namespace std;

#define P(A) cout << #A << " = " << A <<endl;
#define Q(A,B,C) cout << #A <<" = "<< A <<"   "<< #B << " = " <<B<<"   "<< #C <<" = " << C << endl;

int main(){
	string sieveChars(50, 'P');
	P(sieveChars);
	sieveChars.replace(0,2,"NN");//Using 5th From
	P(sieveChars);
	cout << "Current Size " << sieveChars.size() << endl;
	cout << "We need " << (sieveChars.size() / 2 )-1 << endl;
	//Start with 2 and mark all multipls of 2 as not prime and so on
	for(int i =2; i<= (sieveChars.size() / 2 )-1; i++)
		//Find all factors of 2
		for(int factor = 2; factor * i < sieveChars.size(); factor++){
			//Q(i,factor,factor * i);
			sieveChars[factor * i] = 'N';
		}

	P(sieveChars);
	cout << "Prime:" << endl;
	// Return the index of the first 'P' element:
	int j = sieveChars.find('P');
	P(j);
	// While not at the end of the string:
	while(j != sieveChars.npos) {
		// If the element is P, the index is a prime
		cout << j << " ";
		// Move past the last prime
		j++;
		// Find the next prime
		j = sieveChars.find('P', j);
	}
	cout << "\n Not prime:" << endl;
	j = sieveChars.find_first_not_of('P');
	while(j != sieveChars.npos) {
		cout << j << " ";
		j++;
		j = sieveChars.find_first_not_of('P', j);
	}
	system("pause");
}