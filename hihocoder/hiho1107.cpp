#include <bits/stdc++.h>
#define MN 2000000
using namespace std;
int n,cnt=1,ans=0;
string str;
struct Node
{
    int next[100],num;
}trie[MN+100];
void Insert(string s)
{
    int x=0;

    for(int i=0;i<s.size();i++)
    {
        int idx=s[i]-'a';
        for(int i=0;i<=27;i++)trie[cnt].next[i]=0;
        if(!trie[x].next[idx])
        {
            trie[x].next[idx]=cnt++;
        }
        x=trie[x].next[idx];
        trie[x].num++;
    }
}
void Dfs(int x)
{
    if(trie[x].num<=5&&trie[x].num!=0)
    {
        ans++;return;
    }
    for(int i=0;i<26;i++)
    {
        if(trie[x].next[i])Dfs(trie[x].next[i]);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        Insert(str);
    }
    Dfs(0);
    cout<<ans<<endl;
    return 0;
}
