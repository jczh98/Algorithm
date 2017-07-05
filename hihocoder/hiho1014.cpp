#include <bits/stdc++.h>
#define MN 100100
using namespace std;
int n,m,cnt;
char s[4*MN];
struct Node
{
    int next[100],val;
}trie[4*MN];
int idx(char c){return c-'a';}
void Insert(char *ss)
{
    int len=strlen(ss),x=0;
    for(int i=0;i<len;i++)
    {
        int c=idx(ss[i]);
        if(!trie[x].next[c])
        {
            trie[x].next[c]=cnt++;
        }
        x=trie[x].next[c];
        trie[x].val++;
    }
}
int Find(char *ss)
{
    int len=strlen(ss),x=0;
    for(int i=0;i<len;i++)
    {
        int c=idx(ss[i]);
        if(!trie[x].next[c])
        {
            return 0;
        }
        x=trie[x].next[c];
    }
    return trie[x].val;
}
int main()
{
    cin>>n;
    memset(trie,0,sizeof(trie));
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        Insert(s);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        printf("%d\n",Find(s));
    }
    return 0;
}
