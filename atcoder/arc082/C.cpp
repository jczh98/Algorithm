#include <bits/stdc++.h>
using namespace std;
int n, a[100005], c[100005], ans = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[a[i]]++;
        c[a[i] + 1]++;
        if(a[i] == 0) {
            c[100005]++; 
        }else {
            c[a[i] - 1]++;
        }
    }
    for(int i = 0; i <= 100005; i++) {
        ans = max(c[i], ans);
    }
    printf("%d\n", ans);
    return 0;
}