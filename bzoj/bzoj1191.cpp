#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Com{
	int to,next;
}edge[10000];

int head[10000];
int cnt=1;
void Add(int u,int v){
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

int n,m,vis[10000],match[10000],ans,t;

int Dfs(int x){
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v]!=t){
			vis[v]=t;
			if(match[v]==-1||Dfs(match[v])){
				match[v]=x;
				return 1;
			}
		}
	}
	return 0;
}

void Hungary(){
	ans=0;t=0;
	memset(match,-1,sizeof match);
	for(int i=1;i<=m;i++){
		t++;
		if(Dfs(i))ans++;
		else break;
	} 
}
int main(){
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		Add(i,a+1);Add(i,b+1);
	}	
	Hungary();
	cout<<ans<<endl;
	return 0;
}
