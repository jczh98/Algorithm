#include <bits/stdc++.h>
using namespace std;
int a[100], n, b[100], s[100];
bool cmp(int x, int y) {return a[x] < a[y];}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);s[i] = i;
    }
    sort(s + 1, s + 1 + n, cmp);
    for(int i = 1; i <= n; ++i) b[s[i % n + 1]] = a[s[i]];
    for(int i = 1; i <= n; ++i) {
        printf("%d%c", b[i], i == n ? '\n' : ' ');
    }
    return 0;
}