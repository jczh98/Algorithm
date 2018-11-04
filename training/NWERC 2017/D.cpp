#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string dutch[50], a, b, c;
vector<string> dd;
map<string, vector<string>> dic, idic;
map<string, int> cnt;
int n, m;
LL ans1 = 1, ans2 = 1, ans3 = 1;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> dutch[i];
        cnt[dutch[i]]++;
        dd.push_back(dutch[i]);
    }
    sort(dd.begin(), dd.end());
    dd.erase(unique(dd.begin(), dd.end()), dd.end());
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        if(c == "correct") {
            dic[a].push_back(b);
        }else {
            idic[a].push_back(b);
        }
    }
    int flag = 1, flag2 = 1;;
    for(int i = 0; i < dd.size(); ++i) {
        if(dic[dd[i]].size() == 1 && idic[dd[i]].size() == 0) {
            continue;
        }else if(dic[dd[i]].size() == 0 && idic[dd[i]].size() == 1) {
            flag2 = 0;
            continue;
        }
        flag = 0; break;
    }
    if(flag) {
        for(int i = 1; i <= n; ++i) {
            if(dic[dutch[i]].size() == 1) cout << dic[dutch[i]][0];
            else if(idic[dutch[i]].size() == 1) cout << idic[dutch[i]][0];
            if(i == n) cout << endl; else cout << " ";
        }
        if(flag2) cout << "correct" << endl; else cout << "incorrect" << endl;
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(dic[dutch[i]].size() || idic[dutch[i]].size()) {
            ans1 *= dic[dutch[i]].size();
            ans2 *= dic[dutch[i]].size() + idic[dutch[i]].size();
            ans3 *= dic[dutch[i]].size();
        }
    }
    cout << ans1 << " correct\n" << ans2 - ans3 << " incorrect" << endl;
    return 0;
}