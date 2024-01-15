#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> v;
typedef vector<vector<int>> vv;
#define FOR(A,i) for(int i=0;i<A;i++)

int N,R;
vv adj;
v dis,connection;

void dfsUtil(int s){
    for(int v: adj[s]){
        if(dis[v]==-1&&R==-1){
            dis[v]=dis[s]+1;
            dfsUtil(v);
        }
        else if(dis[v]!=-1&&R==-1)R=v;
    }
}

void dfs(int s){
    FOR(N,i){
        dis[i]=-1;
    }
    R=-1;
    dis[s]=0;
    dfsUtil(s);
}

int main(int argc, char const *argv[])
{
    scanf("%d",&N);
    int val;
    FOR(N,i){
        v aux;
        adj.emplace_back(aux);
        dis.emplace_back(-1);
        scanf("%d",&val);
        connection.emplace_back(val-1);
    }
    FOR(N,i){
        adj[i].emplace_back(connection[i]);
    }
    FOR(N,i){
        dfs(i);
        if(i!=N-1)printf("%d ",R+1);
        else printf("%d\n",R+1);
    }
    return 0;
}
