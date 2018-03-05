#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,flag=0;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d%d%d",&a,&b,&c);
        if((a+b)>c&&(b+c)>a&&(a+c)>b)continue;else flag=1;
    }
    if(!flag)printf("YES\n");else printf("NO\n");
    return 0;
}