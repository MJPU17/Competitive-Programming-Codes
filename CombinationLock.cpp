#include<cstdio>
#include<unordered_map>
using namespace std;

unordered_map<int,int> h;
int A,B,C,D;

int res(){
    int u=(B<=A?A-B:h[B]+A);
    int d=(C<B?h[B]+C:C-B);
    int t=(D<=C?C-D:h[D]+C);
    return (360*2+u*9)+(360+d*9)+t*9;
}

int main(int argc, char const *argv[]){
    h[0]=0;
    for(int i=39,j=1;i>0;i--,j++)h[i]=j;
    while(scanf("%d %d %d %d",&A,&B,&C,&D),(A||B||C||D)){
        printf("%d\n",res());
    }
    return 0;
}
