#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> container;
void dfs(int k, string gen) {
    if(k == 11) return;
    LL ret = 0;
    for(int i = 1; i < k; ++i) ret = ret * 10 + (LL) (gen[i] - '0');
    if(ret > 0) container.push_back(ret);
    dfs(k + 1, gen + '4'); 
    dfs(k + 1, gen + '7');
}
int l, r;
LL ans;
int main() {
    dfs(0, "");
    sort(container.begin(), container.end());
    container.erase(unique(container.begin(), container.end()), container.end());
    // cout << container.size() << endl;
    // for(int i = 0; i < container.size(); ++i) {
    //     cout << container[i] << endl;
    // } 
    cin >> l >> r;
    int p1 = upper_bound(container.begin(), container.end(), l) - container.begin();
    int p2 = upper_bound(container.begin(), container.end(), r) - container.begin();
    for(int i = p1; i < p2; ++i) {
        if(i == p1) {
            ans += l;
            ans += (container[i] - l) * container[i];
            continue;
        }
        if(r > container[i]) ans += (container[i] - container[i - 1]) * container[i];
    }
    if(r == container[p2 - 1]) ans += r;
    ans += (r - container[p2 - 1]) * container[p2];
    cout << ans << endl;
    return 0;
}