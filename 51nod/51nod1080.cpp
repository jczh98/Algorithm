#include <bits/stdc++.h>
using namespace std;
int n, flag = 1;
unordered_map<int, int> mp;
int main() {
    scanf("%d", &n);
    for(int i = 0; i * i <= n; ++i) mp[i * i] = i;
    for(int i = 0; i * i <= n; ++i) if(mp[n - i * i] && mp[n - i* i] >= i) flag = 0, printf("%d %d\n", i, mp[n - i * i]);
    if(flag) printf("No Solution\n");
    return 0;
}

