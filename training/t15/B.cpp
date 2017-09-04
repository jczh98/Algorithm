#include <bits/stdc++.h>
using namespace std;
int t,number,n,ans,x1,x2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&number,&n);
        ans=0;
        for(int i=1;i<=n/3;i++)
        {
            x1=max(n/2-i+1,i);x2=(n-i)/2;
            if(i==x1)ans--;
            if(i!=x2&&x2==n-i-x2)ans--;
            ans+=(x2-x1+1)*2;
        }
        cout<<number<<" "<<ans<<endl;
    }
}
