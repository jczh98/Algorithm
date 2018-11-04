#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, k;
int main() {
	cin >> n >> m >> k;
	if(k <= n-1) {
		cout << k + 1 << " " << 1 << endl;
		return 0;
	}
	k++;
	LL temp =  (k - n - 1) / (m-1);
	if(temp % 2 == 1) {
		cout << n - temp << " " << m-((k - n - 1) % (m-1));
	} else {
		cout << n - temp << " " << ((k - n - 1) % (m-1)) + 2;
	}
	return 0;
}
