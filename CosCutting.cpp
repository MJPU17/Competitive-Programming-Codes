#include<cstdio>
#include<algorithm>
using namespace std;

int e[3],T;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d %d",&e[0],&e[1],&e[2]);
        sort(e,e+3);
        printf("Case %d: %d\n",i,e[1]);
    }
    return 0;
}
