#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k, d, t;
int main() {
    cin >> k >> d >> t;
    if (k % d == 0) {
        cout << t << endl;
        return 0;
    }
    LL p = k / d + 1; d = d * p;
    if (d > k) {
        double T = d, before = k, after = d - k;
        if (t > before + after / 2) {
            LL times = t / (before + after / 2);
            double rem = t - times * (before + after / 2);
            if (rem > before) {
                printf("%.6f\n", times * T + before + (rem - before) * 2);
            }else {
                printf("%.6f\n", times * T + rem);
            }
        }else {
            if (t > before) {
                printf("%.2f\n", before + (t - before) * 2);
            }else{
                cout << t << endl;
            }
        }
    }
    return 0;
}
