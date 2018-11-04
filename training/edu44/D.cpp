#include <bits/stdc++.h>
#include <sstream>  //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144

using namespace std;
struct Int_128{  
    unsigned long long a,b;  
    Int_128(long long x){a=0,b=x;}  
    friend bool operator < (Int_128 x,Int_128 y)  
    {  
        return x.a<y.a||(x.a==y.a&&x.b<y.b);  
    }  

    friend Int_128 operator + (Int_128 x,Int_128 y)  
    {  
        Int_128 re(0);  
        re.a=x.a+y.a+(x.b+y.b<x.b);  
        re.b=x.b+y.b;  
        return re;  
    }  
    friend Int_128 operator + (Int_128 x,long long  yy)  
    {  
        Int_128 y(yy);
        Int_128 re(0);  
        re.a=x.a+y.a+(x.b+y.b<x.b);  
        re.b=x.b+y.b;  
        return re;  
    } 
    friend Int_128 operator - (Int_128 x,Int_128 y)  
    {  
        y.a=~y.a;y.b=~y.b;  
        return x+y+1;  
    }  
    void Div2()  
    {  
        b>>=1;b|=(a&1ll)<<63;a>>=1;  
    }  
    friend Int_128 operator * (Int_128 x,Int_128 y)  
    {  
        Int_128 re=0;  
        while(y.a||y.b)  
        {  
            if(y.b&1)re=re+x;  
            x=x+x;y.Div2();  
        }  
        return re;  
    }  
    friend Int_128 operator % (Int_128 x,Int_128 y)  
    {  
        Int_128 temp=y;  
        int cnt=0;  
        while(temp<x)temp=temp+temp,++cnt;  
        for(;cnt>=0;cnt--)  
        {  
            if(temp<x)x=x-temp;  
            temp.Div2();  
        }  
        return x;  
    }  
};  
#define ll Int_128
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
ll cal(ll x) {
    if (x % 2LL == 0) {
        ll tt = x / 2LL;
        tt *= (x + 1LL);
        return tt;
    } else {
        ll tt = (x + 1LL) / 2LL;
        tt *= x;
        return tt;
    }
}
int main() {
    ll i, j, n, m, t, H;
    cin >> n >> H;
    ll l = 1LL, r = 2e9, mid;
    //	cout << "r:" << cal(1) << endl;
    if (H <= 2e9) {
        if (cal(H) < n) {
            ll ans = H;
            ll rest = n - cal(H);
            if (rest % H == 0) {
                ans += rest / H;
            } else {
                ans += rest / H + 1LL;
            }
            cout << ans << endl;
            return 0;
        }
    }

    while (r - l > 1) {
        mid = (l + r) / 2;
        ll temp = cal(mid);
        //		cout << temp << endl;
        if (temp == n) {
            l = mid;
            r = mid;
            break;
        }
        if (temp > n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (cal(l) == n) {
        cout << l << endl;
        return 0;
    }
    if (cal(r) < n) {
        cout << r + 1 << endl;
        return 0;
    }
    if (cal(r) == n) {
        cout << r << endl;
        return 0;
    }
    if (cal(l) < n && cal(r) > n) {
        cout << l + 1 << endl;
        return 0;
    }
    return 0;
}