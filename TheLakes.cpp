#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> v;
typedef vector<v> vv;
#define FOR(A,i) for (int i=0;i<A;i++)

int N,M,prof;
int movex[4]= {0,0,1,-1};
int movey[4]= {-1,1,0,0};
vv lake,dis;

bool isValid(int i,int j){
    if(i>=0&&i<N&&j>=0&&j<M){
        return true;
    }
    return false;
}

void dfs(int i,int j){
    FOR(4,k){
        int x=i+movex[k],y=j+movey[k];
        if(isValid(x,y)){
            if(lake[x][y]!=0&&dis[x][y]==0){
                dis[x][y]=1;
                prof+=lake[x][y];
                dfs(x,y);
            }
        }
    }   
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    FOR(t,f){
        scanf("%d %d",&N,&M);
        FOR(N,i){
            v aux,daux;
            FOR(M,j){
                scanf("%d",&prof);
                aux.emplace_back(prof);
                daux.emplace_back(0);
            }
            lake.emplace_back(aux);
            dis.emplace_back(daux);
        }
        int max=0;
        FOR(N,i){
            FOR(M,j){
                if(lake[i][j]!=0&&dis[i][j]==0){
                    prof=lake[i][j];
                    dis[i][j]=1;
                    dfs(i,j);
                } 
                if(max<prof)max=prof;    
            }
        }
        printf("%d\n",max);
        dis.clear();
        lake.clear();
    }
    return 0;
}
