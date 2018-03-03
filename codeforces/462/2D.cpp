#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p, k;
vector<int> ans;
int main() {
    cin >> p >> k;
    while(p) {
        LL rem = p % -k;
        p /= -k;
        if(rem < 0) {
            rem += k; p++;
        }
        ans.push_back(rem);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        cout << (i == ans.size() - 1 ? "\n" : " ");
    }
    return 0;
}