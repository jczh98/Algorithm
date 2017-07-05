#include <bits/stdc++.h>
using namespace std;
char str[10100];
int main()
{
    fgets(str,10000,stdin);
    for(int i=0;i<strlen(str);i++)
    {
        int c=str[i];c=tolower(c);
        if(c=='a')
        {
            printf("@");
        }else if(c=='b')
        {
            printf("8");
        }else if(c=='c')
        {
            printf("(");
        }else if(c=='d')
        {
            printf("|)");
        }else if(c=='e')
        {
            printf("3");
        }else if(c=='f')
        {
            printf("#");
        }else if(c=='g')
        {
            printf("6");
        }else if(c=='h')
        {
            printf("[-]");
        }else if(c=='i')
        {
            printf("|");
        }else if(c=='j')
        {
            printf("_|");
        }else if(c=='k')
        {
            printf("|<");
        }else if(c=='l')
        {
            printf("1");
        }else if(c=='m')
        {
            printf("[]\\/[]");
        }else if(c=='n')
        {
            printf("[]\\[]");
        }else if(c=='o')
        {
            printf("0");
        }else if(c=='p')
        {
            printf("|D");
        }else if(c=='q')
        {
            printf("(,)");
        }else if(c=='r')
        {
            printf("|Z");
        }else if(c=='s')
        {
            printf("$");
        }else if(c=='t')
        {
            printf("']['");
        }else if(c=='u')
        {
            printf("|_|");
        }else if(c=='v')
        {
            printf("\\/");
        }else if(c=='w')
        {
            printf("\\/\\/");
        }else if(c=='x')
        {
            printf("}{");
        }else if(c=='y')
        {
            printf("`/");
        }else if(c=='z')
        {
            printf("2");
        }else printf("%c",c);
    }
    return 0;
}
