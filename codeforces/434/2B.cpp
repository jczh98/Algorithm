#include<bits/stdc++.h>
using namespace std;
int n, m, k[1000], f[1000];
bool Judge(int x) {
    for(int i = 1; i <= m; ++i) {
        if((k[i] - 1) / x + 1 != f[i]) return false;
    }
    return true;
}
int flag = 0, ans;
set<int> st;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &k[i], &f[i]);
    }
    for(int i = 1; i <= 100; ++i) {
        if(Judge(i)) {
            st.insert(n % i ? n / i + 1 : n / i);
        }
    }
    if(st.size() > 1 || !st.size()) cout << -1 << endl;
    else cout << *st.begin() << endl;
    return 0;
}

