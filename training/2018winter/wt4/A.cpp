#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main() {
    freopen("tabs.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&k);
        if(n==1) {
            printf("0\n"); continue;
        }
        if(k==n||k==1)printf("1\n");
        else printf("2\n");
    }
    return 0;
}