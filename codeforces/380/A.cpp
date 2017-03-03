#include <cstdio>
#include <cstring>
#define MN 100000

int n;
char s[MN];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int i=0;
    while(i<n)
    {
        if(s[i]=='o')
        {
            int j=i;
            while(j<n)
            {
                if(s[j+1]=='g'&&s[j+2]=='o')j+=2;
                else break;
            }
            if(i==j)printf("%c",s[i]);
            else i=j,printf("***");
        }else
        {
            printf("%c",s[i]);
        }
        i++;
    }
    return 0;
}
