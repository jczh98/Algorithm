#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,len,cnt,rk[200][1000],maxcnt;
char name[100],cls[1000],str[100];
struct Node
{
    char name[100];
    LL rk;
}pep[200];
int cmp(Node x,Node y)
{
    if(x.rk!=y.rk)
    {
        return x.rk>y.rk;
    }else
    {
        return strcmp(x.name,y.name)<0;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);maxcnt=0;
        memset(rk,0,sizeof(rk));
        memset(pep,0,sizeof(pep));
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s%s",name,cls,str);
            memcpy(pep[i].name,name,strlen(name)-1);
            len=strlen(cls);cnt=0;
            for(int j=len-2;j>=0;j--)
            {
                if(cls[j]=='u'&&cls[j+1]=='p')
                {
                    rk[i][cnt++]=3;
                }else if(cls[j]=='m'&&cls[j+1]=='i')
                {
                    rk[i][cnt++]=2;
                }else if(cls[j]=='l'&&cls[j+1]=='o')
                {
                    rk[i][cnt++]=1;
                }
            }
            maxcnt=max(maxcnt,cnt);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<maxcnt;j++)
            {
                if(rk[i][j]==0)rk[i][j]=2;
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<maxcnt;j++)
            {
                printf("%d",rk[i][j]);
            }
            printf("\n");
        }*/
        for(int i=1;i<=n;i++)
        {
            LL t=1,sum=0;
            for(int j=maxcnt-1;j>=0;j--)
            {
                sum+=t*(LL)rk[i][j];t*=10;
            }
            pep[i].rk=sum;
        }
        sort(pep+1,pep+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            printf("%s\n",pep[i].name);
        }
        printf("==============================\n");
    }
    return 0;
}
