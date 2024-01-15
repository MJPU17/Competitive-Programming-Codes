#include<cstdio>
#include<utility>
#include<vector>
using namespace std;

double A,B,C,D,p;
int m;
vector<pair<int,double>> depre;

int solve(){
    double dep,pag=B+C,pay=C/A;
    for (int i = 0,j=0; i <= A; i++){
        if(i==depre[j].first&&j<depre.size()){
            dep=depre[j].second;
            j++;
        }
        pag-=(pag*dep);
        if(i!=0)C-=pay;
        if(C<pag)return i;
    }
    return A+1;
}

int main(int argc, char const *argv[]){
    while(scanf("%lf %lf %lf %lf",&A,&B,&C,&D),A>=0){
        while(D--){
            scanf("%d %lf",&m,&p);
            depre.emplace_back(pair<int,double>(m,p));
        }
        m=solve();
        if(m==1)printf("1 month\n");
        else printf("%d months\n",m);
        depre.clear();
    }
    return 0;
}
