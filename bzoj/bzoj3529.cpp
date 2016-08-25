#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define M 100100
#define N 100000
using namespace std;

struct Com{
	int n,m,a,id;
	
	bool operator < (const Com& x)const{
		return a<x.a;
	}
}query[M];

int t,prime[N],mu[N],check[N],cnt,fac[N],facsum[N],ans[M];
pair<int,int> F[N];

struct BIT{
	int c[M];
	
	void init(){
		memset(c,0,sizeof c);
	}
	
	int Lowbit(int x){
		return x&(-x);
	}
	
	void Add(int x,int d){
		while(x<M){
			c[x]+=d;
			x+=Lowbit(x);
		}	
	}
	
	int Sum(int x){
		int re=0;
		while(x>0){
			re+=c[x];
			x-=Lowbit(x);
		}
		return re;
	}
	
}T;

void Sieve(){
	memset(check,0,sizeof check);
	cnt=0;mu[1]=1;F[1].first=1;F[1].second=1;fac[1]=1;facsum[1]=1;
	for(int i=2;i<N;i++){
		if(!check[i]){
			prime[cnt++]=i;
			mu[i]=-1;
			fac[i]=i;
			facsum[i]=i+1;
			F[i].first=i+1;
			F[i].second=i;
		}
		for(int j=0;j<cnt&&i*prime[j]<N;j++){
			check[i*prime[j]]=1;
			F[i*prime[j]].second=i*prime[j];
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				fac[i*prime[j]]=fac[i]*prime[j];
				facsum[i*prime[j]]=facsum[i]+fac[i*prime[j]];
				F[i*prime[j]].first=F[i].first/facsum[i]*facsum[i*prime[j]];
				break;
			}else{
				mu[i*prime[j]]=-mu[i];
				fac[i*prime[j]]=prime[j];
				facsum[i*prime[j]]=prime[j]+1;
				F[i*prime[j]].first=F[i].first*(prime[j]+1);
			}
		}
	}
}

int Cal(int n,int m){
    int last,re=0;  
    if(n>m) swap(n,m);  
    for(int i=1;i<=n;i=last+1)  
    {  
        last=min(n/(n/i),m/(m/i));  
        re+=(n/i)*(m/i)*(T.Sum(last)-T.Sum(i-1));  
    }  
    return re&2147483647;  	
}

int main(){
	scanf("%d",&t);
	Sieve();
	T.init();
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&query[i].n,&query[i].m,&query[i].a);
		query[i].id=i;
	}
	sort(query+1,query+t+1);
	sort(F,F+N);
    for(int i=1,p=1;i<=t;i++)  
    {  
        while(F[p].first<=query[i].a)  
        {  
            for(int j=1;F[p].second*j<N;j++)  
                T.Add(F[p].second*j,F[p].first*mu[j]);  
            p++;  
        }  
        ans[query[i].id]=Cal(query[i].n,query[i].m);  
    }  
    for(int i=1;i<=t;i++)  
        printf("%d\n",ans[i]);  
    return 0;
}
