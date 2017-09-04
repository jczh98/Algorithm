#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
vector<int> vec;
int n, a, sqare = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(cnt[a]) {
            vec.push_back(a);
        }
        cnt[a]++;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    if(vec.size() > 0 && cnt[vec[0]] >= 4) {
        sqare = 1;
    }
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if(vec.size() >= 2) {
        if(sqare) {
            printf("%lld\n", (long long) vec[0] * (long long ) vec[0]);
        }else {
            printf("%lld\n", (long long) vec[0] * (long long ) vec[1]);
        }
    }else {
        printf("0\n");
    }
    return 0;
}
