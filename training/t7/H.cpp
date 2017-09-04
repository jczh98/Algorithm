#include <bits/stdc++.h>
using namespace std;
int t,timestamp;
string lines,ans;
int main()
{
    //freopen("h.in","r",stdin);
    scanf("%d",&t);
    getline(cin,lines);
    while(t--)
    {
        //cout<<t<<endl;
        timestamp=0;ans="";
        while(getline(cin,lines))
        {
            timestamp++;
            if(lines=="END OF CASE")break;
            for(int i=0;i<lines.size();i++)
            {
                if(lines[i]==';')
                {
                    cout<<timestamp;
                    cout<<": "<<ans<<";"<<endl;
                    ans="";
                }else ans+=lines[i];
            }
        }
    }
    return 0;
}
