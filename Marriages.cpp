#include<cstdio>
using namespace std;

int m[16][16],N,T;
bool visi[16];
bool visj[16];

void reset(){
    for(int i=0;i<N;i++){
        visi[i]=false;
        visj[i]=false;
    }
}

bool equal(int i,int j,int a,int b){
    int max1=-1,max2=-1;
    for(int t=0;t<N;t++){
        if(t==j)continue;
        if(m[i][t]<max1){
            max1=m[i][t];
        }
    }
    for(int t=0;t<N;t++){
        if(t==b)continue;
        if(m[a][t]<max1){
            max2=m[a][t];
        }
    }
    return max1>max2;
}

int maxin(){
    int maxi=-1,a,b;
    for(int i=0;i<N;i++){
        if(visi[i])continue;
        for(int j=0;j<N;j++){
            if(visj[j])continue;
            if(maxi<m[i][j]){
                maxi=m[i][j];
                a=i;
                b=j;
            }
            else if(maxi==m[i][j]&&equal(i,j,a,b)){
                maxi=m[i][j];
                a=i;
                b=j;
            }  
        }
    }
    visi[a]=true;
    visj[b]=true;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&m[i][j]);
            }
        }
        reset();
        int sol=0;
        for(int i=0;i<N;i++){
            sol+=maxin();
        }
        printf("Case %d: %d",t,sol);
    }
    return 0;
}
