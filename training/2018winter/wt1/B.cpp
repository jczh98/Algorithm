#include <bits/stdc++.h>
using namespace std;
int t,v,number[10000],Max,a;
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(number,0,sizeof(number));
        Max=0;
        scanf("%d", &v);
        for(int i=1;i<=v;++i) {
            scanf("%d", &a);
            number[a]++;
        }
        for(int i=1;i<=1000;++i) {
            Max=max(number[i],Max);
        }
        for(int i=1;i<=1000;++i) {
            if(number[i]==Max) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}