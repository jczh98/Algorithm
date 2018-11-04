#include <bits/stdc++.h>
using namespace std;
const int N = 24, NN = 1 << 24, inf = 0x3f3f3f3f;
pair<int, int> dp[NN];
int w[N], n, s;
int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < (1 << n); ++i) dp[i] = make_pair(inf, 0);
    dp[0] = make_pair(0, s);
    for (int S = 0; S < (1 << n); ++S) {
        for (int j = 0; j < n; ++j) {
            if (S & (1 << j)) {
                pair<int, int> last = dp[S ^ (1 << j)], np;
                if (last.second + w[j] <= s) {
                    np = make_pair(last.first, last.second + w[j]);
                } else {
                    np = make_pair(last.first + 1, w[j]);
                }
                if (np < dp[S]) dp[S] = np;
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}