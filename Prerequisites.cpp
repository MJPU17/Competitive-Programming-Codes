#include<cstdio>
#include<unordered_set>
using namespace std;

int K,M,C,R,A,aux;
unordered_set<int> curses;
bool acp;

int main(int argc, char const *argv[]){
    while(scanf("%d",&K),K){
        acp=true;
        scanf("%d",&M);
        while(K--){
            scanf("%d",&aux);
            curses.insert(aux);  
        }
        while(M--){
            scanf("%d%d",&C,&R);
            A=0;
            while(C--){
                scanf("%d",&aux);
                if(curses.count(aux))A++;
            }
            if(A<R)acp=false;
        }
        (acp?printf("yes\n"):printf("no\n"));
        curses.clear();     
    }
    return 0;
}
