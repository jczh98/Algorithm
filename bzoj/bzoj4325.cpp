#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int card[100], t, n, a, b;
map<LL, int> mp;
inline LL state() {
    LL ret = 0;
    for(int i = 3; i <= 16; ++i) ret = ret * 6 + card[i] + 1;
    return ret;
}
int dfs() {
    LL st = state();
    if(st == 13) return 0;
    if(mp.count(st)) return mp[st];
    int ans = 100, flag = 0;
    //火箭，对子
    for(int i = 3; i <= 16; ++i) {
        if(card[i] >= 2) {
            card[i] -= 2;
            ans = min(ans, dfs() + 1); flag = 1;
            card[i] += 2;
        }
    }
    //炸弹
    for(int i = 3; i <= 16; ++i) {
        if(card[i] == 4) {
            card[i] -= 4;
            ans = min(ans, dfs() + 1); flag = 1;
            card[i] += 4;
        }
    }
    //三张
    for(int i = 3; i <= 16; ++i) {
        if(card[i] >= 3) {
            card[i] -= 3;
            ans = min(ans, dfs() + 1); flag = 1;
            card[i] += 3;
        }
    }
    //三带一
    for(int i = 3; i <= 16; ++i) {
        if(card[i] >= 3) {
            card[i] -= 3;
            for(int j = 3; j <= 16; ++j) {
                if(card[j] > 0) {
                    card[j] -= 1;
                    ans = min(ans, dfs() + 1); flag = 1;
                    card[j] += 1;
                }
            }
            card[i] += 3;
        }
    }
    //三带二
    for(int i = 3; i <= 16; ++i) {
        if(card[i] >= 3) {
            card[i] -= 3;
            for(int j = 3; j < 16; ++j) {
                if(card[j] >= 2) {
                    card[j] -= 2;
                    ans = min(ans, dfs() + 1); flag = 1;
                    card[j] += 2;
                }
            }
            card[i] += 3;
        }
    }
    //单顺子
    for(int i = 3; i <= 16 - 2 - 4; ++i) {
        if(card[i] && card[i + 1] && card[i + 2] && card[i + 3] && card[i + 4]) {
            card[i]--; card[i + 1]--; card[i + 2]--; card[i + 3]--; card[i + 4]--;
            ans = min(ans, dfs() + 1); flag = 1;
            int j;
            for(j = i + 5; j <= 16 - 2; ++j) {
                if(!card[j]) break;
                else {
                    card[j]--;
                    ans = min(ans, dfs() + 1);
                }
            }
            for(int l = i; l < j; ++l) card[l]++;
        }
    }
    //双顺子
    for(int i = 3; i <= 16 - 2 - 2; ++i) {
        if(card[i] >= 2 && card[i + 1] >= 2 && card[i + 2] >= 2) {
            card[i]-=2; card[i + 1]-=2; card[i + 2]-=2;
            ans = min(ans, dfs() + 1); flag = 1;
            int j;
            for(j = i + 3; j <= 16 - 2; ++j) {
                if(card[j] < 2) break;
                else {
                    card[j]-=2;
                    ans = min(ans, dfs() + 1);
                }
            }
            for(int l = i; l < j; ++l) card[l]+=2;
        }
    }
    //三顺子
    for(int i = 3; i <= 16 - 2 - 1; ++i) {
        if(card[i] >= 3 && card[i + 1] >= 3) {
            card[i]-=3; card[i + 1]-=3;
            ans = min(ans, dfs() + 1); flag = 1;
            int j;
            for(j = i + 2; j <= 16 - 2; ++j) {
                if(card[j] < 3) break;
                else {
                    card[j]-=3;
                    ans = min(ans, dfs() + 1);
                }
            }
            for(int l = i; l < j; ++l) card[l]+=3;
        }
    }  
    //四带二
    for(int i = 3; i < 16; ++i) {
        if(card[i] == 4) {
            card[i] -= 4;
            //双单
            for(int j = 3; j <= 16; ++j) {
                if(!card[j]) continue;
                card[j]--;
                for(int l = 3; l <= 16; ++l) {
                    if(!card[l]) continue;
                    card[l]--;
                    ans = min(ans, dfs() + 1); flag = 1;
                    card[l]++;
                }
                card[j]++;
            }
            //双对子
            for(int j = 3; j <= 16; ++j) {
                if(card[j] < 2) continue;
                card[j]-=2;
                for(int l = 3; l <= 16; ++l) {
                    if(card[l] < 2) continue;
                    card[l]-=2;
                    ans = min(ans, dfs() + 1); flag = 1;
                    card[l]+=2;
                }
                card[j]+=2;
            }
            card[i]+=4;
        }
    }
    if(!flag) {
        ans = 0;
        for(int i = 3; i <= 16; ++i) ans += card[i];
    }
    return mp[st] = ans;
}
int main() {
    scanf("%d%d",&t,&n);
    while(t--) {
        memset(card, 0 ,sizeof(card));
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a, &b);
            if(a == 0) card[16]++;
            else if(a == 1) card[14]++;
            else if(a == 2) card[15]++;
            else card[a]++;
        }
        mp.clear();
        printf("%d\n", dfs());
    }
    return 0;
}