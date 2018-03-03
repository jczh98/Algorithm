#include <bits/stdc++.h>
using namespace std;
string s, ans;
int n, k, vis[1000], Max, Min = INT_MAX, flag = 0, nxt[1000];
int main() {
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < s.size(); ++i) vis[s[i]] = 1;
    for(int i = 'a'; i <= 'z'; ++i) {
        for(int j = i + 1; j <= 'z'; ++j) {
            if(vis[j]) {nxt[i] = j;break;}
        }
    }
    for(int i = 'a'; i <= 'z'; ++i) if(vis[i]) Max = max(Max, i), Min = min(Min, i);
    if(n < k) {
        for(int i = 0; i < k; ++i) {
            if(i < n) cout << s[i];
            else cout << (char)Min;
        }
        cout << endl;
        return 0;
    }
    int pos, tar;
    for(pos = k - 1; pos >= 0; --pos) {
        if(nxt[s[pos]] != 0) { tar = nxt[s[pos]];break;}
    }
    for(int i = 0; i < pos; ++i) cout << s[i]; cout << (char)tar;
    for(int i = 0; i < k - pos - 1; ++i) cout << (char)Min; cout << endl;
    return 0;
}