#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int t,n,G[300][300],vis[300],match[300],ans;

int Dfs(int x){
	for(int i=1;i<=n;i++){
		if(!vis[i]&&G[x][i]){
			vis[i]=1;
			if(match[i]==-1||Dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

void Hungary(){
	ans=0;
	memset(match,-1,sizeof match);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if(Dfs(i))ans++;
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&G[i][j]);
			}
		}
		Hungary();
		if(ans==n){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
} 
