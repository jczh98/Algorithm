#include <bits/stdc++.h>
using namespace std;
int t,a[100],par[100],cnt[100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(par,0,sizeof(par));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=14;i++)
        {
            scanf("%d",&a[i]);par[a[i]]++;
        }
        //sort(a+1,a+1+14);
        int check=0,flag=0;
        for(int i=1;i<=9;i++)
        {
            if(par[i]>=2)
            {
                check=1;
                par[i]-=2;
                for(int j=1;j<=11;j++) cnt[j]=par[j];
                for(int j=1;j<=11;j++)
                {
                    if(cnt[j]<0)
                    {
                        check=0;break;
                    }
                    cnt[j]%=3;cnt[j+1]-=cnt[j];cnt[j+2]-=cnt[j];
                }
                par[i]+=2;
                if(check)
                {
                    //cout<<i<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(flag)printf("Vulnerable\n");
        else printf("Immune\n");
    }
    return 0;
}
