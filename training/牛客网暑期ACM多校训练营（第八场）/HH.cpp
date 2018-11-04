#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef CX_TEST
#define Debug printf
#else
#define Debug(...)
#endif
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
 
const int mod = 1e9 + 7;
const int inv = (mod + 1) >> 1;
const int maxn = (1 << 19) + 5;
 
template <class T>
inline bool In(T &ret) {
    char c = getchar();
    if(c == EOF) return false;
    ret = 0;
    T flag = 1;
    while (c != '-' && !isdigit(c)) c = getchar();
    if(c == '-') flag = -1, c = getchar();
    while (isdigit(c)) ret = ret * 10 + (c - '0'), c = getchar();
    ret *= flag;
    return true;
}
 
int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
 
int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}
 
void FWT(int a[], int n) {
    for(int d = 1; d < n; d <<= 1)
        for(int m = d << 1, i = 0; i < n; i += m)
            for(int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = add(x, y);
                a[i + j + d] = add(x, mod - y);
            }
}
 
void UFWT(int a[], int n) {
    for(int d = 1; d < n; d <<= 1)
        for(int m = d << 1, i = 0; i < n; i += m)
            for(int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = mul(add(x, y), inv);
                a[i + j + d] = mul(add(x, mod - y), inv);
 
            }
}
 
int f[20][maxn];
 
int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    int n, m = 1 << 19, i, j, x, res = 0;
    In(n);
    for(i = 0; i < n; i++) {
        In(x);
        res ^= x;
        f[0][x] = 1;
    }
    //cout<<res<<endl;
    if(res == 0) printf("%d\n", n);
    else {
        if(f[0][res]) {
            printf("%d\n", n - 1);
            return 0;
        }
        f[0][0] = 1;
        FWT(f[0], m);
        for(i = 1; i < 19; i++) {
            for(j = 0; j < m; j++) f[i][j] = mul(f[i - 1][j], f[0][j]);
        }
 
        int l = 1, r = 18;
		for(int i = 1; i <= 18; ++i) {
			UFWT(f[i], m);
			if(f[i][res]) {
				cout << n - i - 1 << endl;
				return 0;
			}
		}
        // while(l < r) {
        //     int mid = (l + r) >> 1;
        //     UFWT(f[mid], m);
        //     if(f[mid][res]) r = mid;
        //     else l = mid + 1;
        // }
        printf("%d\n", n - l - 1);
    }
 
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}