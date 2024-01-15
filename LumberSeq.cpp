#include<cstdio>
#include<algorithm>
using namespace std;

int N,arr[10],aux[10];
bool sol;

bool solveN(){
    for (int i = 0; i < 10; i++){
        if(arr[i]!=aux[i])return false;
    }
    return true;
}

bool solveI(){
    for (int i = 0,j=9; i < 10; i++,j--){
        if(arr[i]!=aux[j])return false;
    }
    return true;
}

int main(int argc, char const *argv[]){
    scanf("%d",&N);
    printf("Lumberjacks:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10; j++){
            scanf("%d",&arr[j]);
            aux[j]=arr[j];
        }
        sort(aux,aux+10);
        if(aux[0]==arr[0])sol=solveN();
        else sol=solveI();
        if(sol)printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}
