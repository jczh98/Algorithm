#include <bits/stdc++.h>
using namespace std;
int num[100005], Min[100005], Max[100005], mn, mi;
string a;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    cin >> a;
    for (int i = 5; i <= n; i++) {
        mn = -1e9 - 1;
        for (int j = 0; j <= 4; j++) {
            mn = max(mn, num[i - j]);
        }
        Max[i] = mn;
    }
    for (int i = 5; i <= n; i++) {
        mi = 1e9 + 1;
        for (int j = 0; j <= 4; j++) {
            mi = min(mi, num[i - j]);
        }
        Min[i] = mi;
    }
    int l = -1e9, r = 1e9;
    for (int i = 4; i <= n - 1; i++) {
        if (a[i] == '1' && a[i - 1] == '0') {
            l = max(l, Max[i + 1] + 1);
        }
        if (a[i] == '0' && a[i - 1] == '1') {
            r = min(r, Min[i + 1] - 1);
        }
    }
    cout << l << " " << r << endl;
    return 0;
}
