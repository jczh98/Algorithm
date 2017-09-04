#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1000000, MOD = 1e9+7;
ll inv[N + 1], f[N + 1], fi[N + 1];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	inv[1] = 1;
	for (int i = 2; i <= N; i++)
		inv[i] = -MOD / i * inv[MOD % i] % MOD;
	f[0] = fi[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = f[i - 1] * i % MOD;
		fi[i] = fi[i - 1] * inv[i] % MOD;
	}
	int H, W; cin >> H >> W;
	int d = gcd(H, W);
	ll sum = 0;
	for (int y = 0; y <= d; y++) {
		int x = d - y;
		if (gcd(H, y) == 1 && gcd(W, x) == 1)
			sum = (sum + f[d] * fi[y] % MOD * fi[x]) % MOD;
	}
	cout << (sum + MOD) % MOD << endl;
}
