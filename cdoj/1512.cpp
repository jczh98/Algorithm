#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,k,SSR[10]={0};
char s[1000];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        if(i>k)
        {
            printf("Feizhou Yin\n");
            return 0;
        }
        scanf("%s",s);
        SSR[6]++;
        if(SSR[6]==50)
        {
            printf("%d F\n",i);
            return 0;
        }
        for(int j=0;j<strlen(s);j++)
        {
            SSR[s[j]-'A'+1]++;
            if(SSR[1]==50)
            {
                printf("%d A\n",i);
                return 0;
            }
            if(SSR[2]==50)
            {
                printf("%d B\n",i);
                return 0;
            }
            if(SSR[3]==50)
            {
                printf("%d C\n",i);
                return 0;
            }
            if(SSR[4]==50)
            {
                printf("%d D\n",i);
                return 0;
            }
            if(SSR[5]==50)
            {
                printf("%d E\n",i);
                return 0;
            }
            if(SSR[6]==50)
            {
                printf("%d F\n",i);
                return 0;
            }
        }
    }
    if(n<k)printf("AMNZ\n");
    else if(n==k)printf("Feizhou Yin\n");
    return 0;
}
