#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
inline int ReadInt() {
    static int n, ch;
    n = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
    return n;
}

const int maxn = 100 + 3;
struct edge {
    int from, to, realCost;
    double cost;
    edge(int from, int to, int realCost): from(from), to(to), realCost(realCost), cost(realCost) {}
    bool operator < (const edge &ano) const {
        return cost < ano.cost;
    }
};

vector<edge> edges;
int n, m, fa[maxn];

inline void init(int n) {
    for (int i = 0; i < n; ++i) fa[i] = i;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void unite(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
}

int Kruskal_min() {
    int ans = 0, cnt = 0;
    init(n);
    for (int i = 0; i < (int)edges.size(); ++i) {
        const edge &e = edges[i];
        if (find(e.to) != find(e.from)) {
            unite(e.to, e.from);
            ans += e.cost;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    return ans;
}

int Kruskal_max() {
    int ans = 0, cnt = 0;
    init(n);
    for (int i = (int)edges.size() - 1; ~i; --i) {
        const edge &e = edges[i];
        if (find(e.to) != find(e.from)) {
            unite(e.to, e.from);
            ans += e.cost;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    return ans;
}
typedef long long ll;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll rel;
vector<int> tree;
double calc(int sum) {
    double avg = (double)sum / (n - 1), ans = 0;
    int cnt = 0;
    int realavg = 0;
    rel = 0;
    tree.clear();
    init(n);
    for (int i = 0; i < (int)edges.size(); ++i) edges[i].cost = (edges[i].realCost - avg) * (edges[i].realCost - avg);
    sort(edges.begin(), edges.end());
    for (int i = 0; i < (int)edges.size(); ++i) {
        const edge &e = edges[i];
        if (find(e.to) != find(e.from)) {
            unite(e.to, e.from);
            ans += e.cost;
            rel += e.realCost;
            tree.push_back(e.realCost);
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    return ans / (n - 1);
}
ll relavg = 0, relans = 0;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        relans = 0;
        edges.clear();
        n = ReadInt(), m = ReadInt();
        for (int i = 0; i < m; ++i) {
            int f = ReadInt() - 1, t = ReadInt() - 1, c = ReadInt();
            edges.push_back(edge(f, t, c));
        }
        sort(edges.begin(), edges.end());
        int l = Kruskal_min(), r = Kruskal_max();
        double ans = 1e300;
        vector<int> ans3;
        for (int i = l; i <= r; ++i) {
            double tmp = calc(i);
            if(ans > tmp) {
                ans = tmp;
                relavg = rel;
                ans3 = tree;
            }
        }
        relavg = relavg * qpow(n - 1, MOD-2, MOD) % MOD;
        for(int i = 0; i < ans3.size(); ++i) {
            relans = (relans + (((ans3[i] - relavg + MOD) % MOD) * ((ans3[i] - relavg + MOD) % MOD)) % MOD) % MOD;
        }
        relans = relans * qpow(n - 1, MOD-2, MOD) % MOD;
        printf("%lld\n", relans);        
    }

    return 0;
}