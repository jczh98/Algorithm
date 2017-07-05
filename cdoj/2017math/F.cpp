#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int m,n,a,b,tot;
set<pair<LL,LL>> st;
LL QuickPow(LL a,LL b,LL mod)
{
    LL res=1;
    while(b)
    {
        if(b&1)res*=a,res=res%mod;
        a*=a;a%=mod;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for(int i=a;i<a+n;i++)
        for(int j=b;j<b+m;j++)
            st.insert(make_pair(QuickPow(i,j,1e9+7LL),QuickPow(i,j,1e9+9LL)));
    printf("%d\n",st.size());
    return 0;
}
