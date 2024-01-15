#include<iostream>
#include<string>
#include<vector>
using namespace std;

int T,N,aux,pos;
string line;
vector<string> ins;

int main(int argc, char const *argv[]){
    cin>>T;
    while (T--){
        cin>>N;
        pos=0;
        while (N--){
            cin>>line;
            if(line=="SAME"){
                cin>>line;
                cin>>aux;
                line=ins[aux-1];
            }
            if(line=="LEFT")pos--;
            else pos++;
            ins.emplace_back(line);
        }
        cout<<pos<<'\n'; 
        ins.clear();
    }
    return 0;
}
