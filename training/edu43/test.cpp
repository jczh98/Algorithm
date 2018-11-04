#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
struct node {
	ll hp,d;
};
node nd[200005];
bool cmp(node p1, node p2) {
	return p1.hp - p1.d > p2.hp - p2.d;
}
int cnt = 0;
int main() {
	ll i,j,n,m,a,b;
	cin >> n >> a >> b;
	for(i=0; i<n; i++) {
		cin >> nd[i].hp >> nd[i].d;
        if(nd[i].hp > nd[i].d) cnt++;
	}
    if(b > cnt) {
        for(int i = 0; i < n; ++i) {
            if(nd[i].hp > nd[i].d) nd[i].d = nd[i].hp;
        }
    }
	ll mc = inf;
	ll turn = 0;
	for(i=0; i<n; i++) {
		if(nd[i].hp * (ll)pow((ll)2,a) - nd[i].d > mc) {
			turn = i;
			mc = nd[i].hp * (ll)pow((ll)2,a) - nd[i].d;
		}
	}
	nd[turn].hp *= (ll)pow((ll)2,a);

	sort(nd,nd+n,cmp);
	int coun = 0;
	while(b--) {
		if(nd[coun].d < nd[coun].hp)
			nd[coun].d = nd[coun].hp;
		coun++;
		if(coun == n)	break;
	}
	ll ans = 0;
	for(i=0; i<n; i++)	ans += nd[i].d;
	cout << ans << endl;
	return 0;
}
