#include <bits/stdc++.h>
#define inf 1e6
using namespace std;
int n,m,ans=0,cnt_b=0,max_r=0,max_c=0,min_r=inf,min_c=inf;
char mp[110][110];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",mp[i]);
    /*if(n==1||m==1)
    {
        printf("-1\n");
        return 0;
    }*/
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='B')
            {
                cnt_b++;
                max_r=max(i,max_r);
                max_c=max(j,max_c);
                min_r=min(i,min_r);
                min_c=min(j,min_c);
            }
        }
    }
    if(cnt_b==0)
    {
        printf("1\n");
        return 0;
    }else if(cnt_b==1)
    {
        printf("0\n");
        return 0;
    }
    int height=abs(max_r-min_r)+1;
    int width=abs(max_c-min_c)+1;
    //cout<<height<<" "<<width<<endl;
    if(height>width)
    {
        if(height>m)
        {
            printf("-1\n");
            return 0;
        }
        ans=height*height-cnt_b;
    }else if(width>height)
    {
        if(width>n)
        {
            printf("-1\n");
            return 0;
        }
        ans=width*width-cnt_b;
    }else
    {
        ans=height*width-cnt_b;
    }
    printf("%d\n",ans);
    return 0;
}
