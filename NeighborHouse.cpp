#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
    int d,w;
    Node(int des, int pes):d(des),w(pes){}
    bool operator<(const Node &b) const{
        return w > b.w;
    }
};
typedef vector<Node> v;
typedef vector<v> vv;


int N,T;
vector<int> dis;
vector<bool> vis;
priority_queue<Node> Q;
vv adj;

void init() {
    dis.resize(N + 1, -1);
    vis.resize(N + 1, false);
}
void relajacion(int c, int a, int w) {
    if (dis[c] + w < dis[a] || dis[a]==-1) {
        dis[a] = dis[c] + w;
        Q.push(Node{a, dis[a]});
    }
}
void dijkstra(int inicial) {
    init();
    Q.push(Node{inicial, 0});
    dis[inicial] = 0;
    int c, a, w;
    while (!Q.empty()) {
        c = Q.top().d;
        Q.pop();
        if (vis[c]) continue;
        vis[c] = true;
        for (auto i = 0u; i < adj[c].size(); i++) {
            a = adj[c][i].d;
            w = adj[c][i].w;
            if (!vis[a]) {
                relajacion(c, a, w);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&T);
    for (int t = 1; t <= T; t++){
        scanf("%d",&N);
        for (int i = 0; i < N*3; i++){
            v aux;
            adj.emplace_back(aux);
        }
        int k=1,aux;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < 3; j++){
                scanf("%d",&aux);
               if(i==0){
                adj[0].emplace_back(Node(k,aux));
               }
               else{
                if(j==0){
                    adj[k-1].emplace_back(Node(k,aux));
                    adj[k-2].emplace_back(Node(k,aux));
                }
                else if(j==1){
                    adj[k-2].emplace_back(Node(k,aux));
                    adj[k-4].emplace_back(Node(k,aux));
                }
                else{
                    adj[k-4].emplace_back(Node(k,aux));
                    adj[k-5].emplace_back(Node(k,aux));
                }
               }
               k++; 
            }
        }
        N=N*3;
        dijkstra(0);
        printf("Case %d: %d\n",t,min(dis[N],min(dis[N-1],dis[N-2])));
        adj.clear();
        dis.clear();
        vis.clear();
    }
    return 0;
}
