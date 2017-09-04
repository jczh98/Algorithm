#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

const int MX = 105, MM = 35, n10 = 1<<10;

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x(x){}
	mint operator+=(mint a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(mint a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(mint a){ (x*=a.x)%=mod; return *this;}
	mint operator+(mint a){ return mint(*this) += a;}
	mint operator-(mint a){ return mint(*this) -= a;}
	mint operator*(mint a){ return mint(*this) *= a;}
};
//

int n, m, k;
int a[MX];
mint dp[MX][n10][MM];

int f(int x){
	int res = 0, pre = -1;
	rep(i,k){
		if((x&1) != pre) res++;
		pre = (x&1); x >>= 1;
	}
	return res-1;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,n-1) scanf("%d",&a[i+1]);
	dp[0][0][0] = 1;
	rep(i,n)rep(j,1<<k)rep(r,m){
		int nxtm = (r+f(j)*a[i])%m;
		dp[i+1][j][nxtm] += dp[i][j][r];
		rep(l,k){
			if(j>>l&1) continue;
			dp[i+1][j|1<<l][nxtm] += dp[i][j][r];
		}
	}
	
	cout << dp[n][(1<<k)-1][0].x << endl;
	return 0;
}
