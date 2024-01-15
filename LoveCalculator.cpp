#include<iostream>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;

string name1,name2;
unordered_map<char,int> vals;

int numberLengt(int n,int cont){
    if(n==0) return cont;
    return numberLengt(n/10,cont+1);
}

int digitSum(int n){
    int length=numberLengt(n,0);
    if(length==1||length==0)return n;
    int sum=0;
    for (int i = 0; i < length; i++){
        sum+=((n/(int)pow(10,i))%10);
    }
    return digitSum(sum);
}

double solve(){
    int sn1=0,sn2=0;
    for (int i = 0; i < name1.length(); i++){
        if(vals.count(name1[i]))sn1+=vals[name1[i]];
    }
    for (int i = 0; i < name2.length(); i++){
        if(vals.count(name2[i]))sn2+=vals[name2[i]];
    }
    int A=digitSum(sn1),B=digitSum(sn2);
    return (double)min(A,B)/max(A,B);
}

int main(int argc, char const *argv[]){
    for(int i=1,j=65,k=97;i<=26;i++,j++,k++)vals[((char)j)]=vals[((char)k)]=i;
    while(getline(cin,name1)){
        getline(cin,name2);
        printf("%.2f %\n",solve()*100);
    }
    return 0;
}
