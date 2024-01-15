#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> Node;
typedef vector<Node> v;
typedef vector<vector<Node>> vv;
#define FOR(A,i) for(ll i=0;i<A;i++)

int N;
ll aux;
vi arr,dis;
vv adj;

void bfs(Node s){
    queue<Node> c;
    dis[s.first]=0;
    c.push(s);
    while (!c.empty())
    {
        Node u=c.front();
        c.pop();
        for(Node v: adj[u.first]){
            if(dis[v.first]==-1){
                dis[v.first]=dis[u.first]+v.second;
                c.push(v);
            }
            else if(dis[u.first]+v.second>dis[v.first]){
                dis[v.first]=dis[u.first]+v.second;
            }
        }
    }

}

void initGraph(){
    FOR(N+2,i){
        v aux;
        if(i!=0 && i!=N+1){
            Node n;
            n.first=i+arr[i-1];
            if(n.first>N)n.first=N+1;
            n.second=arr[i-1];
            aux.emplace_back(n);
        }
        else if(i!=N+1){
            FOR(N+1,i){
                Node n;
                n.first=i;
                n.second=0;
                aux.emplace_back(n);
            }
       }
       adj.emplace_back(aux);
    }
    Node s;
    s.first=0;
    s.second=0;
    bfs(s);
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    FOR(t,i){
        scanf("%d",&N);
        dis.emplace_back(-1);
        dis.emplace_back(-1);
        FOR(N,i){
            scanf("%lld",&aux);
            arr.emplace_back(aux);
            dis.emplace_back(-1);
        }
        initGraph();
        ll max=0;
        FOR(N+2,i){
            if(dis[i]>max)max=dis[i];
        }
        printf("%lld\n",max);
        dis.clear();
        adj.clear();
        arr.clear();
    }
    return 0;
}
