#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l,r;
LL t,lnum[100],rnum[100],ans[100];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(lnum,0,sizeof(lnum));
        memset(rnum,0,sizeof(rnum));
        memset(ans,0,sizeof(ans));
        cin>>l>>r;
        int cnt1=1,cnt2=1;
        while(l)
        {
            lnum[cnt1++]=l%2;
            l/=2;
        }
        while(r)
        {
            rnum[cnt2++]=r%2;
            r/=2;
        }
        for(int i=1;i<cnt2;i++)ans[i]=rnum[i];
        int pos;
        for(pos=cnt2-1;pos>=1;pos--)
        {
            if(lnum[pos]!=rnum[pos])break;
        }
        for(int i=pos;i>=1;i--)
        {
            ans[i]=1;
        }
        LL sum=0,pow=1;
        for(int i=1;i<cnt2;i++)
        {
            sum+=ans[i]*pow;
            pow*=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
