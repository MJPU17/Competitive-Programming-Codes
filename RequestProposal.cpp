#include<iostream>
#include<string>
using namespace std;

int N,M,C,T=1,maxi;
double P,price;
string line,selected;

int main(int argc, char const *argv[]){
    while(cin>>N>>M, N||M){
        cin.ignore();
        maxi=0;
        price=0;
        for (int i = 0; i < N; i++)getline(cin,line);
        for (int i = 0; i < M; i++){
            getline(cin,line);
            cin>>P>>C;
            if(i==0||C>maxi||(C==maxi&&P<price)){
                selected=line;
                maxi=C;
                price=P;
            }
            cin.ignore();
            for (int j = 0; j < C; j++)getline(cin,line);
        }
        if(T!=1)cout<<'\n';
        cout<<"RFP #"<<T++<<'\n'<<selected<<"\n";
    }
    return 0;
}
