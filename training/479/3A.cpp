#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; ++i) {
        if(n % 10) n -= 1; else n /= 10;
    }
    cout << n << endl;
    return 0;
}