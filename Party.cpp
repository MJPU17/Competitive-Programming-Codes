#include<cstdio>
#include<vector>
#include<unordered_set>
#include<cstdlib>
using namespace std;
 
typedef vector<vector<int>> vv;
typedef vector<int> v;
typedef unordered_set<int> set;
#define FOR(A,i) for(int i=0;i<A;i++)
 
vv adj,jerq;
v dis;
int N,D;
set rangs;
 
void dfsUtil(int s){
    for(int v: adj[s]){
        if(dis[v]==0){
            dis[v]=dis[s]+1;
            rangs.insert(dis[v]);
            dfsUtil(v);
        }
    }
}
int root(int i){
    int r=i;
    while (!jerq[r].empty())
    {
        r=jerq[r].at(0);
    }
    return r;
}
 
int dfs(){
    FOR(N,i)dis.push_back(0);
    int k=0;
    FOR(N,k){
        if(dis[k]==0){
            int i=root(k);
            dis[i]=1;
            rangs.insert(dis[i]);
            dfsUtil(i);
        }
    }
    return rangs.size();
}
 
int main(int argc, char const *argv[])
{
    scanf("%d",&N);
    FOR(N,i){
        v aux;
        adj.push_back(aux);
        jerq.push_back(aux);
    }
    FOR(N,i){
       scanf("%d",&D);
       if(D!=-1){
           adj[D-1].push_back(i);
           jerq[i].push_back(D-1);
       }
       
    }
    printf("%d",dfs());
    return 0;
}