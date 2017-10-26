#include <bits/stdc++.h>
using namespace std;
int n;
string str[70005];
unordered_map<string, int> Hash, tmp;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> str[i];
    for(int i = 1; i <= n; ++i) {
        tmp.clear();
        for(int len = 1; len <= str[i].size(); ++len) {
            for(int j = 0; j + len - 1< str[i].size(); ++j) {
                if(tmp.find(str[i].substr(j, len)) == tmp.end()) {
                    Hash[str[i].substr(j, len)]++;
                }
                tmp[str[i].substr(j, len)] = 1;
                //cout << str[i].substr(j, len) << endl;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        int flag = 1;
        for(int len = 1; len <= str[i].size() && flag; ++len) {
            for(int j = 0; j + len - 1< str[i].size(); ++j) {
                if(Hash[str[i].substr(j, len)] == 1) {
                    flag = 0;
                    cout << str[i].substr(j, len) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}