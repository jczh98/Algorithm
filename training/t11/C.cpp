#include <bits/stdc++.h>
#define N 1001000
#define inf 0x7f7f7f7f
using namespace std;
int t,n,a[N],hill,dale,b[N],f1[N],f2[N],f3[N],f4[N],Stack[N];
int main()
{
    freopen("dales.in","r",stdin);
    freopen("dales.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[n-i+1]=a[i];
        hill=dale=0;
        int top=0;
        Stack[top]=-inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>Stack[top])
            {
                Stack[++top]=a[i];
                f1[i]=top;
            }
            else
            {
                top=1;
                Stack[top]=a[i];
                f1[i]=top;
            }
        }
        top=0;
        Stack[top]=inf;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<Stack[top])
            {
                Stack[++top]=a[i];
                f2[i]=top;
            }
            else
            {
                top=1;
                Stack[top]=a[i];
                f2[i]=top;
            }
        }
        top=0;
        Stack[top]=-inf;
        for(int i=1;i<=n;i++)
        {
            if(b[i]>Stack[top])
            {
                Stack[++top]=b[i];
                f3[i]=top;
            }
            else
            {
                top=1;
                Stack[top]=b[i];
                f3[i]=top;
            }
        }
        top=0;
        Stack[top]=inf;
        for(int i=1;i<=n;i++)
        {
            if(b[i]<Stack[top])
            {
                Stack[++top]=b[i];
                f4[i]=top;
            }
            else
            {
                top=1;
                Stack[top]=b[i];
                f4[i]=top;
            }
        }
        for(int i=1;i<=n;i++)
        {
            hill=max(hill,min(f1[i]-1,f3[n+1-i]-1));
            dale=max(dale,min(f2[i]-1,f4[n+1-i]-1));
        }
        printf("%d %d\n",hill,dale);
    }
    return 0;
}
