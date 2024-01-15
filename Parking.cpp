#include<cstdio>
using namespace std;

int T,N,X,mn,mx,aux;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        mn=100;
        mx=-1;
        while(N--){
            scanf("%d",&aux);
            if(mx<aux)mx=aux;
            if(mn>aux)mn=aux;
        }
        printf("%d\n",2*(mx-mn));
    }
    return 0;
}
