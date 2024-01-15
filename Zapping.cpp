#include<cstdio>
#include<queue>
using namespace std;

int dis[100];
int A,B;

int rec(int n,bool o){
    if(o)return (n==99?0:n+1);
    return (n==0?99:n-1);
}

void bfs(){
    for (int i = 0; i < 100; i++)dis[i]=-1;
    queue<int> Q;
    dis[A]=0;
    if(A==B)return;
    Q.push(A);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        int v1=rec(u,true);
        int v2=rec(u,false);
        if(dis[v1]==-1){
            dis[v1]=dis[u]+1;
            Q.push(v1);
        }
        if(dis[v2]==-1){
            dis[v2]=dis[u]+1;
            Q.push(v2);
        }
        if(v1==B||v2==B)break;
    }
}

int main(int argc, char const *argv[]){
    while(scanf("%d %d",&A,&B),A>=0&&B>=0){
        bfs();
        printf("%d\n",dis[B]);    
    }
    return 0;
}
