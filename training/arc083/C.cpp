#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int a, b, c, d, e, f;
int dp[10000], ans_up = 0, ans_down = 1;
vector<pii > ans;
bool cmp(pii a, pii b) {
    return (a.first) * (b.first + b.second) > (b.first) * (a.first + a.second);
}
double des = -9999999.0;
int answ = 0,anst = 0;
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    for(int ia = 0; ia <= a; ia++) {
        for(int ib = 0; ib <= b; ib++) {
            if(ia == 0 && ib == 0) continue;
            memset(dp, 0, sizeof(dp));
            int cur_water = ia * a + ib * b, res = 0;
            if(cur_water * 100 > f) continue;
            for(int j = c; j <= cur_water * e ; j++) {
                dp[j] = max(dp[j - c] + c, dp[j]);
                if(dp[j] + cur_water <= f){
                    res = max(res, dp[j]);
                }
            }
            for(int j = d; j <= cur_water * e ; j++) {
                dp[j] = max(dp[j - d] + d, dp[j]);
                if(dp[j] + cur_water <= f){
                    res = max(res, dp[j]);
                }
            }
            ans.push_back(make_pair(res, cur_water));
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << answ << " " << anst << endl;
    cout << ans[0].first + ans[0].second * 100 << " " << ans[0].first << endl;
}
