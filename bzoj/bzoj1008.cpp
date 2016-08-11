#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const ll MOD=100003;
ll m,n;

ll Ksm(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1) r=(a*r)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}
int main() {
	scanf("%lld%lld",&m,&n);
	ll sum=Ksm(m,n),t=Ksm(m-1,n-1);
	t=(t*m)%MOD;
	printf("%lld\n",(sum-t+MOD)%MOD);
	return 0;
} 
