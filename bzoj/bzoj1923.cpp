#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 2005;
int ans = 0;
bitset<N> A[M];
bool Gauss(int n, int m) {
    for(int i = 1; i <= n; i++) {
        int j = i;
        while(j <= m && !A[j][i]) ++j;
        if(j == m + 1) {return false;}
        ans = max(ans, j);
        swap(A[i], A[j]);
        for(int k = 1; k <= m; ++k) if(k != i && A[k][i]) A[k] ^= A[i];
    }
    return true;
}
int n, m, t;
char str[N];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%s", str + 1);
        for(int j = 1; j <= n; j++) A[i][j] = str[j] - '0';
        scanf("%d", &t);
        A[i][n + 1] = t;
    }
    if(!Gauss(n, m)) {
        printf("Cannot Determine\n");
    }else {
        printf("%d\n", ans);
        for(int i = 1; i <= n; i++) {
            if(A[i][n + 1]) printf("?y7M#\n");
            else printf("Earth\n");
        }
    }
    return 0;
}

