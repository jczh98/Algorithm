#include <bits/stdc++.h>
using namespace std;
int n, p[100005], ans = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for(int i = 1; i < n; i++) {
        if(p[i] == i && p[i + 1] == i + 1) {
            swap(p[i], p[i + 1]);
            ans++;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(p[i] == i) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}