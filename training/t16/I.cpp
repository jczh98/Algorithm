#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
int t,n,kase=1;
char str[1000];
ULL f[1000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        scanf("%s",str+1);
        f[0]=f[1]=1;n=strlen(str+1);
        for(int i=2;i<=n;i++)
        {
            if(str[i]!='0')f[i]+=f[i-1];
            int t=(str[i-1]-'0')*10+str[i]-'0';
            if(t>=10&&t<=26&&str[i-1]!='0')f[i]+=f[i-2];
        }
        cout<<fixed;
        if(str[1]=='0') cout<<"Case #"<<kase++<<": "<<0<<endl;
        else cout<<"Case #"<<kase++<<": "<<f[n]<<endl;
    }
    return 0;
}
