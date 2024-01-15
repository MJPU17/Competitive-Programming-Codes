#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int ll;

int A, B, T;
vector<int> p;

vector<int> sieve(int n){
    vector<int> is(n+1, 0);
    is[0] = is[1] = 1;
    for(int i = 2; i <= n; i++){
        if(is[i]==0){
            p.push_back(i);
            for(int j = 2*i; j <= n; j += i){
                is[j] = 1;
            }
        }
    }
    return is;
}
ll phi(int n){
    ll res = n;
    for (ll i = 0; p[i] * p[i] <= n; i++){
        if (n % p[i] == 0){
            res -= (res / p[i]);
            while (n % p[i] == 0){
                n /= p[i];
            }
        }
    }
    if (n > 1){
        res -= (res / n);
    }
    return res*res;
}

ll totalScore(int a,int b){
    ll aux=0;
    for(int i=a;i<=b;i++){
        aux+=phi(i);
    }
    return aux;
}

int main(int argc, char const *argv[])
{
    sieve(5e6);
    scanf("%d",&T);
    for (int i = 1; i<=T; i++){
        scanf("%d %d",&A,&B);
        printf("Case %d: %lld\n",i,totalScore(A,B));
    }
    return 0;
}
