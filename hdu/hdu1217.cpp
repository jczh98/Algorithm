#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 105;
int n, m, kase = 1;
map<string, int> mp;
string s, a, b;
double d[N][N];
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] < d[i][k] * d[k][j])
                    d[i][j] = d[i][k] * d[k][j];
}
int main() {
    while (cin >> n) {
        if(!n) break;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++) {
            cin >> s; mp[s] = i;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            double w;
            cin >> a >> w >> b;
            d[mp[a]][mp[b]] = w;
        }
        floyd();
        double Max = 0;
        for (int i = 1; i <= n; i++) Max = max(d[i][i], Max);
        cout << "Case " << kase++ << ": ";
        if (Max > 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
