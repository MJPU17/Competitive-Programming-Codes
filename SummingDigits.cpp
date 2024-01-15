#include<cstdio>
#include<cmath>
using namespace std;

int N;

int numDigits(int num,int digits){
    if(num==0)return digits;
    return numDigits(num/10,digits+1);
}

int sumDigits(int num){
    int len=numDigits(num,0);
    if (len==1)return num;
    int sum=0;
    for (int i = 1; i <= len; i++){
        sum+=((num/(int)pow(10,i-1))%10);
    }
    return sumDigits(sum);
}

int main(int argc, char const *argv[]){
    while(scanf("%d",&N),N)printf("%d\n",sumDigits(N));
    return 0;
}
