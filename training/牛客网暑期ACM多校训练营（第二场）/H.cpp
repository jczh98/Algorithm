#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, val[400005];
vector<int> G[400005];
LL dp[400005][4][2];
void dfs(int u, int fa) {
	LL a[4][3], b[4][3];
	memset(a, 0, sizeof(a));
	for(auto v : G[u]) {
		if(v == fa) continue; dfs(v, u);
		memset(b, 0, sizeof(b));
		for(int j = 0; j <= 3; ++j) {
			for(int k = 0; k + j <= 3; ++k) {
				b[j+k][0] = max(b[j+k][0], a[j][0] + dp[v][k][0]);
			}
		}
		for(int j = 0; j <= 3; ++j) {
			for(int k = 0; k + j <= 3; ++k) {
				if(j > 0) b[j+k][1] = max(b[j+k][1], a[j][1] + dp[v][k][0]);
				if(k > 0) b[j+k][1] = max(b[j+k][1], a[j][0] + dp[v][k][1]);
			}
		}
		for(int j = 0; j <= 3; ++j) {
			for(int k = 0; k + j <= 3; ++k) {
				b[j+k][2] = max(b[j+k][2], a[j][2] + dp[v][k][0]);
			}
		}
		for(int j = 1; j <= 3; ++j) {
			for(int k = 1; k + j <= 4; ++k) {
				b[j+k-1][2] = max(b[j+k-1][2], a[j][1] + dp[v][k][1] + val[u]);
			}
		}
		memcpy(a, b, sizeof(b));
	}
	for(int j = 1; j <= 3; ++j) {
		dp[u][j][0] = max(dp[u][j][0], a[j][0]);
		dp[u][j][0] = max(dp[u][j][0], a[j][1] + val[u]);
		dp[u][j][0] = max(dp[u][j][0], a[j][2]);
		dp[u][j][1] = a[j][1] + val[u];
	}
}
int main() {
	int u, v;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &val[i]);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1, 0);
	LL ans = 0;
	for(int i = 1; i <= 3; ++i) {
		ans = max(ans, dp[1][i][0]);
		ans = max(ans, dp[1][i][1]);
	}
	cout << ans << endl;
	return 0;
}