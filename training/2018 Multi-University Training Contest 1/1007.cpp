#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
const ll mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
//pos = lower_bound(a,a+n,key) - a	//查找>=key的位置
//pos = upper_bound(a,a+n,key) - a	//查找>key的位置
ll Scan() {	//  输入外挂
	ll res = 0, flag = 0;
	char ch;
	if ((ch = getchar()) == '-') {
		flag = 1;
	} else if(ch >= '0' && ch <= '9') {
		res = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9') {
		res = res * 10LL + (ch - '0');
	}
	return flag ? -res : res;
}

void Out(ll a) {	//  输出外挂
	if (a < 0) {
		putchar('-');
		a = -a;
	}
	if (a >= 10) {
		Out(a / 10);
	}
	putchar(a % 10 + '0');
}
ll n,c[1005],ans;
int main() {
	int i,j,m,t;
	c[0]=1;
	c[1]=2;
	for(i=2; i<=63; i++)
		c[i] = (c[i-1] * 2 % mod + ( ((1LL << (i-2)) % mod) * ((1LL << (i-1))+1) % mod ) % mod - 1 + mod) % mod;

//	t = Scan();
	scanf("%d",&t);
	while(t--) {
//		n = Scan();
		scanf("%lld",&n);
		ans = 0;
		if(n == 1) {
//			Out(1);
//			printf("\n");
			printf("1\n");
			continue;
		}
		while(n > 1) {
			ll wei = (log(((double)n  + 0.2)* 1.0)) / log(2.0);
			ans = (ans + c[wei]) % mod;
			n -= (1LL << wei);
			if(n == 0)	break;
			ans = (ans + (n % mod * ((1LL << (wei-1)) % mod) % mod) % mod + mod) % mod;
			n = n + 1;
			ans = (ans - 1 + mod) % mod;
		}
		if(n == 1)	ans++;
//		Out((ans+mod) % mod);
//		printf("\n");
		printf("%lld\n",(ans+mod) % mod);
	}
	return 0;
}
