#include<math.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
#include<vector>
using namespace std;
ll MOD = 1e9 + 7;
ll quickmod(ll a,ll b,ll mod) {
	ll ans=1;
	a=a%mod;
	while(b!=0) {
		if(b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
ll dp[100005];
int main() {
	ll t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		ll len = s.size();
		int cur = s.size() - 1;

		dp[0] = quickmod(2,len-1,MOD);
		ll last = len - 1;
		ll coun = 0;
		for(int i=1; i<len; i++) {
			dp[i] = (dp[i-1] - quickmod(2,last,MOD) * quickmod(10,coun,MOD) % MOD + MOD) % MOD;
//			cout << dp[i] << endl;
			dp[i] += quickmod(2,last-1,MOD) * quickmod(10,coun + 1,MOD) % MOD;
			dp[i] = dp[i] % MOD;
//			cout << dp[i] << endl;
			dp[i] += quickmod(2,last-1,MOD) * quickmod(10,coun,MOD) % MOD;
			dp[i] = dp[i] % MOD;
//			cout << dp[i] << endl;
			last--;
			coun++;
		}
		ll ans = 0;
		for(int i=0; i<len; i++) {
			ans += dp[i] * (s[len-i-1] - '0') % MOD;
			ans = ans % MOD;
		}
		cout << ans << endl;
	}

	return 0;
}
