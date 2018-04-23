#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> a;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &x), a.push_back(x);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if(a[0] == 0) cout << a.size() - 1 << endl;
    else cout << a.size() << endl;
    return 0;
}