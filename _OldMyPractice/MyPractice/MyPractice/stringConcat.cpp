#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	char str1[]="I love India";
	char str2[]="Billu Bhanyankar";
	//printf("%c\n",*str2);
	size_t s1 = sizeof(str1)-1;
	size_t s2 = sizeof(str2)-1;
	size_t s3 = s1+s2;
	
	char *str3;
	str3 = (char*)malloc (s1+s2);
	
	memset(str3,0,sizeof(str3));
	int i =0;
	int k =0;
	int j =0;
	bool f1 = true;
	bool f2 = false;
	while(str1[i] != '\0' && str2[j] != '\0'){
		if(f1){
			str3[k] = str1[i];
			k++;
			++i;
			if(str1[i] == ' '){
				f1 = false;
				f2 = true;
				str3[k] = ' ';
				k++;
			}
		}

		if(f2){
			str3[k] = str2[j];
			k++;
			++j;
			if(str2[j] == ' '){
				f1 = true;
				f2 = false;
				str3[k] = ' ';
				k++;
			}
		}
	}
	if(str1[i] != '\0'){
		while(str1[i] != '\0'){
			str3[k] = str1[i];
			k++;
			i++;
		}
	}
	if(str2[j] != '\0'){
		while(str2[j] != '\0'){
			str3[k] = str2[j];
			k++;
			j++;
		}
	}
	str3[k]='\0';
	printf("%s<<%d\n", str3, (str3));
	system("pause");
}
