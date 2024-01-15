#include<cstdio>
#include<unordered_set>
#include<string>
using namespace std;

typedef unordered_set<char> word;

word correct,answer;
string ans;
int N,cont,wrong;

void readWord(){
    correct.clear();
    char car;
    while(scanf("%c",&car)==1&&car!='\n')correct.insert(car);
}

void readAns(){
    answer.clear();
    char car;
    ans="";
    while(scanf("%c",&car)==1&&car!='\n'){
        if(!answer.count(car))ans+=car;
        answer.insert(car);
    }
}

void solve(){
    cont=0;wrong=0;
    printf("Round %d\n",N);
    for(char cur:ans){
        if(correct.count(cur))cont++;
        else wrong++;
        if(wrong==7){
            printf("You lose.\n");
            return;
        }
        if(cont==correct.size()){
            printf("You win.\n");
            return;
        }
    }
    printf("You chickened out.\n");
}

int main(int argc, char const *argv[])
{
    while(true){
        scanf("%d",&N);
        getchar();
        if(N==-1)break;
        readWord();
        readAns();
        solve();
    }
    return 0;
}
