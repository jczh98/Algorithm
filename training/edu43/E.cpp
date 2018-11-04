#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node {
	int hp, d;
}c[200005];
bool cmp(const node & a, const node & b) {
	return a.hp - a.d > b.hp - b.d;
}
int n, a, b;
LL sum = 0;
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &c[i].hp, &c[i].d);
	}
	sort(c + 1, c + 1 + n, cmp);
	for(int i = 1; i <= min(b, n); ++i) {
		sum += max(c[i].hp, c[i].d);
	}
	for(int i = min(b, n) + 1; i <= n; ++i) {
		sum += c[i].d;
	}
	LL ans = sum, db = 1LL << a;
	for(int i = 1; i <= n; ++i) {
		if(i <= min(b, n)) {
			LL tmp = sum;
			tmp -= max(c[i].hp, c[i].d);
			tmp += c[i].hp * db;
			ans = max(ans, tmp);
		}else {
			LL tmp = sum;
			tmp -= max(c[b].hp, c[b].d);
			tmp -= c[i].d;
			tmp += c[i].hp * db + c[b].d;
			ans = max(ans, tmp);
		}
	}
	if(b) cout << ans << endl; else cout << sum << endl;
	return 0;
}