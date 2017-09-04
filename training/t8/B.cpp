#include <bits/stdc++.h>
using namespace std;
int n,op_val[100],ans=0;
char op[100][10];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d",op[i],&op_val[i]);
    }
    for(int i=1;i<=100;i++)
    {
        int t=i;
        for(int j=1;j<=n;j++)
        {
            if(op[j][0]=='A') t+=op_val[j];
            if(op[j][0]=='S')
            {
                t-=op_val[j];
                if(t<0)
                {
                    ans++;
                    break;
                }
            }
            if(op[j][0]=='M') t*=op_val[j];
            if(op[j][0]=='D')
            {
                if(t%op_val[j]==0)
                {
                    t/=op_val[j];
                }else
                {
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
