#include<cstdio>
using namespace std;

int box[3],T;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for (int i = 1; i <= T; i++){
        scanf("%d%d%d",&box[0],&box[1],&box[2]);
        if(box[0]<=20&&box[1]<=20&&box[2]<=20)printf("Case %d: good\n",i);
        else printf("Case %d: bad\n",i);
    }
    return 0;
}
