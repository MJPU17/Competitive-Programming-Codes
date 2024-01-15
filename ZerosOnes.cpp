#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int N,A,B,T=1;
string line;

bool verify(){
    int mi=min(A,B),ma=max(A,B);
    char c=line[ma];
    for (int i = mi; i < ma; i++){
        if(c!=line[i])return false;
    }
    return true;
}

int main(int argc, char const *argv[]){
    while(getline(cin,line)){
        if(line=="")break;
        cin>>N;
        cout<<"Case "<<T++<<":\n";
        while(N--){
            cin>>A>>B;
            cout<<(verify()?"Yes\n":"No\n");
        }
        cin.ignore();
    }
    return 0;
}
