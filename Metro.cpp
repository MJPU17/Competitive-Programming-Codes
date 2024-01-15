#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> list;
typedef vector<vector<int>> adj;
#define FOR(A,I,E) for(int I=E;I<A;I++)
#define FORI(A,I,E) for(int I=A;I>=E;I--)

int N,R,t;
bool res=true;
adj metro;
list connect,dis;

void bfs(int s){
    FOR(N*2,i,0){
        dis.push_back(-1);
    }
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:metro[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

void printGraph(){
    FOR(metro.size(),i,0){
        printf("%d: ",i);
        FOR(metro[i].size(),j,0){
            printf("%d ",metro[i][j]);
        }
        printf("\n");
    }
}

void initGraph(){
    if(connect[0]==0){
        res=false;
        return;
    }
    FOR(N*2,i,0){
        list aux;
        metro.push_back(aux);
    }
    int ant=0;
    if(connect[N]==1){
        metro[ant].push_back(N);
    }
    FOR(N,i,1){
        if(connect[i]==1){
            metro[ant].push_back(i);
            ant=i;
            if(connect[i+N]==1){
                metro[i].push_back(i+N);
            }
        }
    }
    ant=N*2-1;
    while(connect[ant]==0&&ant>N){
        ant--;
    }
    FORI(ant-1,i,N){
         if(connect[i]==1){
            metro[ant].push_back(i);
            ant=i;
        }
    }
    bfs(0);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d",&N,&R);
    FOR(2,i,0){
        FOR(N,j,0){
            scanf("%d",&t);
            connect.push_back(t);
        }
    }
    initGraph();
    if(!res)printf("NO\n");
    else if(dis[R-1]!=-1||dis[R-1+N]!=-1)printf("YES\n");
    else printf("NO\n");
    return 0;
}
