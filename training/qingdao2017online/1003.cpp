#include <bits/stdc++.h>
using namespace std;
#define N 200005
int trans[N][26], pa[N], Maxlen[N], sz, root, last, Right[N];
inline void InitSam() {
    root = last = sz = 1;
}
inline void Extend(int c, int x) {
    int p = last, np = ++sz; last = np; Maxlen[np] = x; Right[np] = 1;
    for(;p && !trans[p][c]; p = pa[p]) trans[p][c] = np;
    if(!p) {
        pa[np] = root;
    }else {
        int q = trans[p][c];
        if(Maxlen[q] == Maxlen[p] + 1) {
            pa[np] = q;
        }else {
            int nq = ++sz;
            memcpy(trans[nq], trans[q], sizeof(trans[q]));
            pa[nq] = pa[q]; Maxlen[nq] = Maxlen[p] + 1; pa[q] = pa[np] = nq;
            for(;trans[p][c] == q; p = pa[p]) trans[p][c] = nq;
        }
    }
}
inline bool Judge(string s) {
    int now = root;
    for(int i = 0; i < s.size(); ++i) {
        if(!trans[now][s[i] - 'a']) return false;
        now = trans[now][s[i] - 'a'];
    }
    return true;
}
int t, n, mx_len, mx_id, flag, lastlen;
string str, mx_s;
char s[100005];
vector<string> sv;
int main() {
    scanf("%d", &t);
    while(t--) {
        InitSam();
        for(int i = 0; i < lastlen * 2; i++) {
            memset(trans[i], 0, sizeof(trans[i])); Maxlen[i] = 0; Right[i] = 0;
        }
        sv.clear();
        mx_len = mx_id = flag = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            str = s;
            sv.push_back(str);
            if(mx_len < str.size()) {
                mx_len = str.size(); mx_id = i; mx_s = s;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(sv[i].size() == mx_len) {
                if (sv[i] != mx_s) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) {
            printf("No\n");
        }else {
            for(int i = 0; i < mx_s.size(); ++i) {
                Extend(mx_s[i] - 'a', i + 1);
            }
            int flag = 1;
            for(int i = 0; i < n; ++i) {
                if(sv[i].size() == mx_len) continue;
                if(!Judge(sv[i])) flag = 0;
            }
            if(flag) {
                printf("%s\n", mx_s.c_str());
            }else {
                printf("No\n");
            }
        }
        lastlen = mx_len;
    }
    return 0;
}