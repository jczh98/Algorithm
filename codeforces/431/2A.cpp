#include <bits/stdc++.h>
using namespace std;
int n, a[1000], cnt = 0, c[1000], need = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= 2;
    }
    if(n % 2 == 0 || a[1] == 0 || a[n] == 0) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}

