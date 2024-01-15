#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> vi;

int B,N,R,D,C,V;
vi arr;

void solve(){
    for (int i = 0; i < B; i++){
        if(arr[i]<0){
            printf("N\n");
            return;
        }
    }
    printf("S\n");
}

int main(int argc, char const *argv[]){
    while(scanf("%d %d",&B,&N),B||N){
        for (int i = 0; i < B; i++){
            scanf("%d",&R);
            arr.emplace_back(R);     
        }
        while(N--){
            scanf("%d %d %d",&D,&C,&V);
            arr[D-1]-=V;
            arr[C-1]+=V;
        }
        solve();
        arr.clear();
    }
    return 0;
}
