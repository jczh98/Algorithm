#include <bits/stdc++.h>
using namespace std;
int n, k, p[1005];
struct node {
	double e, pk;
}E[1005];
bool cmp(node e1, node e2) {
	return e1.e + e1.pk * e2.e < e2.e + e2.pk * e1.e;
}
double ans;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for(int j = 1; j <= k; ++j) {
			scanf("%d", &p[j]);
		}
		sort(p + 1, p + 1 + k);
		double pnow = 1.0; E[i].pk = 1.0;
		for(int j = 1; j <= k; ++j) {
			E[i].e += pnow;
			pnow *= p[j] * 1.0 / 1000.0;
			E[i].pk *= p[j] * 1.0 / 1000.0;
		}
		E[i].pk = 1.0 - E[i].pk;
	}
	// for(int i = 1; i <= n; ++i) {
	// 	cout << E[i].e << " " << E[i].pk << endl;;
	// }
	sort(E + 1, E + 1 + n, cmp);
	double tmp = 1.0;
	for(int i = 1; i <= n; ++i) {
		ans += tmp * E[i].e;
		tmp *= E[i].pk;
	}
	printf("%.10f\n", ans);
	return 0;
}