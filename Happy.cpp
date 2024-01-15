#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,a,b,c,d,tiem=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(i==0){
            tiem=b+c;
            printf("%d\n",a);
            continue;
        }
        if(tiem<=b+d){
            if(b>tiem)tiem=b;
            tiem+=c;
            printf("%d\n",a);
        }
    }
    return 0;
}
