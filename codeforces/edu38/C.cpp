#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t, x;
int main() {
    cin >> t;
    while(t--) {
        cin >> x;
        if(x == 0) {
            cout << "1 1" << endl;
            continue;
        }
        int sqr = sqrt(x) + 1, flag = 0;
		for(int a = 1; a <= sqr; ++a) {
			if(x % a == 0) {
				LL b = x / a;
				if(b > a) {
					if((a+b) % 2 == 0) {
						LL n = (a + b) / 2, m = -1;
						LL m1 = n / (((b-a))/2)-1, m2 = n / (((b-a))/2), m3 = n / (((b-a))/2)+1;
						if(m1 && 2 * (LL) (n / m1) == (b-a)) m = m1; 
						if(m2 && 2 * (LL) (n / m2) == (b-a)) m = m2; 
						if(m3 && 2 * (LL) (n / m3) == (b-a)) m = m3; 
						if(~m) {
                            cout << n << " " << m << endl; flag = 1;
							break;
						}
					}
				}
			}
		}
        if(!flag) cout << -1 << endl;
    }
    return 0;
}