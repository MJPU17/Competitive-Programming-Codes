#include<iostream>
#include<utility>
#include<string>
using namespace std;

typedef pair<string,int> psi;

int T,V,m;
string line;
psi urls[10];

int main(int argc, char const *argv[]){
    cin>>T;
    for (int i = 1; i <= T; i++){
        m=0;
        for (int j = 0; j < 10; j++){
            cin>>line>>V;
            urls[j]=psi(line,V);
            if(V>m)m=V;
        }
        cout<<"Case #"<<i<<":\n";
        for (int j = 0; j < 10; j++){
            if(m==urls[j].second)cout<<urls[j].first<<'\n';
        }
    }
    return 0;
}
