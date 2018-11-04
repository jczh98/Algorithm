#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n, a[100005];
LL k;
vector<int> b;
bool check(int x) {
    int r = 0, sum = 0; LL num = 0;
    for(int i = 1; i <= n; ++i) {
        while(r <= n && sum < 2) {
            ++r;
            if(a[r] >= x) sum++;
        }
        if(sum >= 2) num += n - r + 1;
        if(a[i] >= x) sum--;
    }
    return num >= k;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%lld", &n, &k);
        b.clear();
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), b.push_back(a[i]);
        sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());
        int l = 0, r = b.size() - 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(b[mid])) {
                l = mid + 1; ans = mid;
            }else r = mid - 1;
        }
        cout << b[ans] << endl;
    }
    return 0;
}