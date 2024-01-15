#include<cstdio>
using namespace std;

long long cont,L,T,A;

void sequence(long long num){
    if(num==1)return;
    else if(num%2==0)num/=2;
    else{ 
        num=3*num+1;
        if(num>L)return;
    }
    cont++;
    sequence(num);
}

int main(int argc, char const *argv[]){
    T=1;
    while(true){
        scanf("%lld %lld",&A,&L);
        if(A<0&&L<0)break;
        cont=1;
        sequence(A);
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",T,A,L,cont);
        T++;
    }
    return 0;
}
