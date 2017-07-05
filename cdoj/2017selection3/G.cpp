#include <bits/stdc++.h>
using namespace std;
int n,flag=0;
char str1[1100],str2[1100];
int main()
{
    scanf("%d%s%s",&n,str1,str2);
    if(n%2)
    {
        for(int i=0;i<strlen(str1);i++)if(str1[i]==str2[i]){flag=1;break;}
        if(flag)printf("Deletion failed\n");else printf("Deletion succeeded\n");
    }else
    {
        for(int i=0;i<strlen(str1);i++)if(str1[i]!=str2[i]){flag=1;break;}
        if(flag)printf("Deletion failed\n");else printf("Deletion succeeded\n");
    }
    return 0;
}
