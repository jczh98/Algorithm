#include <bits/stdc++.h>
using namespace std;
string expr;
int main() {
    cin >> expr;
    int i;
    for(i = expr.size() - 1; i >= 0; --i) {
        if(expr[i] == ',') break;
    }
    for(i = i + 1; i < expr.size(); ++i) {
        if(isdigit(expr[i]) || expr[i] == '-') break;
    }
    string ans;
    for(; expr[i] != ')' && i < expr.size(); ++i) {
        ans += expr[i];
    }
    cout << ans << endl;
    return 0;
}