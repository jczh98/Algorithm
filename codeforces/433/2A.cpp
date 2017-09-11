#include <bits/stdc++.h>
using namespace std;
int n, down, ans_up = 1, ans_down = 100000;
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int j = n - i;
        if (j < i)
            if (__gcd(i, j) == 1) {
                cout << j << " " << i << endl;
                return 0;
            }
    }
    return 0;
}

