#include <bits/stdc++.h>
#define MN 100010
using namespace std;
int k,h[MN];
char str[MN];
int main()
{
    memset(h,0,sizeof(h));
    scanf("%d",&k);
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='1')
        {
            if(h[i%k])
            {
                printf("%d %d\n",h[i%k],i+1);
                return 0;
            }
            h[(i+1)%k]=i+1;
        }
    }
    printf("0 0\n");
    return 0;
}
