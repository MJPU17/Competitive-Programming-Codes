#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> v;
#define FOR(A,i,j) for(int i=j;i<A;i++)

int N,T,M;
v wei;

int sum(){
    int s=(wei[N-1]+wei[0]);
    FOR(N,i,1){
        s+=(wei[i-1]+wei[i]);
    }
    return s;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&T);
    FOR(T,i,0){
        scanf("%d %d",&N,&M);
        int aux;
        FOR(N,i,0){
            scanf("%d",&aux);
            wei.emplace_back(aux);
        }
        if(M<N||M==2)printf("-1\n");
        else{
            printf("%d\n",sum());
            for(int i=1;i<=M;i++){
                if(i!=M)printf("%d %d\n",i,i+1);
                else printf("%d %d\n",i,1);
            }
        }
        wei.clear();
    }
    return 0;
}
