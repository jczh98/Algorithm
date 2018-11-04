#include <bits/stdc++.h>
using namespace std;
int n, T, a[100]={0,1,2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,
 173,311,317};
char s[1000];
int main() {
    scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase) {
        scanf("%s",&s);
        int len=strlen(s);
        if(len >= 4) {
            printf("Case #%d: %d\n", kase, a[20]);
        }else {
            int x = atoi(s), pos;
            for(int i = 1; i <= 20; ++i) {
                if(x >= a[i]) {
                    pos = i;
                }
            }
            printf("Case #%d: %d\n", kase, a[pos]);
        }
    }
    return 0;
}