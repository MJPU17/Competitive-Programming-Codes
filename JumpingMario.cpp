#include<cstdio>
using namespace std;

int I,N,T,B,arr[49];

int main(int argc, char const *argv[]){
    scanf("%d",&I);
    for (int i = 1; i <= I; i++){
        scanf("%d",&N);
        T=0;
        B=0;
        for (int j = 0; j < N; j++){
            scanf("%d",&arr[j]);
            if(j){
                if(arr[j-1]<arr[j])T++;
                else if(arr[j-1]>arr[j])B++;
            }
        }
        printf("Case %d: %d %d\n",i,T,B);
    }
    return 0;
}
