#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL N = 100;
string readin;
int cnt[20], card[200], remain[20], len;
LL fac[200], inv[200], ans;
int main() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % MOD;
    inv[1]=1;
    for (int i = 2; i <= N; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    while(cin >> readin) {
        len = 0; ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(remain, 0, sizeof(remain));
        for(int i = 0; i < readin.size(); ++i) {
            if(readin[i] == '1') {
                card[++len] = 10; i++; cnt[10]++;
            }else if(readin[i] == 'A') {
                card[++len] = 1; cnt[1]++;
            }else if(readin[i] == 'J') {
                card[++len] = 11; cnt[11]++;
            }else if(readin[i] == 'Q') {
                card[++len] = 12; cnt[12]++;
            }else if(readin[i] == 'K') {
                card[++len] = 13; cnt[13]++;
            }else card[++len] = readin[i] - '0', cnt[readin[i] - '0']++;
        }
        for(int i = 1; i <= 13; ++i) remain[i] = 4 - cnt[i];
        for(int i = 1; i <= len; ++i) {
            for(int j = 1; j < card[i]; ++j) {
                if(!remain[j]) continue;
                LL num = fac[52 - len - i];
                for(int k = 1; k <= 13; ++k) {
                    if(!remain[k]) continue;
                    for(int l = 1; l < remain[k]; ++l) num = (num * inv[l]) % MOD;
                    if(k != j) num = (num * inv[remain[k]]) % MOD;
                }
                ans = (ans + num) % MOD;
            }
            if(!remain[card[i]]) break;
            else {
                remain[card[i]]--;
                int sum = 0;
                for(int j = 1; j <= 13; ++j) sum += remain[j];
                if(sum == 0 ) {
                    if(i <= len - 1) ans = (ans + 1) % MOD; break;
                }
            }
        }
        cout << ans << endl;
    } 
    
    return 0;
}