#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int N=505,M=10010;
int dp[N][M],path[N][M],number[N][M],ans[N],cnt;
struct boy {
	int d,s,turn;
};
bool cmp(boy a, boy b) {
	return max(a.d, a.s) - a.s > max(b.d, b.s) - b.s;
}
boy b[N];
int main() {
	int n,c,i,j;
	cin >> n >> c;
	for(i=1; i<=n; i++) {
		cin >> b[i].d >> b[i].s;
		b[i].turn = i;
	}
	sort(b+1,b+1+n,cmp);
	for(i=0; i<=n; i++)
		for(j=0; j<=c; j++)
			dp[i][j]=-M;

	dp[0][c]=0;
	for(i=1; i<=n; i++) {
		for(j=0; j<=c; j++) {
			dp[i][j]=dp[i-1][j];
			path[i][j]=j;
			number[i][j]=0;
		}
		for(j=0; j<=c; j++) {
			if(dp[i-1][j]>=0) {
				if(j<b[i].s || j < b[i].d)	continue;
				if(dp[i-1][j]+1>dp[i][j-b[i].s]) {
					dp[i][j-b[i].s] = dp[i-1][j]+1;
					path[i][j-b[i].s] = j;
					number[i][j-b[i].s] = b[i].turn;
				}
			}
		}
	}
	int x;
	for(i=x=0; i<=c; i++) {
		if(dp[n][i]>dp[n][x]) {
			x=i;
        }
    }
	cout << dp[n][x] << endl;;
	for(i = n; i > 0; i--) {
		if(number[i][x])	ans[++cnt] = number[i][x];
		x = path[i][x];
	}
	for(i=cnt; i > 0; i--)	{
        cout << ans[i];
        if(i == 1) cout << endl; else cout << " ";
    }
    return 0;
}
