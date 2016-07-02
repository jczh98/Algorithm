#include <cstdio>

int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0) return 0;
        if(n%2==0)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}