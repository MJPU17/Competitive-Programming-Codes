#include<cstdio>
using namespace std;

int T,N,A,M;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for (int i = 1; i <= T; i++){
        scanf("%d",&N);
        M=0;
        for (int j = 0; j < N; j++){
            scanf("%d",&A);
            if(A>M)M=A;
        }
        printf("Case %d: %d\n",i,M);
    }
    return 0;
}
