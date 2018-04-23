#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL co[1000005], pl[1000005];
inline LL read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n; 
LL m;
int main() {
	cin >> n >> m;
	for(register int i = 0; i < n; ++i) {
		co[i] = read();
	}
	for(register int i = 0; i < n; ++i) {
		pl[i] = read();
	}
    sort(co, co + n);
    sort(pl, pl + n);
    LL sco = 0, spl = 0, ans = 0, cnt = 0;
    for(register int i = 0; i < n; ++i) {
        sco += co[i];
        spl += pl[n - 1 - i];
        cnt++;
        ans = max(ans, spl - sco + 1LL * (cnt / 3) * m);
    }
    cout << ans << endl;
    return 0;
}
