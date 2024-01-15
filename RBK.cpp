#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int,int> cord;
typedef vector<int> v;
typedef vector<v> vv;
#define FOR(A,i) for(int i=0;i<A;i++)

int r1,c1,r2,c2;
vv dis;

v myrook={-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
v mxrook={0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
v mybish={-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7};
v mxbish={-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
v mxking={0,0,1,-1,1,-1,1,-1};
v myking={1,-1,0,0,1,-1,-1,1};
v movy,movx;

bool isValid(int y,int x){
    if(y>=0&&y<8&&x>=0&&x<8)return true;
    return false;
}

void bfs(){
    cord s;
    s.first=r1-1;
    s.second=c1-1;
    dis[s.first][s.second]=0;
    queue<cord> cola;
    cola.push(s);
    while(!cola.empty()){
        cord u=cola.front(),v;
        cola.pop();
        FOR(movx.size(),i){
            v.first=u.first+movy[i];
            v.second=u.second+movx[i];
            if(isValid(v.first,v.second)&&dis[v.first][v.second]==-1){
                dis[v.first][v.second]=dis[u.first][u.second]+1;
                cola.push(v);
                if(v.first==r2-1&&v.second==c2-1)return;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    vv aux;
    FOR(8,i){
        v ax;
        FOR(8,j){
            ax.emplace_back(-1);
        }
        aux.emplace_back(ax);
    }
    FOR(3,i){
        dis=aux;
        if(i==0){
            movy=myrook;
            movx=mxrook;
        }
        else if(i==1){
            movy=mybish;
            movx=mxbish;
        }
        else {
            movy=myking;
            movx=mxking;
        }
        bfs();
        if(dis[r2-1][c2-1]!=-1)printf("%d",dis[r2-1][c2-1]);
        else printf("0");
        if(i!=2)printf(" ");
        else printf("\n");
    }
    return 0;
}
