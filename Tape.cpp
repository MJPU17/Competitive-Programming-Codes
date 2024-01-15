#include<string>
#include<regex>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    int ascii;
    getline(cin,line);
    while(true){
        getline(cin,line);
        if(line=="___________")break;
        line=regex_replace(line,regex("[^o ]"),"");
        line=regex_replace(line,regex("o"),"1");
        line=regex_replace(line,regex(" "),"0");
        ascii=stoi(line,0,2);
        cout<<(char)ascii;
    }
    cout<<"\n";
    return 0;
}
