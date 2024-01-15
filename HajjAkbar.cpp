#include<iostream>
#include<string>

using namespace std;

int i=1;
string line;

int main(int argc, char const *argv[]){
    while(cin>>line,line!="*"){
        if(line=="Hajj")cout<<"Case "<<i++<<": Hajj-e-Akbar\n";
        else cout<<"Case "<<i++<<": Hajj-e-Asghar\n";
    }
    return 0;
}
