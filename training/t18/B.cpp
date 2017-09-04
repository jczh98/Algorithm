#include <bits/stdc++.h>
using namespace std;
int t,q,m;
char s1[100],s2[100];
set<char> st[200];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&q,&m);
        for(int i=1;i<=q;i++)
        {
            st[i].insert('A');
            st[i].insert('B');
            st[i].insert('C');
            st[i].insert('D');
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=q;j++)
            {
                scanf("%s%s",s1,s2);
                if(s2[0]=='F')
                {
                    if(st[j].count(s1[0]))
                    {
                        st[j].erase(st[j].find(s1[0]));
                    }
                }else if(s2[0]=='T')
                {
                    st[j].clear();
                    st[j].insert(s1[0]);
                }
            }
        }
        for(int i=1;i<q;i++)
        {
            if(st[i].size()==1)
            {
                printf("%c ",*st[i].begin());
            }else
            {
                printf("? ");
            }
        }
        if(st[q].size()==1)
        {
            printf("%c\n",*st[q].begin());
        }else
        {
            printf("?\n");
        }
    }
    return 0;
}
