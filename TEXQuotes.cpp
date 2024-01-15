#include<cstdio>
using namespace std;

char s;
bool ab=true;

int main(int argc, char const *argv[]){
    while(scanf("%c",&s)!=EOF){
        if(s=='"'){
            if(ab)printf("``");
            else printf("''");
            ab=!ab;
        }
        else printf("%c",s);
    }
    return 0;
}
