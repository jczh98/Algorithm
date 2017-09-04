#include <bits/stdc++.h>
using namespace std;
int t,infection_mon,infection_year,strike_mon,strike_year;
char str[1000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&infection_mon,str);
        infection_year=atoi(str);
        scanf("%d%s",&strike_mon,str);
        strike_year=atoi(str);
        //cout<<infection_year<<" "<<strike_year<<endl;
        if(infection_year==strike_year)
        {
            int rat=12-infection_mon+1;
            double ans=1.0/2.0/rat*(strike_mon-infection_mon);
            //cout<<ans<<endl;
            printf("%.4f\n",ans);
        }else
        {
            int rat=12-infection_mon+1;
            double ans=(strike_year-infection_year-1)+1.0/2.0+1.0/12.0*(strike_mon-1);
            //cout<<strike_mon<<endl;
            printf("%.4f\n",ans);
        }
    }
    return 0;
}
