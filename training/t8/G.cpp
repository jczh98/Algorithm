#include <bits/stdc++.h>
using namespace std;
int n;
struct Stu
{
    string first,last;
    bool operator < (const Stu &rhs) const
    {
        if(last==rhs.last)
        {
            //int t=first.compare(rhs.first);
            //if(t==1)return false;else return true;
            return first<rhs.first;
        }else
        {
            /*int t=last.compare(rhs.last);
            if(t==1)return false;else return true;*/
            return last<rhs.last;
        }
    }
}student[1000];
int main()
{
    /*string s1("Aeam");
    string s2("Adam");
    cout<<s1.compare(s2)<<endl;*/
    cin>>n;
    for(int i=1;i<=n;i++)cin>>student[i].first>>student[i].last;
    sort(student+1,student+1+n);
    for(int i=1;i<=n;i++)cout<<student[i].first<<" "<<student[i].last<<endl;
    return 0;
}
