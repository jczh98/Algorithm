#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
int n;
ULL b[100005];
vector<ULL> sta;
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(b[i] < 128) {
            sta.push_back(b[i]);
            ULL ret = 0, ind = 1ULL;
            for(int j = 0; j < (int)(sta.size() - 1); ++j) {
                //cout << sta[j] << " ";
                ret += (sta[j] - 128) * ind; ind *= 1ULL * 128;
            }
            //cout << endl;
            if(sta.size() >= 1) ret += sta[sta.size() - 1] * ind;
            if(!ret) {
                cout << ret << endl;
            }else if(ret & 1) {
                printf("%-llu\n", (ret + 1ULL))
                cout << -(ret + 1) / 2 << endl;
            }else {
                cout << ret / 2 << endl;
            }
            sta.clear();
        }else sta.push_back(b[i]);
    }
    return 0;
}