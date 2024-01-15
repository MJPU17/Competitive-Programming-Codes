#include <cstdio>
#include<utility>
using namespace std;

pair<int,int> cord1;
pair<int,int> cord2;
int N,M,t;

int min(){
    if(cord1.first==1&&cord1.second==1 ||cord1.first==N&&cord1.second==1 || cord1.first==1&&cord1.second==M || cord1.first==N&&cord1.second==M
    ||cord2.first==1&&cord2.second==1 ||cord2.first==N&&cord2.second==1 || cord2.first==1&&cord2.second==M || cord2.first==N&&cord2.second==M)return 2;
    if(cord1.first==1||cord1.second==1 ||cord1.first==N||cord1.second==M||cord2.first==1||cord2.second==1 ||cord2.first==N||cord2.second==M)return 3;
    return 4;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        scanf("%d %d\n%d %d %d %d",&N,&M,&cord1.first,&cord1.second,&cord2.first,&cord2.second);
        printf("%d\n",min());
    }    
    return 0;
}
