#include <bits/stdc++.h>
#define MN 501000
using namespace std;
struct Acm
{
    struct Trie
    {
        int nxt[30],fail,num;
    }trie[MN];

    int cnt;
    queue<int> q;

    void Init()
    {
        for(int i=0;i<MN;i++)
        {
            memset(trie[i].nxt,0,sizeof(trie[i].nxt));
            trie[i].fail=trie[i].num=0;
        }
        cnt=1;
    }
    void Insert(char *s)
    {
        int x=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            int v=s[i]-'a';
            if(!trie[x].nxt[v])trie[x].nxt[v]=cnt++;
            x=trie[x].nxt[v];
        }
        trie[x].num++;
    }

    void GetFail()
    {
        trie[0].fail=-1;
        q.push(0);
        while(!q.empty())
        {
            int now=q.front();q.pop();
            for(int i=0;i<26;i++)
            {
                if(trie[now].nxt[i])
                {
                    if(now==0)trie[trie[now].nxt[i]].fail=0;
                    else
                    {
                        int k=trie[now].fail;
                        while(k!=-1)
                        {
                            if(trie[k].nxt[i])
                            {
                                trie[trie[now].nxt[i]].fail=trie[k].nxt[i];
                                break;
                            }
                            k=trie[k].fail;
                        }
                        if(k==-1)trie[trie[now].nxt[i]].fail=0;
                    }
                    q.push(trie[now].nxt[i]);
                }
            }
        }
    }
    int Match(char *s)
    {
        int x=0,res=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            int v=s[i]-'a';
            if(trie[x].nxt[v])x=trie[x].nxt[v];
            else
            {
                int k=trie[x].fail;
                while(k!=-1&&trie[k].nxt[v]==0)k=trie[k].fail;
                if(k==-1)x=0;
                else x=trie[k].nxt[v];
            }
            int now=x;
            while(now&&trie[now].num)
            {
                res+=trie[now].num;
                trie[now].num=0;
                now=trie[now].fail;
            }
        }
        return res;
    }
}acm;
int n,t;
char s[1000100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        acm.Init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%s",s),acm.Insert(s);
        acm.GetFail();
        scanf("%s",s);
        printf("%d\n",acm.Match(s));
    }
    return 0;
}
