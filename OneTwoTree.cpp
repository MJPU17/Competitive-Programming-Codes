#include<iostream>
#include<string>
using namespace std;

int T;
string line;

void solve(){
    if(line.length()==5)printf("3\n");
    else if((line[0]=='o'&&line[1]=='n')||(line[0]=='o'&&line[2]=='e')||(line[1]=='n'&&line[2]=='e'))printf("1\n");
    else printf("2\n");
}

int main(int argc, char const *argv[]){
    cin>>T;
    while (T--){
        cin>>line;
        solve();
    }
    return 0;
}
