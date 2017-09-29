#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, a, b, rem;
stack<int> st;
vector<char> ans;
string DFS(int n) {
    if(n == 1) return "1";
    if(n == 2) return "11";
    if(n == 3) return "111";
    if(n & 1) {
        return "[" + DFS(n / 2) + "]1";
    }else {
        return "[" + DFS(n / 2) + "]";
    }
}
int main() {
    cin >> n;
    cout << DFS(n) << endl;
    return 0;
}

