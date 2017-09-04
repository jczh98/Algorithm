#include <bits/stdc++.h>
using namespace std;
int n, a, odd, even;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(a & 1) odd++;
        else even++;
    }
    if(odd & 1) {
        printf("First\n");
    }else {
        if(odd == 0) {
            printf("Second\n");
        }else {
            printf("First\n");
        }
    }
    return 0;
}