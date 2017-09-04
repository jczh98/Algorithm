#include <bits/stdc++.h>
using namespace std;
char good[500],pat[100100],query[100100];
int n,vis_good[1000]={0},is_star=0,star_pos;
int main()
{
    scanf("%s%s",good,pat);
    for(int i=0;i<strlen(good);i++)vis_good[good[i]]=1;
    for(int i=0;i<strlen(pat);i++)if(pat[i]=='*'){is_star=1;star_pos=i;}
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",query);
        if(is_star)
        {
            int flag=0,i,j,st,ed;
            if(strlen(pat)-1>strlen(query))
            {
                printf("NO\n");
                continue;
            }
            for(i=0;i<star_pos;i++)
            {
                if(pat[i]=='?')
                {
                    if(!vis_good[query[i]])
                    {
                        flag=1;break;
                    }
                }else
                {
                    if(pat[i]!=query[i])
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag)
            {
                printf("NO\n");continue;
            }
            //cout<<star_pos<<endl;
            for(i=strlen(pat)-1,j=strlen(query)-1;i>star_pos;i--,j--)
            {
                if(pat[i]=='?')
                {
                    if(!vis_good[query[j]])
                    {
                        flag=1;break;
                    }
                }else
                {
                    if(pat[i]!=query[j])
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag)
            {
                printf("NO\n");continue;
            }
            st=star_pos,ed=j;
            //if(st>ed)
            //cout<<st<<" "<<ed<<endl;
            for(i=st;i<=ed;i++)
            {
                if(vis_good[query[i]])
                {
                    flag=1;break;
                }
            }
            if(flag)
            {
                printf("NO\n");continue;
            }
        }else
        {
            if(strlen(pat)!=strlen(query)){printf("NO\n");continue;}
            int flag=0;
            for(int i=0;i<strlen(pat);i++)
            {
                if(pat[i]=='?')
                {
                    if(!vis_good[query[i]])
                    {
                        flag=1;break;
                    }
                }else
                {
                    if(pat[i]!=query[i])
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag)
            {
                printf("NO\n");continue;
            }
        }
        printf("YES\n");
    }
    return 0;
}
