#include <bits/stdc++.h>
using namespace std;
string s, t;
int sufs[100005], suft[100005], sums[100005], sumt[100005], q;
int solve(int sl, int sr, int tl, int tr) {
    int sa = min(sufs[sr], sr - sl + 1), ta = min(suft[tr], tr - tl + 1);
    int sb = sums[sr] - sums[sl - 1], tb = sumt[tr] - sumt[tl - 1];
    //cout << sa << " " << sb << " " << ta << " " << tb << endl;
    if(sb <= tb && (tb - sb) % 2 == 0) {
        if(sb == tb) {
            if(sa < ta) return 0;
            return ((sa - ta) % 3) == 0;
        }else if(sb == 0) {
            return sa > ta;
        }else return sa >= ta;
    }else return 0;
}
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> s >> t;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'B' || s[i] == 'C') sums[i + 1] = sums[i] + 1; else sums[i + 1] = sums[i];
    }
    for(int i = 0; i < t.size(); ++i) {
        if(t[i] == 'B' || t[i] == 'C') sumt[i + 1] = sumt[i] + 1; else sumt[i + 1] = sumt[i];
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'A') sufs[i + 1] = sufs[i] + 1; else sufs[i + 1] = 0;
    }
    for(int i = 0; i < t.size(); ++i) {
        if(t[i] == 'A') suft[i + 1] = suft[i] + 1; else suft[i + 1] = 0;
    }
    // for(int i = 0; i < s.size(); ++i) {
    //     cout << sums[i + 1] << " ";
    // }cout << endl;
    // for(int i = 0; i < t.size(); ++i) {
    //     cout << sumt[i + 1] << " ";
    // }cout << endl;
    scanf("%d", &q);
    while(q--) {
        int sl, sr, tl, tr;
        scanf("%d%d%d%d", &sl, &sr, &tl, &tr);
        cout << solve(sl, sr, tl, tr);
    }
    return 0;
}