#include<cstdio>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    int t,n,aux;
    ll p;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++){
        p=0;
        scanf("%d",&n);
        for(int j = 0; j < n ; j++){
            scanf("%d",&aux);
            if(aux>=0)p+=aux;
        }
        printf("Case %d: %lld\n",i,p);
    }
    return 0;
}
