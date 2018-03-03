#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> price[10000];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second < b.first * a.second;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &price[i].first, &price[i].second);
    }
    sort(price + 1, price + 1 + n, cmp);
    double ans = price[1].first * 1.0 * m / price[1].second;
    printf("%.9lf\n", ans);
    return 0;
}