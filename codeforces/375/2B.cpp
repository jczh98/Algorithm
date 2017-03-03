#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>
#include <climits>
#include <cctype>
using namespace std;

char s[1000];
int n,longest_word=0,inside_words,flag;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int cnt=0;flag=0;inside_words=0;
    s[n]='*';
    for(int i=0;i<=n;i++)
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
        {
            cnt++;
        }else
        {
            if(flag==0&&longest_word<cnt)longest_word=cnt;
            cnt=0;
            if(flag==1&&isalpha(s[i-1]))inside_words++;
            if(s[i]=='(')
            {
                flag=1;
            }else if(s[i]==')')
            {
                flag=0;
            }
        }
    }
    printf("%d %d\n",longest_word,inside_words);
    return 0;
}
