#include <bits/stdc++.h>
using namespace std;
const int N = 262145;
unordered_map<string, int> a, b;
string c, d, e, g, h;
int i, j, q, u, v, t, l;
int n, m;
unordered_map<string, int>::iterator p;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> c;
    a[c] = 1;
    for (i = n; i >= 1; --i) {
        for (p = a.begin(); p != a.end(); p++) {
            d = p->first;
            if(a[d] == 0) continue;
            e="";
            g="";
            h="";
            l = (1<<i);
            for (j = 0; j < l; j += 2) {
                u = d[j]-'0';
                v = d[j + 1]-'0';
                e.push_back((u&v)+'0');
                g.push_back((u|v)+'0');
                h.push_back((u^v)+'0');
            }
            b[e] += a[d];
            b[g] += a[d];
            b[h] += a[d];
        }
        a = b;
        b.clear();
    }
    cout << a["1"];
    return 0;
}
