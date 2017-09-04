#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define INF 2139062143
#define inf -2139062144
#define MOD 1000000007
#define mem(a,b) memset((a),b,sizeof(a))
#define TS printf("!!!\n")
#define pb push_back
#define pai pair<int,int>
using namespace std;
string ori,pat;
int n,nxt[1001000],ans=0;
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
        cin>>ori>>pat;
        if(pat.size()>ori.size())
        {
            cout<<"Bob"<<endl;
        }else
        {
            int flag1=0,flag2=0;
            ans=0;Kmp();
            if(ans)flag1=1;
            reverse(pat.begin(),pat.end());
            string t="";
            int j;
            for(j=0;j<pat.size();j++)
            {
                if(pat[j]!='0')break;
            }
            for(;j<pat.size();j++)
            {
                t+=pat[j];
            }
            pat=t;
            ans=0;Kmp();
            if(ans)flag2=1;
            if(flag1||flag2)cout<<"Alice"<<endl;else cout<<"Bob"<<endl;
        }
    }
    return 0;
}
