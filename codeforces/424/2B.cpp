#include <bits/stdc++.h>
using namespace std;
char mpping[1000],first[30],second[30],origin[2000];
int main()
{
    scanf("%s%s",first,second);
    for(int i=0;i<26;i++)
    {
        mpping[first[i]]=second[i];
        mpping[toupper(first[i])]=toupper(second[i]);
    }
    scanf("%s",origin);
    for(int i=0;i<strlen(origin);i++)
    {
        if(isalpha(origin[i]))printf("%c",islower(origin[i])?mpping[origin[i]]:mpping[origin[i]]);
        else printf("%c",origin[i]);
    }
    printf("\n");
    return 0;
}
