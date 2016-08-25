#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

LL SG(LL x){
	return x%2==0?x/2:SG(x/2);
}

int t,n;
LL a,s;
int main(){
	cin>>t;
	while(t--){
		s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)cin>>a,s^=SG(a);
		if(s)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
