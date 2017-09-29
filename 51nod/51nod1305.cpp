#include <bits/stdc++.h>
using namespace std;
int n, a, s1, s2;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if(a == 1) s1++;
        if(a == 2) s2++;
    }
    printf("%d", s1 * (n - 1) + s2 * (s2 - 1) / 2);
    return 0;
}
