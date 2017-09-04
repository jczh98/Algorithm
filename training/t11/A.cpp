#include <bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
int bull=0,cow=0;
map<char,int> cow_cnt,pos;
int main()
{
    freopen("bulls.in","r",stdin);
    freopen("bulls.out","w",stdout);
    scanf("%s%s",s1,s2);
    for(int i=0;i<4;i++)
    {
        cow_cnt[s1[i]]=1;
        pos[s1[i]]=i;
    }
    for(int i=0;i<4;i++)
    {
        if(s2[i]==s1[i])
        {
            bull++;
        }else if(cow_cnt.count(s2[i])&&pos[s2[i]]!=i)
        {
            cow++;
        }
    }
    printf("%d %d\n",bull,cow);
    return 0;
}
