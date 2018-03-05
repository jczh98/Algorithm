#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
int T;
char s[maxn],c[maxn];
int deal(int l,int r)
{
    int sign=1;
    if(c[l]=='-')
    {
        if(c[l+1]=='0')return INF;
        sign=-1,l++;
    } 
    if(c[l]=='0'&&l<r)return INF;
    int ans=0; 
    for(int i=l;i<=r;i++)ans=10*ans+c[i]-'0';
    return sign*ans;
}
int flag[11];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(flag,0,sizeof(flag));
        scanf("%s",s);
        int len=strlen(s),gg=-1;
        for(int i=0;i<len;i++)
            if(s[i]>='0'&&s[i]<='9')flag[s[i]-'0']=1;
        for(int k=0;k<10;k++)
        {
            if(gg!=-1)break;
            if(flag[k])continue;
            for(int i=0;i<len;i++)
            {
                c[i]=s[i];
                if(c[i]=='?')c[i]=k+'0';
            }
            int pos1,pos2,type=-1;
            for(int i=1;i<len;i++)
            {
                if(type==-1)
                {
                    if(c[i]=='+')type=1,pos1=i;
                    if(c[i]=='-')type=2,pos1=i;
                    if(c[i]=='*')type=3,pos1=i;
                }
                if(c[i]=='=')pos2=i;
            }
            int x=deal(0,pos1-1),y=deal(pos1+1,pos2-1),z=deal(pos2+1,len-1);
            if(x==INF||y==INF||z==INF)continue;
            if(type==1&&x+y==z)gg=k;
            else if(type==2&&x-y==z)gg=k;
            else if(type==3&&1ll*x*y==1ll*z)gg=k;
        }
        printf("%d\n",gg);
    }
    return 0;
}