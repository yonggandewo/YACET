#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
using namespace std;
string cip,enc;
char x,y;
int Name(char a){
	if(isdigit(a))return a-48;
	else return a-87;
}
int main(){
	printf("Ciphertext:");
	getline(cin,cip);
	printf("Encryption:");
	getline(cin,enc);
	if(cip.size()&1||enc.size()&1||cip.size()!=enc.size()){
		printf("ERROR: Illegal Ciphertext and Encryption");
		getchar();
		return 0;
	}
	for(int i=0;i<cip.size();++i){
		if(!isdigit(cip[i])&&!(cip[i]>96&&cip[i]<103)){
			printf("ERROR: Illegal Ciphertext and Encryption");
			getchar();
			return 0;
		}
		if(!isdigit(enc[i])&&!(enc[i]>96&&enc[i]<103)){
			printf("ERROR: Illegal Ciphertext and Encryption");
			getchar();
			return 0;
		}
	}
	ofstream fout("Plaintext.txt");
	for(int i=0;i<cip.size();i+=2){
		x=Name(cip[i])*16+Name(cip[i+1]);
		y=Name(enc[i])*16+Name(enc[i+1]);
		putchar(x^y);
		fout<<(char)(x^y);
	}
	fout.close();
	return 0;
}
