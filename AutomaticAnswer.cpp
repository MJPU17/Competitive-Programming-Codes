#include<cstdio>
#include<cmath>
using namespace std;

int T,A;

int main(int argc, char const *argv[]){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&A);
        printf("%d\n",(abs((((((A*567)/9)+7492)*235)/47)-498)/10)%10);
    }
    return 0;
}
