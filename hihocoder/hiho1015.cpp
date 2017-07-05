#include <bits/stdc++.h>
using namespace std;
string ori,pat;
int n,nxt[100000],ans=0;
int GetNext()
{
    nxt[0]=nxt[1]=0;
    for(int i=1;i<pat.size();i++)
    {
        int j=nxt[i];
        while(j&&pat[i]!=pat[j])j=nxt[j];
        nxt[i+1]=((pat[i]==pat[j])?j+1:0);
    }
}
int Kmp()
{
    memset(nxt,0,sizeof(nxt));
    GetNext();
    int j=0;
    for(int i=0;i<ori.size();i++)
    {
        while(j&&ori[i]!=pat[j])j=nxt[j];
        if(ori[i]==pat[j])j++;
        if(j==pat.size())ans++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>pat>>ori;
        ans=0;
        Kmp();
        printf("%d\n",ans);
    }
    return 0;
}
