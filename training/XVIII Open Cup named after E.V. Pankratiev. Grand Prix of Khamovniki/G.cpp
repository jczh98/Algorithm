#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
//pos = lower_bound(a,a+n,key) - a	//查找>=key的位置
//pos = upper_bound(a,a+n,key) - a	//查找>key的位置
__float128 ffabs(__float128 x)
{
    return x >= 0 ? x : -x;
}
const int N = 100005;
double x[N], y[N];
__float128 tmpk[N], k[N];
const __float128 EPS = 1e-9;
int main() {
	int i,j,m,n;
	cin >> n;
	for(i = 0; i < n + 1; i++) {
		cin >> x[i] >> y[i];
	}
	__float128 sum = 0;
	__float128 totaly = 0;
	for(i = 0; i < n; i++) {
		k[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
		if(i > 0) {
			tmpk[i] = (k[i] - k[i - 1]) / 2;
			totaly += tmpk[i] * ffabs(x[0] - x[i]);
			sum += tmpk[i];
		}
	}
	if(ffabs(sum - k[n-1]) <= EPS && ffabs(sum + k[0]) <= EPS && ffabs(totaly - y[0]) <= EPS) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
