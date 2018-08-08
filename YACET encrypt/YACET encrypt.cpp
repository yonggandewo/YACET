#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
string a;
vector<int>n;
int main(){
	srand(time(NULL));
	printf("Plaintext:");
	getline(cin,a);
	ofstream fout("encryption.txt");
	printf("Encryption:");
	for(int i=0;i<a.size();++i){
		n.push_back(rand()%256);
		printf("%02x",n[i]);
		fout<<setfill('0')<<setw(2)<<hex<<n[i];
	}
	fout.close();
	ofstream kout("ciphertext.txt");
	printf("\nCiphertext:");
	for(int i=0;i<a.size();++i){
		printf("%02x",a[i]^n[i]);
		kout<<setfill('0')<<setw(2)<<hex<<(a[i]^n[i]);
	}
	kout.close();
	getchar();
	return 0;
}
