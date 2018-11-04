#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
const ll P[N] = {1019880619, 99988619, 19260817, 1000000007, 1000000009, 100000837, 99989711, 99990337, 99990389, 99990419, 99990461, 99990467, 99990487, 99990491, 99990493, 99990511, 99990533, 99990547, 99990551, 99990571};
ll qpow(ll a, ll b, ll mod) {
	ll ret = 1;
	while(b) {
		if(b) {
			if(b&1) ret = (ret*a) % mod;
			a = (a*a) % mod; b >>= 1;
		}
	}
	return ret;
}
bool check(string n, ll mod) {
	ll nn = 0;
	int len = n.size();
	for(int i = 0; i < len; ++i) {
		nn = (nn * 10 + n[i] - '0') % mod;
	}
	if(qpow(nn, (mod-1LL)/2LL, mod) == 1LL) return true;
	return false;
}
bool judge(string s) {
	int flag = 0;
	for(int i = 0; i < N; ++i) {
		if(!check(s, P[i])) flag = 1;
	}
	if(flag) return false;
	else return true;
}
bool check2(string n, ll mod) {
	ll nn = 0;
	int len = n.size();
	for(int i = 0; i < len; ++i) {
		nn = (nn * 10 + n[i] - '0') % mod;
	}
	ll tot = 0;
	tot = (nn*nn%mod - nn + mod) % mod;
	tot = tot * qpow(2, mod-2, mod) % mod;
	if(qpow(tot, (mod-1LL)/2LL, mod) == 1LL) return true;
	return false;
}
bool judge2(string s) {
	if(s == "1") return true;
	int flag = 0;
	for(int i = 0; i < N; ++i) {
		if(!check2(s, P[i])) flag = 1;
	}
	if(flag) return false;
	else return true;
}
int t;
string n;
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		//cout << judge(n) << " " << judge2(n) << endl;
		if(judge(n) && judge2(n)) {
			cout << "Arena of Valor" << endl;
		}else if(judge(n) && !judge2(n)) {
			cout << "Hearth Stone" << endl;
		}else if(!judge(n) && judge2(n)) {
			cout << "Clash Royale" << endl;
		}else {
			cout << "League of Legends" << endl;
		}
	}
	return 0;
}