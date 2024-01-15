#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int>> vp;

int N,C,P;
vi init;
vp pole;
bool sol;

bool isValid(int pos){
    if(pos>=0&&pos<N)return true;
    return false;
}

void solve(){
    for (int i = 0; i < N; i++){
        int pos=i+pole[i].second;
        if(!isValid(pos)||init[pos]!=-1){
            sol=false;
            break;
        }
        init[pos]=pole[i].first;
    }
    if(!sol)printf("-1\n");
    else{
        for (int i = 0; i < N; i++){
            if(i!=N-1)printf("%d ",init[i]);
            else printf("%d\n",init[i]);
        }
    }
}

int main(int argc, char const *argv[]){
    while(true){
        scanf("%d",&N);
        if(N==0)break;
        sol=true;
        for (int i = 0; i <N; i++){
            scanf("%d %d",&C,&P);
            pole.emplace_back(pair<int,int>(C,P));
            init.emplace_back(-1);
        }
        solve();
        pole.clear();
        init.clear();
    }
    return 0;
}
