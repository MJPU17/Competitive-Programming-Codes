#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int,int> node;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<node> v;
typedef vector<v> vv;
#define FOR(A,i) for(int i=0;i<A;i++)

vv adj;
int N ,T,maxi=0;
vi values,dis,rec;

void bfs(){
    node n;
    n.first=0;
    n.second=0;
    queue<node> cola;
    cola.push(n);
    dis[0]=rec[0]=0;
    while(!cola.empty()){
        node u=cola.front();
        cola.pop();
        for(node v:adj[u.first]){
            if(dis[v.first]==-1){
                dis[v.first]=dis[u.first]+v.second;
                cola.push(v);
            }
            else if(dis[v.first]<=dis[u.first]+v.second){
                dis[v.first]=dis[u.first]+v.second;
                rec[v.first]=rec[u.first]+1;
            }
        }
    }

}

void printfGraph(){
    FOR(N*12+1,i){
        printf("%d:",i);
        FOR(adj[i].size(),j){
            printf("[%d]",adj[i][j].first);
        }
        printf("\n");
    }
}

void initGraph(){
    FOR(12*N+1,i){
        v aux;
        dis.emplace_back(-1);
        rec.emplace_back(-1);
        adj.emplace_back(aux);
    }
    for(int i=1;i<=N*12;i+=12){
        node n;
        n.first=i;
        n.second=values[i];
        adj[0].emplace_back(n);
        for(int j=1;j<=N*12;j++){
            n.first=j;
            n.second=values[j];
            adj[i].emplace_back(n);
        }
    }
    for(int j=1;j<N*12;j++){
        if((j-1)%12==0)continue;
        node n;
        n.first=j+1;
        n.second=values[j+1];
        adj[j].emplace_back(n);
    }
    bfs();
}

int main(int argc, char const *argv[])
{
    scanf("%d %d",&N,&T);
    int val;
    values.emplace_back(0);
    FOR(N,i){
      FOR(12,i){
        scanf("%d",&val);
        values.emplace_back(val);
      }
    }
    initGraph();
    printfGraph();
    FOR(N*12,i){
        if(dis[i]>maxi&&rec[i]==T)maxi=dis[i];
    }
    printf("%d\n",maxi);
    return 0;
}
