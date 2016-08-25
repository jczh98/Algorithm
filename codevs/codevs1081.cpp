#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,q,a,b,x,num,num2;

int c[100010];

int Lowbit(int x){
	return x&-x; 
} 

int Query(int x){
	int re=0;
	while(x>0){
		re+=c[x];x-=Lowbit(x);
	}
	return re;
}

void Add(int x,int d){
	while(x<=n){
		c[x]+=d;x+=Lowbit(x);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		Add(i,num);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&num);
		if(num==1){
			scanf("%d%d%d",&a,&b,&x);
			for(int i=a;i<=b;i++){
				Add(i,x);
			}
		}else if(num==2){
			scanf("%d",&num2);
			printf("%d\n",Query(num2)-Query(num2-1));
		}
	}
}
