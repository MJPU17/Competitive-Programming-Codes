#include<cstdio>
using namespace std;

int T,A,B;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&A,&B);
        (A<B?printf("<\n"):(A>B?printf(">\n"):printf("=\n")));
    }
    return 0;
}
