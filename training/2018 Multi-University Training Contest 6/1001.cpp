#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string);	stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
const double pi=acos(-1.0);
//pos = lower_bound(a, a+n, key) - a	//查找>=key的位置
//pos = upper_bound(a, a+n, key) - a	//查找>key的位置
int main() {
	int i, j, n, m, t;
	cin >> t;
	long double a,b;
	while(t--) {
		cin >> a >> b;
		long double ans = b*b*(2.0+sqrt(a*a/b/b)*pi);
		printf("%.6Lf\n",ans);
	}
	return 0;
}
