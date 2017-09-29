#include <bits/stdc++.h>
using namespace std;
int n, a, cnt0, cnt5;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if(!a) cnt0++;
        else cnt5++;
    }
    if(!cnt0) {
        printf("-1\n");
    }else {
        if(cnt5 / 9 == 0) printf("0\n");
        else {
            for(int i = 1; i <= cnt5 / 9 * 9; ++i) printf("5");
            for(int i = 1; i <= cnt0; ++i) printf("0");
            printf("\n");
        }
    }
    return 0;
}

