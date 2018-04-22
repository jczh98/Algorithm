#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100, MOD = 1e9 + 7;
int n, k, a, b;
LL T[N][N], S[N][N], ans[N][N];
inline void matrix_mul(LL a[N][N], LL b [N][N], int sz) {
    LL tmp[N][N];
    memset(tmp, 0, sizeof tmp);
    for(int i = 1; i <= sz; ++i) {
        for(int j = 1; j <= sz; ++j) {
            for(int k = 1; k <= sz; ++k) {
                tmp[i][j] = (tmp[i][j] +  a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(a, tmp, sizeof tmp);
}
inline void matrix_sum(LL a[N][N], LL b[N][N], int sz) {
    for(int i = 1; i <= sz; ++i) {
        for(int j = 1; j <= sz; ++j) {
            a[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
}
inline void matrix_sub(LL a[N][N], LL b[N][N], int sz) {
    for(int i = 1; i <= sz; ++i) {
        for(int j = 1; j <= sz; ++j) {
            a[i][j] = ((a[i][j] - b[i][j]) % MOD + MOD) % MOD;
        }
    }    
}
inline void matrix_pow(LL a[N][N], int b, int sz) {
    LL tmp[N][N];
    memset(tmp, 0, sizeof tmp);
    for(int i = 1; i <= sz; ++i) tmp[i][i] = 1;
    while(b) {
        if(b & 1) matrix_mul(tmp, a, sz);
        matrix_mul(a, a, sz); b >>= 1;
    }
    memcpy(a, tmp, sizeof tmp);
}
inline void matrix_print(LL a[N][N], int sz) {
    for(int i = 1; i <= sz; ++i) {
        for(int j = 1; j <= sz; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
inline LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
// P(x) = \sum_{i=2}^{x-1} T^{x - i} * S * T^{i - 2}
void calc(LL a[N][N], int x) {
    if(x == 0) {
        memcpy(a, T, sizeof(T));
        matrix_mul(a, S, k);
        return;
    }
    if(x & 1) {
        // P(x) = P(x - 1) * T + T^{x+1} * S
        LL ret[N][N];
        memcpy(ret, T, sizeof(T));
        matrix_pow(ret, x + 1, k);
        matrix_mul(ret, S, k);
        calc(a, x - 1);
        matrix_mul(a, T, k);
        matrix_sum(a, ret, k);
    }else {
        // P(x) = P(x / 2) * T^{x / 2} + T^{x / 2} * P(x / 2) - T^{x/2 + 1} * S * T^{x/2}
        LL T2[N][N], ret1[N][N], ret2[N][N];
        memcpy(T2, T, sizeof(T));
        matrix_pow(T2, x >> 1, k); 
        calc(a, x >> 1);
        memcpy(ret1, a, sizeof T);
        matrix_mul(ret1, T2, k);
        memcpy(ret2, T2, sizeof T2);
        matrix_mul(ret2, a, k);
        matrix_sum(ret1, ret2, k);

        memcpy(ret2, T, sizeof(T));
        matrix_mul(ret2, T2, k);
        matrix_mul(ret2, S, k);
        matrix_mul(ret2, T2, k);
        matrix_sub(ret1, ret2, k);
        memcpy(a, ret1, sizeof ret1);
    }
    return;
}
int main() {
    scanf("%d%d%d%d", &n, &k, &a, &b);
    for(int i = 1; i <= k; ++i) {
        T[i][i] = T[i][i - 1] = T[i][i + 1] = 1;
        if(i >= a + 1 && i <= b - 1) S[i][i] = S[i][i - 1] = S[i][i + 1] = 1;
    }
    // LL comp[N][N];
    // for(int i = 2; i <= n - 1; ++i) {
    //     LL T1[N][N], T2[N][N], T3[N][N];
    //     memcpy(T1, T, sizeof(T)); memcpy(T2, T, sizeof(T));
    //     matrix_pow(T1, n - i, k); matrix_pow(T2, i - 2, k);
    //     matrix_mul(T1, S, k); matrix_mul(T1, T2, k);
    //     matrix_sum(comp, T1, k);
    // }
    // cout << "origin:" << endl; matrix_print(comp, k);
    calc(ans, n - 3);
    LL inv = qpow(n - 2, MOD - 2, MOD);
    //cout << "T:" << endl; matrix_print(T, k);
    //cout << "S:" << endl; matrix_print(S, k);
    //cout << "Pre:" << endl; matrix_print(ans, k);
    cout << (ans[k / 2][k / 2] * inv) % MOD<< endl;
    return 0;
}