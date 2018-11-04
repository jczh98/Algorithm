#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string);	stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
const double pi=acos(-1.0);
//pos = lower_bound(a, a+n, key) - a	//查找>=key的位置
//pos = upper_bound(a, a+n, key) - a	//查找>key的位置
char s[1005][1005];
int maxheng[1005][1005];
int maxshu[1005][1005];
int tmpma[55];
int mp[55];
inline int convert(char a) {
	if(a <= 'z' && a >= 'a')	return a - 'a';
	else	return a - 'A' + 26;
}
int main() {
	register int i, j, n, m, t, k;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++) {
		scanf("%s",s[i]);
	}
	for(i=0; i < n; i++) {
		for(j=0; j < m; j++) {
			memset(mp,0,sizeof(mp));
			for(k=0; k < 52 && j + k < m; k++) {
				if(!mp[convert(s[i][j + k])]) {
					mp[convert(s[i][j + k])] = 1;
					maxheng[i][j] = k + 1;
				} else {
					break;
				}
			}
		}
	}
	for(i=0; i < n; i++) {
		for(j=0; j < m; j++) {
			memset(mp,0,sizeof(mp));
			for(k=0; k < 52 && i + k < n; k++) {
				if(!mp[convert(s[i + k][j])]) {
					mp[convert(s[i + k][j])] = 1;
					maxshu[i][j] = k + 1;
				} else {
					break;
				}
			}
		}
	}
	ll ans = 0, tmpans;
    int shutmp, pos, tmp;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			for(k=0; k<=52; k++)	tmpma[k] = INF;
			tmp = INF;
			for(k=0; k<52 && i + k < n; k++) {
				tmp = min(tmp,maxheng[i+k][j]);
				tmpma[k] = tmp;
			}
			shutmp = INF;
			pos = 51;
			for(k=0; k<52 && j + k < m; k++) {
				shutmp = min(shutmp, maxshu[i][j+k]);
				tmpans = 0;
				if(pos + 1 > shutmp)	pos = shutmp - 1;
				while(true) {
					if(tmpma[pos] >= k+1)	break;
					pos--;
					if(pos < 0)	break;
				}
				if(pos < 0)	break;
				ans += (ll)(pos + 1);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
