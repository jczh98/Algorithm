#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#define MN 1000+10
using namespace std;

int t,line;
char tree[MN][MN],s[MN];

void Dfs(int r,int c)
{
    printf("%c(",tree[r][c]);
    if(r+1<line&&tree[r+1][c]=='|')
    {
        int i=c;
        while(i-1>=0&&tree[r+2][i-1]=='-')i--;
        while(tree[r+2][i]=='-'&&tree[r+3][i]!='\0')
        {
            if(!isspace(tree[r+3][i]))Dfs(r+3,i);
            i++;
        }
    }
    printf(")");
    return;
}

int main()
{
    fgets(s,MN,stdin);
    sscanf(s,"%d",&t);
    while(t--)
    {
        line=0;
        memset(tree,0,sizeof(tree));
        while(true)
        {
            fgets(tree[line],MN,stdin);
            if(tree[line][0]=='#')break;
            else line++;
        }
        printf("(");
        if(line)for(int i=0;i<strlen(tree[0]);i++)
        {
            if(tree[0][i]!=' ')
            {
                Dfs(0,i);break;
            }
        }
        printf(")\n");
    }
    return 0;
}
