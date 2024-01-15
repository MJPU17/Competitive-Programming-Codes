#include<cstdio>
using namespace std;

int N,A,B,C,D;

void solve(){
    if(C==A||D==B)printf("divisa\n");
    else if(C>A&&D>B)printf("NE\n");
    else if(C<A&&D>B)printf("NO\n");
    else if(C<A&&D<B)printf("SO\n");
    else printf("SE\n");
}

int main(int argc, char const *argv[]){
    while(scanf("%d",&N),N>0){
        scanf("%d %d",&A,&B);
        while(N--){
            scanf("%d %d",&C,&D);
            solve();
        }
    }
    return 0;
}
