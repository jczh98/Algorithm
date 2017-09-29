#include <bits/stdc++.h>
using namespace std;
int m, b, a[20005], s, flag;
int main() {
    while(scanf("%d", &m) != EOF) {
        while(m--) {
            scanf("%d", &b);
            for(int i = 1; i <= b; i++) {
                scanf("%d", &a[i]);
            }
            sort(a + 1, a + 1 + b);
            s = 0; flag = 0;
            for(int i = 1; i <= b; i++) {
                s += a[i];
                if(s < i * (i - 1)) {
                    flag = 1;
                    break;
                }
            }
            if(s != b * (b - 1)) {
                flag = 1;
            }
            if(flag) {
                printf("F\n");
            }else {
                printf("T\n");
            }
        }
    }
    return 0;
}

