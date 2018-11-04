#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int TTT=0,SSS;
ll gcd(ll x,ll y){return (y==0)?x:gcd(y,x%y);}
ll f[100];int f_n=0;
const int S=10;
const ull m_p[20]={2,5,7,61,97,37,101,13,11,997,2083,5807,7213,9907,10781,11897,14033,18013,43789,10009};
ll cheng(ll a,ll b,ll p){
	ll mmh;mmh=0;
	while (b){
		if (b&1) if (mmh=mmh+a,!(mmh<p)) mmh=mmh-p;
		b>>=1;a=a+a;if (!(a<p)) a=a-p;
	}
	return mmh;
}
ll mi(ll a,ll b,ll p){
	ll mmh;mmh=1;
	while (b){
		if (b&1ull) mmh=cheng(mmh,a,p);
		b>>=1;a=cheng(a,a,p);
	}
	return mmh;
}
bool prime_judge(ll n){
    if(n==2) return 1;
    if(!(n&1)) return 0;
    for (register int i=0;i<S;i++)
    if (m_p[i]==n) return 1;else if (mi(m_p[i]%n,n-1,n)!=1) return 0;
    return 1;
}
inline ll pollard_rho(ll n,int c){
	int i=1,k=2;ll x=(rand()*rand()+rand()*rand())%(n-1)+1,y=x;c%=n;
	for(;;){
		i++;
		x=cheng(x,x,n)+c;if (!(x<n)) x=x-n;
		ll d=gcd((y<x?y-x+n:y-x),n);
		if (d>1&&d<n) return d;
		if (y==x) return n;
		if (i==k) y=x,k<<=1;
	}
}
void find(ll n,int c){
	if (n==1) return;
	if (prime_judge(n)){
		f[f_n++]=n;
		return;
	}
	ll p=n;int k=c;
	while (!(p<n)) p=pollard_rho(p,c--);
	find(p,k);
	find(n/p,k);
}
int num[100];
inline void Solve(ll n) {
    f_n = 0;
    find(n, 3000);
    sort(f, f + f_n);
    num[0] = 1;
    int k = 1;
    for(int i = 1; i < f_n; ++i) {
        if(f[i] == f[i - 1]) ++num[k - 1];
        else num[k] = 1, f[k++] = f[i];
    }
    f_n = k;
}
int t, nn, ans;
int main() {
    freopen("out2.txt", "w", stdout);
    //scanf("%d", &t);
    for(int nn = 1; nn <= 100000; ++nn) {
    //while(t--) {
        //scanf("%d", &nn);
        if(nn == 1) {
            printf("0\n"); continue;
        }
        Solve(nn); ans = 0;
        for(int i = 0; i < f_n; ++i) {
            ans += num[i] * (f[i] - 1);
        }
        printf("%d\n", ans);
    }
}