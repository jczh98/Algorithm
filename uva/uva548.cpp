#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int n,lch[10010],rch[10010],in_order[10010],post_order[10010];

int Input(int *a){
	string line;
	while(!getline(cin,line))return false;
	stringstream ss(line);
	n=0;int x;
	while(ss>>x)a[n++]=x;
	return n>0;
}

int Build(int L1,int R1,int L2,int R2){
	if(L1>R1||L2>R2)return 0;
	int root=post_order[R2],pos=0,cnt;
	while(in_order[pos]!=root)pos++;
	lch[root]=Build(L1,pos-1,L2,L2+(pos-1-L1));
	rch[root]=Build(pos+1,R1,L2+(pos-L1),R2-1);
	return root;
}

int minn,min_sum;

void Dfs(int u,int sum){
	sum+=u;
	if(!lch[u]&&!rch[u])if(sum<min_sum||(sum==min_sum&&u<minn)){
		minn=u;min_sum=sum;
	}
	if(lch[u])Dfs(lch[u],sum);
	if(rch[u])Dfs(rch[u],sum);
}

int main(){
	while(Input(in_order)){
		Input(post_order);
		memset(lch,0,sizeof lch);
		memset(rch,0,sizeof rch);
		Build(0,n-1,0,n-1);
		min_sum=minn=(1<<30);
		Dfs(post_order[n-1],0);
		printf("%d\n",minn);
	}	
	return 0;
}
