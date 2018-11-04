#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
map<int, int> rndmp, cnt;
int vex[N], n, f[N], ff[N], Xor, u[N], v[N], has_one = 0;
vector<int> used;
int rnd() {
    while(true) {
        // std::uniform_int_distribution<int> distribution(1,1000000000);
        // int x = distribution(random);
        int x = rand() % 1000000000 + 1;
        if(rndmp.count(x)) continue;
        rndmp[x] = 1;
        return x;
    }
}
int main() {
    srand(time(NULL));
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]); has_one += (f[i] == 1);
    }
    Xor = n;
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u[i], &v[i]); Xor ^= u[i]; Xor ^= v[i];
        vex[u[i]] += 1; vex[u[i]] %= 2;
        vex[v[i]] += 1; vex[v[i]] %= 2;
    }
    for(int i = 1; i <= n; ++i) {
        if(vex[i] && f[i]) used.push_back(i);
    }
    if(!Xor) {
        printf("%d\n", n);
        for(int i = 1; i < n; ++i) {
            printf("%d %d\n", u[i], v[i]);
        }
        return 0;
    }
    if(Xor && !has_one) {
        printf("-1\n");
        return 0;
    }
    for(int t = 1; t <= 3; ++t) {
        rndmp.clear();
        for(int i = 1; i <= n; ++i) if(!f[i]) rndmp[i] = 1;
        for(int i = 1; i <= n; ++i) {
            if(f[i]) ff[i] = rnd(); else ff[i] = i;
        }
        // for(int i = 1; i <= n; ++i) {
        //     cout << ff[i] << " ";
        // }cout << endl;
        Xor = n;
        for(int i = 1; i <= n; ++i) {
            if(vex[i]) Xor ^= ff[i];
        }
        if(Xor) {
            if(used.size()==0)continue;
            int p = rand() % used.size();
            ff[used[p]] ^= Xor;
        }
        int flag = 0;
        for(int i = 1; i <= n; ++i) {
            if(!ff[i] || ff[i] > 1e9) flag = 1;
        }
        if(flag) continue;
        cnt.clear(); flag = 0;
        for(int i = 1; i <= n; ++i) {
            if(cnt.count(ff[i])) {
                flag = 1; break;
            }else {
                cnt[ff[i]] = 1;
            }
        }
        if(flag) continue;
        printf("%d\n", n);
        for(int i = 1; i < n; ++i) {
            printf("%d %d\n", ff[u[i]], ff[v[i]]);
        }
        return 0;
    }
    printf("-1\n");
    return 0;
}