#include <bits/stdc++.h>
using namespace std;
inline bool check(int x) {
    int sum = 0;
    while(x) {
        sum += x%10; x/=10;
    }
    return sum == 10;
}
vector<int> ans;
int k;
int main() {
    for(register int i = 10; i <= 11000000; ++i) {
        if(check(i)) {
            ans.push_back(i);
        }
    }
    scanf("%d", &k);
    cout << ans[k - 1] << endl;
    return 0;
}