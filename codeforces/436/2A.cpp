#include <bits/stdc++.h>
using namespace std;
int n, a[1000], cnt[1000];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    int flag1 = 0, flag2 = 0;
    for(int i = 1; i <= 100; ++i) {
        if(cnt[i]) {
            flag1++;
        }
    }
    for(int i = 1; i <= 100; ++i) {
        if(cnt[i]) {
            if(cnt[i] != n / 2) {
                flag2 = 1;
            }
        }
    }
    if(flag1 == 2 && !flag2) {
        printf("YES\n");
        for(int i = 1; i <= 100; ++i) {
            if(cnt[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }else {
        printf("NO\n");
    }
}

