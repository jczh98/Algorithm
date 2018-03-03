#include <bits/stdc++.h>
using namespace std;
int n, a[200005], sum[200005];
char s[200005];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + s[i] - '0';
    int flag = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > i) {
            if(a[i] - i != sum[a[i] - 1] - sum[i - 1]) flag = 1;
        }
    }
    if(flag == 1) printf("NO\n"); else printf("YES\n");
    return 0;
}