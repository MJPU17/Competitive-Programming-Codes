#include<cstdio>
using namespace std;

int N,ax,ay,bx,by,cx,cy;

bool win(){
    if(ax>=bx&&ax<=cx||ax>=cx&&ax<=bx||ay>=by&&ay<=cy||ay>=cy&&ay<=by)return false;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d\n%d %d\n%d %d\n%d %d",&N,&ax,&ay,&bx,&by,&cx,&cy);
    printf((win()?"YES\n":"NO\n"));
    return 0;
}
