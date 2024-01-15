#include<cstdio>
using namespace std;

int N,aux,deg,dag,i=1;

int main(int argc, char const *argv[]){
    while(scanf("%d",&N),N){
        deg=0;dag=0;
        while(N--){
            scanf("%d",&aux);
            if(aux!=0)deg++;
            else dag++;
        }
        printf("Case %d: %d\n",i++,deg-dag);
    }
    return 0;
}
