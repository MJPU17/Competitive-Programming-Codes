#include<iostream>
#include<string>
using namespace std;

int T;
string url;

int main(int argc, char const *argv[]){
    cin>>T;
    for (int i = 1; i <= T; i++){
        cin>>url;
        if(url[4]!='s')url=url.substr(0,4)+"s"+url.substr(4);
        cout<<"Case "<<i<<": "<<url<<"\n";
    }    
    return 0;
}
