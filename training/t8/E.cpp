#include <bits/stdc++.h>
using namespace std;
char str[1000];
int cnt[1000]={0},sum=0,ans=0;
int main()
{
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        cnt[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)if(cnt[i])sum++;
    if(sum<=2)
    {
        printf("0\n");
    }else
    {
        int i=0;
        sort(cnt,cnt+26);
        //for(int j=0;j<26;j++)cout<<cnt[j]<<" ";
        while(!cnt[i])i++;
        for(;i<24;i++)
        {
            ans+=cnt[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
