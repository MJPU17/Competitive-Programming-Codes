#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> v;
typedef vector<vector<int>> vv;
#define FOR(A,i) for(int i=0;i<A;i++)

int N,D;
vv adj;
v dis;

void bfs(int s){
    FOR(N-1,I){
        dis.emplace_back(-1);
    }
    queue<int> q;
    dis[s]=0;
    q.emplace(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : adj[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.emplace(v);
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    v connection;
    scanf("%d %d",&N,&D);
    FOR(N-1,i){
        int val;
        v aux;
        adj.emplace_back(aux);
        scanf("%d",&val);
        connection.emplace_back(val);
    }
    FOR(N-1,i)adj[i].emplace_back(i+connection[i]);
    bfs(0);
    if(dis[D-1]!=-1)printf("YES\n");
    else printf("NO\n");
    return 0;
}
