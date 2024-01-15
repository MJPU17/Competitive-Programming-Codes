#include<cstdio>
using namespace std;

int T,A,B;

int main(int argc, char const *argv[]){

    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d %d",&A,&B);
        printf("%d\n",((int)A/3)*((int)B/3));
    }
    return 0;
}
