#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,flag;

int main()
{
    ios::sync_with_stdio(false);
    int cnt=0;
    while(cin>>n)
    {
        if(n==0)return 0;
        if(cnt++)printf("\n");
        flag=0;
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                for(int x=0;x<=9;x++)
                    for(int y=0;y<=9;y++)
                        for(int z=1;z<=9;z++)
                            {
                                if(i==j||j==x||x==y||y==z||z==i||i==y||i==x||j==y||j==z||x==z)continue;
                                if(i==0&&j!=0)
                                    if(x==0||y==0)continue;
                                if(i==0&&j==0&&x!=0)
                                    if(y==0)continue;
                                int d=i*10000+j*1000+x*100+y*10+z;
                                int ans=d*n,flag2=0,cnt[100];
                                memset(cnt,0,sizeof(cnt));
                                while(ans)
                                {
                                    if(ans%10==i||ans%10==j||ans%10==x||ans%10==y||ans%10==z)flag2=1;
                                    if(cnt[ans%10])flag2=1;
                                    cnt[ans%10]=1;
                                    ans/=10;
                                }
                                if(flag2)continue;
                                if(d*n<=98765&&d*n>=10000)
                                {
                                    printf("%d / %d%d%d%d%d = %d\n",d*n,i,j,x,y,z,n);
                                    flag=1;
                                }
                            }

        if(!flag)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
