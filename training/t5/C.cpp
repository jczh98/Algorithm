#include <bits/stdc++.h>
using namespace std;
int t,r,c,mp[500][500],cnt_r[500][500],cnt_c[500][500],ans,t1,t2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt_r,0,sizeof(cnt_r));
        memset(cnt_c,0,sizeof(cnt_c));
        ans=0;
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(mp[i][j])
                {
                    cnt_r[i][j]=cnt_r[i][j-1]+1;
                    cnt_c[i][j]=cnt_c[i-1][j]+1;
                }else
                {
                    cnt_r[i][j]=cnt_r[i][j-1];
                    cnt_c[i][j]=cnt_c[i-1][j];
                }
            }
        }
 		for(int i=1;i<=r-1;i++)
        {
 			for(int j=1;j<=c-1;j++)
 			{
 				if(!mp[i][j]||!mp[i+1][j]||!mp[i][j+1])continue;
 				if(mp[i+1][j+1])ans++;
 				t1=t2=0;
 				for(int k=2;i+k<=r&&j+k<=c;k++){
 					if(!mp[i+k][j]||!mp[i][j+k]) break;
 					int t=cnt_r[i+k-1][j+k-1]-cnt_r[i+k-1][j]+cnt_c[i+k-1][j+k-1]-cnt_c[i][j+k-1]-mp[i+k-1][j+k-1];
 					t1+=(k-1)*2-1-t;t2+=t;
 					t=cnt_r[i+k][j+k]-cnt_r[i+k][j-1]+cnt_c[i+k][j+k]-cnt_c[i-1][j+k]-mp[i+k][j+k];
 					if(t!=(k+1)*2-1) continue;
 					if(abs(t1-t2)<=1)ans++;
 				}
 			}
 		}
        printf("%d\n",ans);
    }
    return 0;
}
