#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n,k,ans1,ans2;
string s[1000],ans;

bool cmp(string a,string b)
{
    return a.size()<b.size();
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>ans;
	sort(s,s+n,cmp);
	ans1=ans2=0;
	for(int i=0;i<n&&(s[i].size()<=ans.size());i++)
    {
        if(s[i].size()<ans.size())ans1++;
        if(s[i].size()==ans.size()&&(s[i]!=ans))ans2++;
    }
    printf("%d %d\n",ans1+ans1/k*5+1,ans1+ans2+(ans1+ans2)/k*5+1);
	return 0;
}
