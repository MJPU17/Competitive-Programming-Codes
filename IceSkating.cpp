#include<cstdio>
#include<unordered_map>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

typedef pair<int,int> cord;
typedef vector<int> v;
typedef vector<v> vv;

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

int N,time,nscc;
vv adj;
unordered_map<cord,int,PairHash> con;
v d,scc;
stack<int> top_sort;

v newVector(int contain){
    v vaux;
    for(int i=0;i<N;i++){
        vaux.emplace_back(contain);
    }
    return vaux;
}

void dfs(int u) {
    d[u] = time++;
    for(int v:adj[u]) {if (d[v]==0) dfs(v);}
    top_sort.push(u);
}

void dfs_kos(int u) {
    scc[u] = nscc;
    d[u] = time++;
    for(int v:adj[u]) {if (d[v]==0) dfs_kos(v);}
}

vv transpose(){
    vv adj2;
    for(int i=0; i<N;i++){
        v aux;
        adj2.emplace_back(aux);
    }
    for(int i=0; i<N;i++){
        for(int v:adj[i]){
            adj2[v].emplace_back(i);
        }
    }
    return adj2;
}

void strongly_cc(){
    d=newVector(0);
    time=1;
    for(int i=0; i<N;i++){
        if(d[i]==0){
            dfs(i);
        }
    }
    nscc=0;
    d=newVector(0);
    scc=newVector(-1);
    adj=transpose();
    while(!top_sort.empty()){
        int u=top_sort.top();
        top_sort.pop();
        if(d[u]==0){
            dfs_kos(u);
            nscc++;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&N);
    int num=0;
    for(int i=0;i<N;i++){
        cord caux;
        v vaux;
        scanf("%d %d",&caux.first,&caux.second);
        con.insert({caux,num++});
        adj.emplace_back(vaux);
    }
    for(pair<cord,int> maux:con){
        for(pair<cord,int> maux2:con){
            if(maux.first.first==maux2.first.first || maux.first.second==maux2.first.second){
                if(maux.first!=maux2.first)adj[maux.second].emplace_back(maux2.second);
            }
        }
    }
    strongly_cc();
    printf("%d",nscc-1);
    return 0;
}