#include<math.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
ll quick(ll a,ll b) {
    ll ans=1;
    while(b!=0) {
        if(b&1) ans=ans*a;
        b>>=1;
        a=a*a;
    }
    return ans;
}
ll Mod = 1e9+7;
ll a[70];
ll quickmod(ll a,ll b,ll mod) {
    ll ans=1;
    a=a%mod;
    while(b!=0) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main() {
    ll temp = 1;
    int count = 0;
    a[0] = 0;
    a[1] = 1;
    while (temp <= 1e18) {
        a[count++ + 2] = (ll)quickmod(2,count-1,Mod) * (quickmod(2,count,Mod) + 1) % Mod;
        temp *= 2;
    }
//	for(int i = 0;i<count;i++)	printf("%lld\n",a[i]);
    ll x;
    while (scanf("%lld",&x) != EOF) {
        ll ans = 0;
        x -= 1;
        bool first = true;
        while (x > 0) {
            ll te = 1;
            int cc = 1;
            for (int i = 1; i <= 68; i++) {
                if (te > x) {
                    break;
                } else {
                    te *= 2;
                    cc++;
                }
            }
            te /= 2;
            if (first) {
                ans += a[cc-1];
                ans %= Mod;
                first = false;
//				printf("fuck:%lld\n",ans);
                x -= te;
            } else {
                int i;
                for (i = 1; i <= 66; i++) {
                    if (quick(2,i) - quick(2,i-1) == te) {
                        break;
                    }
                }
                ans += a[i+1] - a[i];
                ans %= Mod;
//				printf("fuck:%lld\n",ans);
                x-=te;
            }
        }
        printf("%lld\n",ans);
    }
}