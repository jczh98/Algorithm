#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3000;
LL c[N + 10][N + 10];
int n, m, q, t, r1, r2, c1, c2;
inline LL Lowbit(LL x) {return x & (-x);}
void Add(int x, int y, LL val) {
    for(int i = x; i <= n; i += Lowbit(i)) {
        for(int j = y; j <= m; j += Lowbit(j)) {
            c[i][j] += val;
        }
    }
}
LL Query(int x, int y) {
    LL ret = 0;
    for(int i = x; i > 0; i -= Lowbit(i)) {
        for(int j = y; j > 0; j -= Lowbit(j)) {
            ret += c[i][j];
        }
    }
    return ret;
}
typedef pair<pair<int, int>, pair<int, int> > p4;
map<p4, int> mp;
int main() {
    for(int i = 1; i <= 9; ++i) srand(time(0) ^ rand() ^ (rand() % 19260817));
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> t >> r1 >> c1 >> r2 >> c2;
        if(t == 1) {
            int g =  rand() << 15 | rand();
            mp[make_pair(make_pair(r1, c1), make_pair(r2, c2))] = g;
            Add(r1, c1, g); Add(r1, c2 + 1, -g); Add(r2 + 1, c1, -g); Add(r2 + 1, c2 + 1, g);
        }else if(t == 2) {
            int g = mp[make_pair(make_pair(r1, c1), make_pair(r2, c2))];
            Add(r1, c1, -g); Add(r1, c2 + 1, g); Add(r2 + 1, c1, g); Add(r2 + 1, c2 + 1, -g);
        }else if(t == 3) {
            LL a = Query(r1, c1), b = Query(r2, c2);
            if(a == b) cout << "Yes" << endl; else cout << "No" << endl;
        }
    }
    return 0;
}

