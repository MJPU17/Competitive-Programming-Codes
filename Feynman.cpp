#include<cstdio>
using namespace std;

int N, mem[101];

int solve(int n){
    if(mem[n]==-1){
        if(n==0)mem[n]=0;
        else mem[n]=(n*n)+solve(n-1);
    }
    return mem[n];
}

int main(int argc, char const *argv[]){
    for (int i = 0; i < 101; i++){
        mem[i]=-1;
    }
    while(true){
        scanf("%d",&N);
        if(N==0)break;
        printf("%d\n",solve(N));
    }
    return 0;
}
