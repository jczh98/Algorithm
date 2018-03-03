#include <bits/stdc++.h>
using namespace std;
int a[1000005], n, ans, x;
int main() {
	scanf("%d",&n);
	while(n--) {
        cin >> x;
        a[x] = 1;
	}
	for(int i = 2;i <= 500000;i++) {
		if(a[i] == 1) {
			ans = max(ans,i - 1);
		}
	}
	for(int i = 999999;i >= 500001;i--) {
		if(a[i] == 1) {
			ans = max(ans,1000000 - i);
		}
	}
	cout << ans << endl;
	return 0;
}
