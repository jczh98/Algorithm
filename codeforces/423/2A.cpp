#include <bits/stdc++.h>
using namespace std;
int n,t,one_seat,two_seat,two_single,ans=0;;
int main()
{
    two_single=0;
    scanf("%d%d%d",&n,&one_seat,&two_seat);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            if(one_seat)
            {
                one_seat--;
            }else
            {
                if(two_seat)
                {
                    two_single++;
                    two_seat--;
                }else
                {
                    if(two_single)
                    {
                        two_single--;
                    }else
                    {
                        ans++;
                    }
                }
            }
        }else
        {
            if(two_seat)
            {
                two_seat--;
            }else
            {
                ans+=2;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
