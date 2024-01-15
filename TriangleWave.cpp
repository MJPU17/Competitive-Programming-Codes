#include<cstdio>
using namespace std;

int T,A,F;

void solve(){
    for (int i = 0; i < F; i++){
        for (int j = 1; j <= A; j++){
            for(int k=0;k<j;k++){
                printf("%d",j);
            }
            printf("\n");
        }
        for (int j = A-1; j > 0; j--){
            for(int k=0;k<j;k++){
                printf("%d",j);
            }
            printf("\n");
        }
        if(i!=F-1)printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d\n%d",&A,&F);
        solve();
         if(T-1!=i)printf("\n");
    }
    return 0;
}
