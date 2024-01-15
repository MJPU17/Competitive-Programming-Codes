#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> v;
typedef vector<v> vv;

int N;
vv adj;
v conect,path;
vector<bool> visited;

bool isSafe(int v, int pos) {
    if (!visited[v]) {
        if (pos == 0) return true;
        if (pos < N+1 && find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), v) != adj[path[pos - 1]].end()) {
            return true;
        }
    }
    return false;
}

bool hamiltonianPathUtil(int pos) {
    if (pos == N+1) return true;
    for (int v = 0; v < N+1; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            visited[v] = true;
            if (hamiltonianPathUtil(pos + 1)) return true;
            path[pos] = -1;
            visited[v] = false;
        }
    }
    return false;
}

bool findHamiltonianPath(int start) {
    path.clear();
    visited.clear();
    for (int i = 0; i < N+1; i++) {
        path.emplace_back(-1);
        visited.emplace_back(false);
    }
    path[0] = start;
    visited[start] = true;
    if (hamiltonianPathUtil(1)) return true;
    return false;
}

void solve(){
    for(int i=0;i<N+1;i++){
        v aux;
        adj.emplace_back(aux);
    }
    for(int i=0;i<N;i++){
        if(i<N-1)adj[i].emplace_back(i+1);
        if(conect[i]==0){
            adj[i].emplace_back(N);
        }else{
            adj[N].emplace_back(i);
        }
    }
    bool sol=false;
    for(int i=0;i<N+1;i++){
        if(findHamiltonianPath(i)){
            sol=true;
            break;
        }
    }
    if(sol){
        for(int i=0;i<N;i++){
            printf("%d ",path[i]+1);
        }
        printf("%d\n",path[N]+1);
    }
    else printf("-1\n");
    adj.clear();
    conect.clear();
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&N);
        int aux;
        for(int i=0;i<N;i++){
            scanf("%d",&aux);
            conect.emplace_back(aux);
        }
        solve();     
    }
    return 0;
}
