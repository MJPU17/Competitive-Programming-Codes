#include<cstdio>

using namespace std;

bool prime[1000002];
int N;

void init(){
    for (int i = 0; i <1000002; i++)prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<1000002;i++){
        if(prime[i]){
            for(int j=i*i;j<1000002;j+=i)prime[j]=false;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    scanf("%d",&N);
    for(int m=1;m<1000;m++){
        if(!prime[N*m+1]){
            printf("%d\n",m);
            break;
        }
    }
    return 0;
}
