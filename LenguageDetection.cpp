#include<iostream>
#include<string>
using namespace std;

string line;
int i=1;

string lenguage(){
    if(line=="HELLO")return "ENGLISH\n";
    if(line=="HOLA")return "SPANISH\n";
    if(line=="HALLO")return "GERMAN\n";
    if(line=="BONJOUR")return "FRENCH\n";
    if(line=="CIAO")return "ITALIAN\n";
    if(line=="ZDRAVSTVUJTE")return "RUSSIAN\n";
    return "UNKNOWN\n";
}

int main(int argc, char const *argv[]){
    while(cin>>line,line!="#")cout<<"Case "<<i++<<": "<<lenguage();
    return 0;
}
