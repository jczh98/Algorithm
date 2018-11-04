#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[100], mp[100], len = 0, applen = 0;
char s[1000];
unordered_map<ll,int> mmp; 
vector<int> app, seq;
void dfs(int cur) {
    if(cur == applen) {
        //string ans = "";
        ll ans = 0;
        for(int i = 0; i < len - 1; ++i) {
            if(mp[s[i] - 'a'] > mp[s[i + 1] - 'a']) {
                //cout << ">";
                ans = ans * 3LL + 2LL;
                //ans += '>';
            }else if(mp[s[i] - 'a'] < mp[s[i + 1] - 'a']) {
                //cout << "=";
                ans = ans * 3LL + 1LL;
                //ans += '<';
            }else {
                //cout << "<";
                ans = ans * 3LL;
                //ans += '=';
            }
        }
        if(mmp.find(ans) == mmp.end()) {
            mmp[ans] = 1;
        }else {
            mmp[ans]++;
        }
        // for(int i = 0; i < app.size(); ++i) {
        //     cout << (char) (app[i] + 'a') << " " << mp[app[i]] << endl;
        // }cout << endl;
        return;
    }else {
        for(int i = 0; i <= 9; ++i) {
            if(!vis[i]) {
                vis[i] = 1;
                mp[app[cur]] = i;
                dfs(cur + 1);
                vis[i] = 0;                
            }
        }
    }
}
int main() {
    //freopen("out.txt", "w", stdout);
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; ++i) {
        app.push_back(s[i] - 'a');
    }
    sort(app.begin(), app.end());
    app.erase(unique(app.begin(), app.end()), app.end());
    applen = app.size();
    // for(int i = 0; i < app.size(); ++i) {
    //     cout << app[i] << " ";
    // }cout << endl;
    dfs(0);
    int flag = 0;
    for(unordered_map<ll,int>::iterator it = mmp.begin(); it != mmp.end(); it++) {
        //cout << it->first << endl;
        if(it->second == 1) {
            ll ans = it->first;
            while(ans) {
                seq.push_back(ans % 3); ans /= 3;
            }
            reverse(seq.begin(), seq.end());
            for(int i = 0; i < len - 1; ++i) {
                printf("%c ", s[i]);
                if(seq[i] == 2) {
                    printf("> ");
                }else if(seq[i] == 1) {
                    printf("< ");
                }else {
                    printf("= ");
                }
            }
            printf("%c\n", s[len - 1]);
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}