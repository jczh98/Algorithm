#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, a[100], b[100];
vector<LL> mul;
vector<LL> ans;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++i) {
        mul.clear();
        for(int j = 1; j <= m; ++j) {
            for(int k = 1; k <= n; ++k) {
                if(k == i) continue;
                mul.push_back(1LL * a[k] * b[j]);
            }
        }
        sort(mul.begin(), mul.end());
        ans.push_back(mul[mul.size() - 1]);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}