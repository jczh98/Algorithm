#include <bits/stdc++.h>
#define N 100100
#define inf 10000000000LL
using namespace std;
typedef long long LL;
LL n,s,v[N],ans[N],cnt=0,sum=0,l,r;
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(v+1,v+1+n);
    l=1,r=n;
    while(l<r)
    {
        if(v[l]+v[r]>s)
        {
            ans[cnt++]=v[l++];
            ans[cnt++]=v[r--];
        }else
        {
            ans[cnt++]=v[l++];
            ans[cnt++]=v[l++];
        }
    }
    /*for(int i=0;i<cnt;i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;*/
    if(l==r)ans[cnt++]=v[l];
    ans[cnt]=inf;
    //cout<<cnt<<endl;
    int pos=0;
    while(pos<cnt)
    {
        if(ans[pos]+ans[pos+1]>s)
        {
            pos++;sum++;
        }else
        {
            pos+=2;sum++;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<cnt-1;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[cnt-1]<<endl;;
    return 0;
}
