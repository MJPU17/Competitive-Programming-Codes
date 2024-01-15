#include<cstdio>
using namespace std;

int T,N;
double sum,A,B,C;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d",&N);
        sum=0;
        for (int j = 0; j < N; j++){
            scanf("%lf %lf %lf",&A,&B,&C);
            if(B!=0){
                sum+=(A*C);
            }
        }
        printf("%.0lf\n",sum);
    }
    return 0;
}
