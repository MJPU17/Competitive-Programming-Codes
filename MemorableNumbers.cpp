#include<iostream>
#include<string>
#include<utility>
#include<unordered_map>
#include<map>
using namespace std;

typedef unordered_map<char,char> mapss;
typedef map<string,int> mapsi;

int T,N;
bool enter;
string aux,num;
mapss letters;
mapsi all;

void init(){
    letters['A']='2';letters['B']='2';letters['C']='2';
    letters['D']='3';letters['E']='3';letters['F']='3';
    letters['G']='4';letters['H']='4';letters['I']='4';
    letters['J']='5';letters['K']='5';letters['L']='5';
    letters['M']='6';letters['N']='6';letters['O']='6';
    letters['P']='7';letters['R']='7';letters['S']='7';
    letters['T']='8';letters['U']='8';letters['V']='8';
    letters['W']='9';letters['X']='9';letters['Y']='9';
}

string number(string line){
    string newLine="";
    for(int i=0;i<line.length();i++){
        if(line[i]!='-'){
            if(letters.count(line[i])){
                newLine+=letters[line[i]];    
                continue;            
            }
            newLine+=line[i];
        }
    }
    newLine=newLine.substr(0,3)+"-"+newLine.substr(3,4);
    return newLine;
}

int main(int argc, char const *argv[])
{
    init();
    cin>>T;
    for (int i = 0; i < T; i++){
        enter=false;
        cin>>N;
        for (int j = 0; j < N; j++){
            cin>>aux;
            num=number(aux);
            if(all.count(num))all[num]=all[num]+1;
            else all[num]=1;
        }
        for(pair<string,int> cur : all){
            if(cur.second>1){
                cout<<cur.first<<" "<<cur.second<<"\n";
                enter=true;
            }
        }
        if(!enter){
            cout<<"No duplicates.\n";
        }
        if(i!=T-1){
            cout<<"\n";
        }
        all.clear();             
    }
    return 0;
}
