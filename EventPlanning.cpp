#include<cstdio>
using namespace std;


int N,B,H,W,p,a,sol;
bool ok;

int main(int argc, char const *argv[]){
    while(scanf("%d %d %d %d",&N,&B,&H,&W)!=EOF){
        sol=-1;
        while(H--){
            scanf("%d",&p);
            ok=false;            
            for (int i = 0; i < W; i++){
                scanf("%d",&a);
                if(a>=N)ok=true;
            }
            if(ok&&(sol==-1||p*N<sol))sol=p*N;
        }
        if(sol!=-1&&sol<=B)printf("%d\n",sol);
        else printf("stay home\n");
    }
    return 0;
}
