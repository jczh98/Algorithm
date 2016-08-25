#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a,b,c,d,k,sum[50010];

int prime[50010],check[50010],cnt,mu[50010],N=50010,ans;
void GetMu(){
	memset(check,0,sizeof check);
	cnt=0;mu[1]=1;
	for(int i=2;i<=N;i++){
		if(!check[i]){
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt&&i*prime[j]<N;j++){
			check[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else{
				mu[i*prime[j]]=-mu[i];
			}
		}
	}
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1]+mu[i];
	}
}

int Cal(int x,int y){
	int re=0,pos;
	x/=k,y/=k;
	for(int i=1;i<=x&&i<=y;i=pos+1){
		pos=min(x/(x/i),y/(y/i));
		re+=(sum[pos]-sum[i-1])*(x/i)*(y/i);
	}
	return re;
}

int main(){
	cin>>n;
	GetMu();
	while(n--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		ans=Cal(d,b)-Cal(a-1,d)-Cal(b,c-1)+Cal(a-1,c-1);
		printf("%d\n",ans);
	}		
	return 0;
} 
