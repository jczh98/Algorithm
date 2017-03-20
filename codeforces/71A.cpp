#include <cstdio>
#include <cstring>
#include <cmath>
int n;
char word[100000];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",word);
        if(strlen(word)<=10)printf("%s\n",word);
        else
        {
            printf("%c%d%c\n",word[0],strlen(word)-2,word[strlen(word)-1]);
        }
    }
    return 0;
}
