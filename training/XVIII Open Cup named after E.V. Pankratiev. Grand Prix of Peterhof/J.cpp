#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string n;
const int N = 20;
const ll P[N] = {1019880619, 99988619, 19260817, 1000000007, 1000000009, 100000837, 99989711, 99990337, 99990389, 99990419, 99990461, 99990467, 99990487, 99990491, 99990493, 99990511, 99990533, 99990547, 99990551, 99990571};
ll qpow(ll a,ll b,ll mod) {
	ll ans=1;
	a=a%mod;
	while(b!=0) {
		if(b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
bool check(string n, ll mod) {
	ll nn = 0;
	int len = n.size();
	for(int i = 0; i < len; ++i) {
		nn = (nn * 10 + n[i] - '0') % mod;
	}
//	cout << qpow(nn, (mod-1LL)/2LL, mod) << endl;
	if(qpow(nn, (mod-1LL)/2LL, mod) == 1LL) return true;
	return false;
}
ll toint(string a) {
	ll res;
	stringstream ss;
	ss << a;
	ss >> res;
	return res;
}

int main() {
	cin >> n;
	int len = n.size();
	if(len <= 15) {
		ll a = toint(n);
		ll tmp = ll(sqrt((double)a + 0.1) + 0.1);
		if(tmp * tmp == a)	cout << "Yes" << endl;
		else	cout << "No" << endl;
		return 0;
	}
	int flag = 0;
//	cout << check(n, P[1]) << endl;
	for(int i = 0; i < N; ++i) {
		if(!check(n, P[i])) flag = 1;
	}
	if(flag) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
