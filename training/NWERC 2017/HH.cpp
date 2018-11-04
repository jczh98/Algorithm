#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
ll a[3];
int main() {
	int i,j,n,m,t;
	cin >> t;
	ll d;
	while(t--) {
		cin >> a[0] >> a[1] >> a[2] >> d;
		sort(a,a+3);
		if(d > 1) {
			a[2] += d;
			cout << a[2] * a[2] + a[1] * a[1] + a[0] * a[0] + 7 * a[0] << endl;
			continue;
		} else {
			ll ans1,ans2,ans3;
			a[0] += d;
			ans1 = a[2] * a[2] + a[1] * a[1] + a[0] * a[0] + 7 * min(min(a[0],a[1]),a[2]);
			a[0] -= d;
			a[1] += d;
			ans2 = a[2] * a[2] + a[1] * a[1] + a[0] * a[0] + 7 * min(min(a[0],a[1]),a[2]);
			a[1] -= d;
			a[2] += d;
			ans3 = a[2] * a[2] + a[1] * a[1] + a[0] * a[0] + 7 * min(min(a[0],a[1]),a[2]);
			a[2] -= d;
			cout << max(max(ans1,ans2),ans3) << endl;
		}

	}
	return 0;
}
