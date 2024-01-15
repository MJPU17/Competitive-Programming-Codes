#include <iostream>

using namespace std;

int powE(int b,int e){
	int res=1;
	for(int i=0;i<e;i++)res*=b;
	return res;
}
string toBinary(string a){
	string bi="";
	for(char x:a){
		if(x=='o')bi+="1";
		else if(x==' ')bi+="0";
	}
	return bi;
}
int toDecimal(string a){
	int res=0;
	int exp=0;
	for(int i=a.length()-1;i>=0;i--){
		if(a[i]=='1')res+=powE(2,exp);
		exp++;
	}
	return res;
}

int main(int argc, char *argv[]) {
	string c;
	getline(cin,c);
	while(true){
		getline(cin,c);
		if(c[0]=='_')break;
		string binary=toBinary(c);
		int assci=toDecimal(binary);
		cout<<(char)assci;
	}
	return 0;
}
