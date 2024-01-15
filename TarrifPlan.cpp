#include<cstdio>
using namespace std;

int T,N,aux,sm,sj, mile[2001],juice[2001];

void init(){
    int paym=10,payj=15;
    for (int i = 0,j=0,k=0; i < 2001; i++,j++,k++){
        if(j==30){
            j=0;
            paym+=10;
        }
        if(k==60){
            k=0;
            payj+=15;
        }
        mile[i]=paym;
        juice[i]=payj;
    } 
}

int main(int argc, char const *argv[]){
    init();
    scanf("%d",&T);
    for (int i = 1; i <= T; i++){
        scanf("%d",&N);
        sm=0;sj=0;
        while (N--){
            scanf("%d",&aux);
            sm+=mile[aux];
            sj+=juice[aux];
        }
        if(sm<sj)printf("Case %d: Mile %d\n",i,sm);
        else if(sj<sm)printf("Case %d: Juice %d\n",i,sj);
        else printf("Case %d: Mile Juice %d\n",i,sm);
    }    
    return 0;
}
