#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pLL;
int w,h,b;
LL Gcd(LL a,LL b)
{
    if(a<b)swap(a,b);
    return b==0?a:Gcd(b,a%b);
}
struct Fraction
{
    LL up,down;
    Fraction(LL up=0,LL down=1):up(up),down(down){}
    Fraction operator + (const Fraction &rhs) const
    {
        LL u=up*rhs.down+down*rhs.up;
        LL d=down*rhs.down;
        if(u==0)return Fraction(0,1);
        LL g=Gcd(u,d);
        u/=g;d/=g;
        return Fraction(u,d);
    }
    Fraction operator / (const int &rhs) const
    {
        LL u=up;
        LL d=down*rhs;
        if(u==0)return Fraction(0,1);
        LL g=Gcd(u,d);
        u/=g;d/=g;
        return Fraction(u,d);
    }
};
set<pLL> st;
Fraction image[1000][1000],new_image[1000][1000];
int main()
{
    //Fraction f(0,1),g(1,1),t;
    //t=f/9;
    //cout<<t.up<<"/"<<t.down<<endl;
    scanf("%d%d%d",&w,&h,&b);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            scanf("%d",&image[i][j].up);
            image[i][j].down=1;
        }
    }
    while(b--)
    {
        for(int i=0;i<=h+1;i++)image[i][0]=image[i][w];
        for(int i=0;i<=h+1;i++)image[i][w+1]=image[i][1];
        for(int i=0;i<=w+1;i++)image[0][i]=image[h][i];
        for(int i=0;i<=w+1;i++)image[h+1][i]=image[1][i];
        /*for(int i=0;i<=h+1;i++)
        {
            for(int j=0;j<=w+1;j++)
            {
                cout<<image[i][j].up<<"/"<<image[i][j].down<<" ";
            }cout<<endl;
        }cout<<endl;*/
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                Fraction t(0,1);
                t=t+image[i][j];
                t=t+image[i+1][j+1];
                t=t+image[i+1][j];
                t=t+image[i][j+1];
                t=t+image[i-1][j];
                t=t+image[i][j-1];
                t=t+image[i-1][j-1];
                t=t+image[i+1][j-1];
                t=t+image[i-1][j+1];
                new_image[i][j]=t/9;
            }
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                image[i][j]=new_image[i][j];
            }
        }
        /*for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                cout<<image[i][j].up<<"/"<<image[i][j].down<<" ";
            }cout<<endl;
        }cout<<endl;*/
    }
    /*for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cout<<image[i][j].up<<"/"<<image[i][j].down<<" ";
        }cout<<endl;
    }*/
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            st.insert(make_pair(image[i][j].up,image[i][j].down));
        }
    }
    /*for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if(vis[i][j])ans++;
        }
    }*/
    printf("%d\n",st.size());
    return 0;
}
