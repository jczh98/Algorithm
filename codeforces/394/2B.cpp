#include <cstdio>
#include <cstring>
int n,l,a1[10000],a2[10000],b[10000];
int main()
{
    memset(b,0,sizeof(b));
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
        b[a1[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a2[i]);
    }
    int flag=0;
    for(int i=0;i<l;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(i+a2[j]<l)
            {
                if(b[i+a2[j]]==1)
                {
                    cnt++;
                }
            }else
            {
                if(b[i+a2[j]-l]==1)
                {
                    cnt++;
                }
            }
        }
        if(cnt==n)
        {
            flag=1;break;
        }
    }
    if(flag==0)printf("NO\n");
    else printf("YES\n");
    return 0;
}
