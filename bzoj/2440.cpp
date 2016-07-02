#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 100000
using namespace std;
 
int mu[1000000],prime[1000000],check[1000000],tot;
int t,k,ans;
void Get_Mu(){
    int i,j;
    memset(check,0,sizeof(check));
    mu[1]=1;tot=0;
    for(i=2;i<MAXN;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(j=0;j<tot;j++){
            if(i*prime[j]>MAXN)break;
            check[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}
 
int Calculate(int x){
    int re=0,u=sqrt(x),i;
    for(i=1;i<=u;i++){
        re+=mu[i]*(x/(i*i));
    }
    return re;
}
 
void Dichotomie(int x){
    int l=1,r=x<<1,m;
    while(l+1<r){
        m=(l>>1)+(r>>1)+(l&r&1);
        if(Calculate(m)>=k)ans=m,r=m;
        else l=m;
    }
}
int main(){
    Get_Mu();   
    cin>>t;
    while(t--){
        scanf("%d",&k);
        ans=1;
        Dichotomie(k);
        printf("%d\n",ans);
    }
}