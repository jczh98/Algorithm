#include <bits/stdc++.h>
using namespace std;
int m, A[200005], ans[200005];
struct Node {
    int v, pos;
    bool operator < (const Node & rhs) const {
        return v < rhs.v;
    }
}B[200005];
int main() {
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &B[i].v);
        B[i].pos = i;
    }
    sort(A + 1, A + 1 + m, greater<int>());
    sort(B + 1, B + 1 + m);
    for(int i = 1; i <= m; i++) {
        ans[B[i].pos] = A[i];
    }
    for(int i = 1; i <= m; i++) {
        printf("%d%c", ans[i], i == m ? '\n' : ' ');
    }
    return 0;
}