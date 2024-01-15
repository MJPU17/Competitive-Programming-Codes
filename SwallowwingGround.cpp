#include<cstdio>
#include<cmath>
using namespace std;

int T,W,A,B,ant;
bool sol;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&W);
        sol=true;
        ant=-1;
        while (W--){
            scanf("%d %d",&A,&B);
            if(ant!=abs(A-B)&&ant!=-1)sol=false;
            ant=abs(A-B);
        }
        if(i!=0)printf("\n");
        printf((sol?"yes\n":"no\n"));
    }
    return 0;
}
