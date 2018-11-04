#include <bits/stdc++.h>
using namespace std;
namespace linear_seq {
    #define rep(i,a,n) for (int i=a;i<n;i++)
    #define per(i,a,n) for (int i=n-1;i>=a;i--)
    #define pb push_back
    #define mp make_pair
    #define all(x) (x).begin(),(x).end()
    #define fi first
    #define se second
    #define SZ(x) ((int)(x).size())
    typedef vector<int> VI;
    typedef long long ll;
    typedef pair<int,int> PII;
    const ll mod=998244353;
    ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    // head
    const int N=10010;
    ll res[N],base[N],_c[N],_md[N];
 
    vector<int> Md;
    void mul(ll *a,ll *b,int k) {
        rep(i,0,k+k) _c[i]=0;
        rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
        for (int i=k+k-1;i>=k;i--) if (_c[i])
            rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
        rep(i,0,k) a[i]=_c[i];
    }
    int solve(ll n,VI a,VI b) { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
//        printf("SIZE %d\n",SZ(b));
        ll ans=0,pnt=0;
        int k=SZ(a);
        assert(SZ(a)==SZ(b));
        rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
        Md.clear();
        rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
        rep(i,0,k) res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<pnt)<=n) pnt++;
        for (int p=pnt;p>=0;p--) {
            mul(res,res,k);
            if ((n>>p)&1) {
                for (int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
                rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
            }
        }
        rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
        if (ans<0) ans+=mod;
        return ans;
    }
    VI BM(VI s) {
        VI C(1,1),B(1,1);
        int L=0,m=1,b=1;
        rep(n,0,SZ(s)) {
            ll d=0;
            rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
            if (d==0) ++m;
            else if (2*L<=n) {
                VI T=C;
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                L=n+1-L; B=T; b=d; m=1;
            } else {
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    int gao(VI a,ll n) {
        VI c=BM(a);
        c.erase(c.begin());
        rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
        return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
    }
};
// using namespace linear_seq;
// int n;
// int main() {
//     VI a;
//     a.push_back(0);
//     a.push_back(2);
//     a.push_back(10);
//     a.push_back(16);
//     a.push_back(41);
//     a.push_back(66);
//     a.push_back(123);
//     a.push_back(152);
//     a.push_back(178);
//     a.push_back(243);
//     a.push_back(384);
//     a.push_back(448);
//     a.push_back(649);
//     a.push_back(794);
//     a.push_back(935);
//     a.push_back(1013);
//     a.push_back(1360);
//     scanf("%d", &n);
//     printf("%d\n", gao(a, n-1));
// }
#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string);	stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
//pos = lower_bound(a, a+n, key) - a	//查找>=key的位置
//pos = upper_bound(a, a+n, key) - a	//查找>key的位置
ll edge[1005][1005], path[1005][1005], A[1005][1005];

bool issqrt(ll a) {
	ll b = (ll)(sqrt((double)a + 0.1) + 0.1);
	if(b * b == a)	return true;
	else	return false;
}
int main() {
	int i, j, k, n, m, t;
	int N = 100;
	for(ll i=1; i<=N; i++) {
		for(ll j=1; j<=N; j++) {
			for(ll k=1; k<=i * j; k++) {
				if(issqrt(i*j*k)) {
					edge[i][j] = k;
					break;
				}
			}
		}
	}

	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++) {
			A[i][j]=edge[i][j];
			path[i][j]=-1;
		}
	}

	for(k=1; k<=N; k++) {
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				if(A[i][j]>(A[i][k]+A[k][j])) {
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
    using namespace linear_seq;
    VI a;
	for(k = 1; k <= N; k++) {
		ll ans = 0;
		for(i=1; i<k; i++) {
			for(j=i+1; j<=k; j++) {
				ans += A[i][j];
			}
		}
		//cout <<k <<  " " << ans<< endl;
//		cout << " " << ans;
        a.push_back(ans);
	}
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", gao(a, n-1));
    }
	return 0;
}
