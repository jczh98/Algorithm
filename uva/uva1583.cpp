#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 100010
using namespace std;

int t,n,ans[MN];

void Pre(){
	memset(ans,0,sizeof ans);
	for(int i=1;i<=MN;i++){
		int x=i,y=i;
		while(x>0){
			y+=x%10;x/=10;
		}
		if(ans[y]==0)ans[y]=i;
	}
}

int main(){
	Pre();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}	
	return 0;
}
