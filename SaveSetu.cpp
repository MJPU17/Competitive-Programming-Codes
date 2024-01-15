#include<iostream>
#include<string>
using namespace std;

int T,money,total=0;
string operation;

int main(int argc, char const *argv[]){
    cin>>T;
    while(T--){
        cin>>operation;
        if(operation=="donate"){
            cin>>money;
            total+=money;
        }
        else cout<<total<<"\n";
    }
    return 0;
}
