#include <cstdio>
#include <iostream>
using namespace std;

int a[200010],n,m,b,c,d[200010][100],k;

void RmqInit(){
	for(int i=1;i<=n;i++) d[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		}
	}
}

int Rmq(int l,int r){
	k=0;
	while((1<<(k+1))<=r-l+1)k++;
	return max(d[l][k],d[r-(1<<k)+1][k]); 
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	RmqInit();
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b,&c);
		printf("%d\n",Rmq(b,c));
	} 
	return 0;
}
