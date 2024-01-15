#include<vector>
#include<string>
#include<iostream>
using namespace std;

typedef vector<int> v;
typedef vector<v> vv;
#define FOR(A,I) for(int I=0;I<A;I++)

int n,x,y;
int dir;
vv mat;
string word;

bool isValid(int x,int y){
    if(x>=0&&y<n)return true;
    return false;
}

void mov(){
    if(dir==0){
        if(isValid(x-1,y))x--;
        if(mat[x][y+1]==-1){
            dir=1;
        }
    }
    else if(dir==1){
        if(isValid(x,y+1))y++;
        if(mat[x+1][y]==-1){
            dir=2;
        }
    }
    else if(dir==2){
        if(isValid(x+1,y))x++;
        if(mat[x][y-1]==-1){
            dir=3;
        }
    }
    else if(dir==3){
        if(isValid(x,y-1))y--;
        if(mat[x-1][y]==-1){
            dir=0;
        }
    }
}

void matrix(){
    FOR(n,i){
        v aux;
        FOR(n,j){
            aux.emplace_back(-1);
        }
        mat.emplace_back(aux);
    }
    x=n/2;
    y=n/2;
    dir=0;
    int k=0;
    FOR(n,i){
        FOR(n,j){
            mat[x][y]=k++;
            mov();
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    cin.ignore();
    matrix();
    getline(cin,word);
    FOR(n,i){
        FOR(n,j){
            if(mat[i][j]<word.length()){
                cout<<word[mat[i][j]];
            }
        }
    }
    cout<<"\n";
    return 0;
}
