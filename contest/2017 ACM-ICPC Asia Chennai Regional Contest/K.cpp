#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
//set<int>::iterator set_stater
//typedef pair<int,int> pii;
using namespace std;
int t,n,dp[100010][2];
char s[10];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag1=0,flag2=0,cnta=0,cntb=0;
        ff(i,1,n)
        {
            scanf("%s",s+1);
            int len=strlen(s+1);
            if(len==1)
            {
                if(s[1]=='a')
                    cnta++;
                else
                    cntb++;
            }
            else
            {
                if(s[1]==s[2])
                {
                    if(s[1]=='a')
                        cnta++;
                    else
                        cntb++;
                }
                else if(s[1]=='a')
                    flag1++;
                else
                    flag2++;
            }
        }
            if(!flag1&&!flag2)
            {
                if(cnta==0||cntb==0)
                    printf("1\n");
                else
                    printf("2\n");
            }
            else if(!flag1)
                printf("%d\n",2*flag2);
            else if(!flag2)
                printf("%d\n",2*flag1);
            else
            {
                if(flag1==flag2)
                    printf("%d\n",2*max(flag1,flag2)+1);
                else
                    printf("%d\n",2*max(flag1,flag2));
            }
    }
    return 0;
}