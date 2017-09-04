#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Fraction {
private :
    LL rator;
    LL nator;
public :
    Fraction(LL rator = 0,LL nator = 1) {
        this->rator = rator; this->nator = nator;
        if(this->nator < 0) {
            this->rator *= -1;
            this->nator *= -1;
        }
    }
    friend Fraction operator+(const Fraction &fa, const Fraction &fb) {
        Fraction ft;
        ft.rator = fa.rator * fb.nator + fa.nator * fb.rator;
        ft.nator = fa.nator * fb.nator;
        LL tmp = __gcd(ft.rator,ft.nator);
        ft.rator /= tmp;
        ft.nator /= tmp;
        return ft;
    }
    friend Fraction operator-(const Fraction &fa, const Fraction &fb) {

        Fraction ft;
        ft.rator = fa.rator * fb.nator - fa.nator * fb.rator;
        ft.nator = fa.nator * fb.nator;
        LL tmp = __gcd(ft.rator,ft.nator);
        ft.rator /= tmp;
        ft.nator /= tmp;
        if(ft.nator < 0) {
            ft.rator *= -1;
            ft.nator *= -1;
        }
        return ft;
    }
    friend Fraction operator*(const Fraction &fa, const Fraction &fb) {
        Fraction ft;
        ft.rator = fa.rator * fb.rator;
        ft.nator = fa.nator * fb.nator;
        LL tmp = __gcd(ft.rator,ft.nator);
        ft.rator /= tmp;
        ft.nator /= tmp;
        return ft;
    }
    void Show() const {
        if(nator == 1 || rator == 0) cout << rator << endl;
        else
        {
            if(rator*nator<0)
            {
                cout << "-" << abs(rator) << '/' << abs(nator) << endl;
            }else
            {
                cout << abs(rator) << '/' << abs(nator) << endl;
            }

        }
    }
};


LL t,number,m,k;
Fraction frac[1000][1000],tmp;
int main()
{
    //freopen("out.txt","r",stdin);
    frac[0][1]=Fraction(1);
    for(int i=1;i<=500;i++)
    {
        for(int j=2;j<=i+1;j++)
        {
            tmp=Fraction(i,j);
            frac[i][j]=tmp*frac[i-1][j-1];
            //frac[i][j].Show();
        }
        tmp=Fraction(1);
        for(int j=2;j<=i+1;j++)tmp=tmp-frac[i][j];
        frac[i][1]=tmp;
    }
    cin>>t;
    while(t--)
    {
        cin>>number>>m>>k;
        cout<<number<<" ";
        frac[m][k].Show();
    }
    return 0;
}
