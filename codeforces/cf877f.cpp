#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
int n, k, t[MAXN], a[MAXN], q, block, pos[MAXN], Hash[MAXN], HashL[MAXN], HashR[MAXN];
LL ans = 0, data[MAXN], sum[MAXN];
LL Count[5000005];
vector<LL> All;
struct Query {
    int l, r, id;
    friend bool operator < (const Query a, const Query b) {
        return pos[a.l] == pos[b.l] ? a.r < b.r : pos[a.l] < pos[b.l];
    }
}query[MAXN];
inline void InsR(int x) {ans += Count[HashL[x]];Count[Hash[x]]++;}
inline void InsL(int x) {ans += Count[HashR[x]];Count[Hash[x]]++;}
inline void DecR(int x) {Count[Hash[x]]--;ans -= Count[HashL[x]];}
inline void DecL(int x) {Count[Hash[x]]--;ans -= Count[HashR[x]];}
int main() {
    scanf("%d%d", &n, &k);block = sqrt(n * 1.0);
    for(register int i = 1; i <= n; ++i) scanf("%d", &t[i]);
    for(register int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(t[i] == 2) a[i] *= -1;
        sum[i] = sum[i - 1] + a[i] * 1LL;
        pos[i] = (i - 1) / block + 1;
        All.push_back(sum[i]); All.push_back(sum[i] - k); All.push_back(sum[i] + k);
    }
    All.push_back(sum[0]); All.push_back(sum[0] - k); All.push_back(sum[0] + k);
    sort(All.begin(), All.end());
    All.resize(unique(All.begin(), All.end()) - All.begin());
    for(int i = 0; i <= n; ++i) {
        Hash[i] = lower_bound(All.begin(), All.end(), sum[i]) - All.begin();
        HashL[i] = lower_bound(All.begin(), All.end(), sum[i] - k) - All.begin();
        HashR[i] = lower_bound(All.begin(), All.end(), sum[i] + k) - All.begin();
    }
    int zero = lower_bound(All.begin(), All.end(), 0) - All.begin();
    scanf("%d", &q); 
    for(register int i = 1; i <= q; ++i) {
        scanf("%d%d", &query[i].l, &query[i].r); query[i].id = i;
    }
    sort(query + 1, query + 1 + q);
    register int L = 1, R = 0; Count[zero]++;
    for(register int i = 1; i <= q; ++i) {
        while(R < query[i].r) {++R;InsR(R);}
        while(R > query[i].r) {DecR(R);--R;}
        while(L < query[i].l) {DecL(L - 1);++L;}
        while(L > query[i].l) {--L;InsL(L - 1);}
        data[query[i].id] = ans;
    }
    for(register int i = 1; i <= q; ++i) printf("%I64d\n", data[i]);
    return 0;
}