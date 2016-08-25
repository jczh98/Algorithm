#include <cstdio>
#include <iostream>
using namespace std;

int t,n,p;
int ans;

int Ksm(int a,int b){
	int re=1;
	a%=p;
	while(b){
		if(b&1)re=(re*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return re%p;
}

int Euler(int x){
	int re=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			re=re/i*(i-1);
			while(x%i==0)x/=i;
		}			
	}
	if(x>1)re=re/x*(x-1);	
	return re%p;
}

int main(){
	cin>>t;
	while(t--){
		ans=0;
		scanf("%d%d",&n,&p);
		for(int i=1;i*i<=n;i++){	
			if(n%i==0){
				if(i*i!=n)ans+=Euler(n/i)*Ksm(n,i-1),ans%=p;
				ans+=Euler(i)*Ksm(n,n/i-1),ans%=p;				
			}		

		}
		cout<<ans<<endl;
	}	
	return 0;
}
