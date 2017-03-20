#include <cstdio>
#include <cstring>
char s[10000][10];
int n,k,color[10000],tcnt[10000];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)color[i]=i;
    for(int i=1;i<=n-k+1;i++)scanf("%s",s[i]);
    for(int i=1;i<=n-k+1;i++)
    {
        if(s[i][0]=='N')
        {
            memset(tcnt,0,sizeof(tcnt));
            for(int j=i;j<=i+k-1;j++)
            {
                tcnt[color[j]]=tcnt[color[j]]+1;
            }
            int t2=0;
            for(int j=1;j<=n;j++)
            {
                if(tcnt[j]>=2)t2++;
            }
            /*if(i==n-k+1)
            {
                for(int i=1;i<=n;i++)printf("%d ",tcnt[i]);
                printf("#%d\n",t2);
            }*/
            if(t2==0)
            {
                color[i+k-1]=color[i];
            }
        }else if(s[i][0]=='Y')
        {
            /*memset(tcnt,0,sizeof(tcnt));
            for(int j=i;j<=i+k-1;j++)
            {
                tcnt[color[j]]=tcnt[color[j]]+1;
            }
            int t2=0;
            for(int j=1;j<=n;j++)
            {
                if(tcnt[j]>=2)t2++;
            }
            if(t2==0)continue;
            for(int j=i+1;j<=i+k-1;j++)
            {
                color[j]=color[j-1]+1;
            }*/
        }
    }
    for(int i=1;i<n;i++)
    {
        if(color[i]<=26)printf("%c",'A'+color[i]-1);
        if(color[i]>26)printf("%c%c",'A'+color[i]-1-26,'a'+color[i]-1-26);
        //printf("%d ",color[i]);
        printf(" ");
    }
    if(color[n]<=26)printf("%c",'A'+color[n]-1);
    if(color[n]>26)printf("%c%c",'A'+color[n]-1-26,'a'+color[n]-1-26);
    printf("\n");
    return 0;
}
