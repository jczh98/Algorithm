#include <bits/stdc++.h>
using namespace std;
int t,n,number,ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&number,&n);ans=0;
        if(n==1)
        {
            cout<<number<<" "<<1<<endl;
            continue;
        }
        while(n!=1)
        {
            ans=max(ans,n);
            if(n&1)n=n*3+1;else n/=2;
        }
        printf("%d %d\n",number,ans);
    }
    return 0;
}
