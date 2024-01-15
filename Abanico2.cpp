#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

ll x(ll n){
    ll t=((ll)sqrt(n-1))+1;
    return (t%2)*min(t,t*t-n+1) + ((t+1)%2)*min(t,n-((t-1)*(t-1)));
}

ll y(ll n){
    ll t=((ll)sqrt(n-1))+1;
    return (t%2)*min(t,n-((t-1)*(t-1))) + ((t+1)%2)*min(t,t*t-n+1);
}

int main(int argc, char const *argv[])
{
    int t;
    ll N;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld",&N);
        printf("Case %d: %d %d\n",i,x(N),y(N));
    }
    return 0;
}