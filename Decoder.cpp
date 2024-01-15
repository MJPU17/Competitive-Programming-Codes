#include<iostream>
#include<string>
using namespace std;

string line;

int main(int argc, char const *argv[])
{
    while(getline(cin,line)){
        for(int i=0;i<line.length();i++){
            cout<<(char)(((int)line[i])-7);
        }
        cout<<"\n";
    }
    return 0;
}
