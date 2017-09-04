#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,number,b,rem,len;
LL sum;
char str[50005000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%s",&number,&b,str);
        rem=0;len=strlen(str);sum=1;
        for(int i=len-1;i>=0;i--)
        {
            rem=(rem+(str[i]-'0')%(b-1)*sum%(b-1))%(b-1);
            sum=(sum%(b-1)*b%(b-1))%(b-1);
        }
        printf("%d %d\n",number,rem);
    }
    return 0;
}
