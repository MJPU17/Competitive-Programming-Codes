#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef vector<char> arr;
typedef vector<vector<char>> matrix;
typedef queue<pair<int,int>> cords;
typedef pair<int,int> pi;
#define FOR(A,I) for(int I=0;I<A;I++)

int R,C;
char aux;
matrix meadow;
cords s,w;
pi cord;

void printMatrix(){
  FOR(R,i){
        FOR(C,j){
            printf("%c", meadow[i][j]);
        }
        printf("\n");
    }  
}

bool isValid(int i,int j){
    if(i>=0&&i<R&&j>=0&&j<C){
        return true;
    }
    return false;
}
bool putDog(int i,int j){
    if(isValid(i,j)){
        if(meadow[i][j]=='S'){
            return false;
        }
        if(meadow[i][j]!='W')meadow[i][j]='D';
    }
    return true;
}

bool solve(){
    if(s.empty()||w.empty()){
        FOR(R,i){
            FOR(C,j){
                if(meadow[i][j]=='.'){
                    meadow[i][j]='D';
                    i=R;
                    break;
                }
            }
        }
    }
    else{
        while(!w.empty()){
            pi v=w.front();
            w.pop();
            int x=v.first;
            int y=v.second;
            if(!putDog(x+1,y)||!putDog(x-1,y)||!putDog(x,y+1)||!putDog(x,y-1))return false;
        }
    }
    return true;
}

void saveCords(int i, int j){
    if(aux=='S'){
        cord.first=i;
        cord.second=j;
        s.push(cord);
    }
    else if(aux=='W'){
         cord.first=i;
        cord.second=j;
        w.push(cord);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n",&R,&C);
    FOR(R,i){
        arr file;
        FOR(C,j){
            scanf("%c",&aux);
            if(aux!='\n'){
                saveCords(i,j);
                file.push_back(aux);
            }
            else j--;
        }
        meadow.push_back(file);
    }
    if(solve()){
        printf("Yes\n");
        printMatrix();
    }
    else{
        printf("No\n");
    }
    return 0;
}
