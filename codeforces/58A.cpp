#include <cstdio>
#include <cstring>
char s[1000],h[]={"hello"};
int pos=0;
int main()
{
    scanf("%s",s);
    for(int i=0;i<strlen(h);i++)
    {
        if(h[i]==s[pos])
        {
            pos++;
        }else
        {
            while(h[i]!=s[pos])
            {
                pos++;
                if(pos>=strlen(s))
                {
                    printf("NO\n");
                    return 0;
                }
            }
            pos++;
        }
    }
    printf("YES\n");
    return 0;
}
