#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;
string one;
string two;
vector<string> parts;

void divideParts(string line){
    int init=0,fin=0;
    string part1=line.substr(1,line.find('>')-1);
    parts.emplace_back(part1);
    init=line.find('>')+1;
    fin=line.rfind('<');
    string part2=line.substr(init,fin-init);
    parts.emplace_back(part2);
    init=line.rfind('<')+1;
    fin=line.rfind('>');
    string part3=line.substr(init,fin-init);
    parts.emplace_back(part3);
    string part4=line.substr(line.rfind(">")+1);
    parts.emplace_back(part4);
}

int main(int argc, char const *argv[]){

    cin>>N;
    cin.ignore();
    for (int i = 0; i < N; i++){
       getline(cin,one);
       getline(cin,two);
       divideParts(one.substr(one.find('<')));
       one=one.substr(0,one.find('<'));
       two=two.substr(0,two.find('.'));
       cout<<one+parts[0]+parts[1]+parts[2]+parts[3]<<"\n";
       cout<<two+parts[2]+parts[1]+parts[0]+parts[3]<<"\n";
       parts.clear();
    }
    return 0;
}
