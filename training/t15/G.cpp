#include <bits/stdc++.h>
using namespace std;
int t,number,n,cur,x,len,pos[100000];
string str,tmp;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>t;cin.ignore();
    while(t--)
    {
        cin>>number;cin.ignore();
        //getline(cin,tmp);
        getline(cin,str);
        cin>>n;cin.ignore();
        //cout<<n<<" "<<str<<endl;
        len=str.size();
        pos[0]=0;
        printf("%d ",number);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            pos[i]=(pos[i-1]+x+len)%len;
            //cout<<x<<" "<<pos[i]<<" "<<str[pos[i]]<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            //if(pos[i]==41)cout<<i<<endl;
            cout<<str[pos[i]];
        }
        cout<<endl;
    }
}
