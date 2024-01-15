#include<cstdio>
using namespace std;

int T,A,B,C,D;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d %d %d %d",&A,&B,&C,&D);
        printf("%d\n",(A+B+C+D));
    }
    return 0;
}
