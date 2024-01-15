#include<iostream>
#include<string>
using namespace std;

int T;
string line;

char result(){
    if(line=="1"||line=="4"||line=="78")return '+';
    if(line[line.length()-1]=='5'&&line[line.length()-2]=='3')return'-';
    if(line[line.length()-1]=='4'&&line[0]=='9')return'*';
    return '?';
}

int main(int argc, char const *argv[]){
    cin>>T;
    while (T--){
        cin>>line;
        cout<<result()<<'\n';
    }
    return 0;
}
