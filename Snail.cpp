#include<cstdio>
using namespace std;

double H,U,D,F,aux;
int count;
bool suc;

void solve(){
    double men=F*U/100;
    while(aux<=H&&aux>=0){
        count++;
        aux+=U;
        U-=men;
        if(U<0)U=0;
        if(aux<=H)aux-=D;
    }
    suc=(aux>=0);
}

int main(int argc, char const *argv[])
{
    while(true){
        scanf("%lf %lf %lf %lf",&H,&U,&D,&F);
        if(H==0)break;
        count=0;
        aux=0;
        solve();
        if(suc)printf("success on day %d\n",count);
        else printf("failure on day %d\n",count);
    }    
    return 0;
}
