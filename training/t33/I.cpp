#include <bits/stdc++.h>
using namespace std;
inline int Max(int a, int b) {
    return a > b ? a : b;
}
inline void read(int &x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
}
inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
int fa[100005], sz[100005];
int Find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}
int city[1000005], state[1000005];
int N;
inline void Init(int x) {
    N = x;
    memset(city, 0, sizeof(city));
    memset(state, 0, sizeof(state));
}
inline void Add(int x, int v1, int v2) {
    while (x <= N) {
        state[x] += v1;
        city[x] += v2;
        x += (x & -x);
    }
}
inline int Sum(int * C, int x) {
    int res = 0;
    while (x > 0) {
        res += C[x];
        x -= (x & -x);
    }
    return res;
}
int t, n, m, low[100005], high[100005], _Max, x, y;
inline void Link(int u, int v) {
    x = Find(u), y = Find(v);
    if (x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    if (sz[x] > 1) {
        Add(low[x], -1, -sz[x]);
        Add(high[x], 1, sz[x]);
    }
    if (sz[y] > 1) {
        Add(low[y], -1, -sz[y]);
        Add(high[y], 1, sz[y]);
    }
    fa[x] = y;
    sz[y] += sz[x];
    low[y] = min(low[x], low[y]);
    high[y] = max(high[x], high[y]);
    Add(low[y], 1, sz[y]);
    Add(high[y], -1, -sz[y]);
}

char str[10];
int a, b, s;

int main() {
    read(t);
    while (t--) {
        _Max = 0;
        read(n);
        for (register int i = 1; i <= n; i++) {
            read(a);
            read(b);
            fa[i] = i;
            sz[i] = 1;
            low[i] = b;
            high[i] = b;
            _Max = Max(_Max, b);
        }
        Init(_Max);
        read(m);
        while (m--) {
            scanf("%s", str);
            if (str[0] == 'r') {
                read(a); read(b);
                Link(a + 1, b + 1);
            } else {
                read(s);
                read(a);
                write(Sum(state, s)); putchar(' ');
                write(Sum(city, s)); putchar('\n');
            }
        }
    }
    return 0;
}