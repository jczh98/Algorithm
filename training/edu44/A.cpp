#include <bits/stdc++.h>
using namespace std;
int n, p[1000], odd = 0, even = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n / 2; ++i) {
        scanf("%d", &p[i]);
    }
    sort(p + 1, p + 1 + n / 2);
    for(int i = 1; i <= n / 2; ++i) {
        if(p[i] != i * 2) {
            even += abs(i * 2 - p[i]);
        }
    }
    for(int i = 1; i <= n / 2; ++i) {
        if(p[i] != i * 2 - 1) {
            odd += abs(i * 2 - 1 - p[i]);
        }
    }
    cout << min(odd, even) << endl;
    return 0;
}