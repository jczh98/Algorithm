#include <cstdio>
#include <cstring>
char s1[1000],s2[1000];
int a1[1000],a2[1000];
int main()
{
    scanf("%s%s",s1,s2);
    for(int i=0;i<strlen(s1);i++)a1[i]=(int)(s1[i]-'0'),a2[i]=(int)(s2[i]-'0');
    for(int i=0;i<strlen(s1);i++)a1[i]=a1[i]^a2[i];
    for(int i=0;i<strlen(s1);i++)printf("%d",a1[i]);
    printf("\n");
    return 0;
}
