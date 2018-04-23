#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<map>
#include<math.h>
#define N 100100
#define ll long long
using namespace std;

inline ll read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

struct node {
	ll x,d,next;
} edge[2*N];
ll tot;
ll head[N];
//vector<node> G[N];
ll E[2*N];//dfs时记录的节点，每条边记录2遍，共记录2*N-1个节点
ll D[2*N];//表示dfs记录路径的各个点的深度
ll first[N];//first[i]表示记录路径中第一次访问i点的位置下标
ll vis[N];//是否访问过
ll dis[N];//记录距离根节点的距离
ll n,m,top;//top表示数组下标
ll dp[30][2*N];//dp[i][j]表示从j点开始，数2^i个点区间内的最大值或最小值，在此题中记录的为最小深度
bool flag[N];
void addedge(ll u,ll v, ll w) {
	edge[tot].x=v;
	edge[tot].d=w;
	edge[tot].next=head[u];
	head[u]=tot++;
}

void dfs(ll u,ll dep, ll w) { //正在访问的点u，该点的深度dep，距离根节点的最短路径w
	vis[u]=1;
	E[top]=u;
	D[top]=dep;
	first[u]=top++;
	dis[u]=w;
	for(ll i=head[u]; i!=-1; i=edge[i].next) {
		if(!vis[edge[i].x]) {
			ll v=edge[i].x;
			ll cost=edge[i].d;
			dfs(v,dep+1,w+cost);
			E[top]=u;
			D[top++]=dep;//回溯时再次访问该点，记录下来
		}
	}
	/*
	    for(ll i=0;i<G[u].size();i++)
	    {
	        if(!vis[G[u][i].x])
	        {
	            ll v=G[u][i].x;
	            ll cost=G[u][i].d;
	            dfs(v,dep+1,w+cost);
	            E[top]=u;
	            D[top++]=dep;//回溯时再次访问该点，记录下来

	        }
	    }
	    */
}
void ST(ll num) {
	//动态规划记录各个区间，及两个点的最近公共祖先所在位置即E和D的下标
	for(ll i=1; i<=num; i++)
		dp[0][i]=i;//当长度为 1，起点为 i 时，最近公共祖先为本身
	//外循环必须为区间长度，先求出区间长度为1的值才能求出区间长度为2的值，依次类推
	//内循环为起点
	for(ll i=1; (1<<i)<=num; i++) {
		for( ll j=1; j<=num; j++) {
			if(j+(1<<i)-1 <= num) { //区间的右端点必须不大于最大值，1<<i (i=0,1,2,3...时，该值为1,2,4,8... )
				ll a=dp[i-1][j];
				ll b=dp[i-1][j+(1<<i>>1)];//右半个区间，1<<i>>1相当于2^(i-1)
				if(D[a]<D[b])
					dp[i][j]=a;
				else
					dp[i][j]=b;
			}
		}
	}
}
ll RMQ(ll x,ll y) {
	int k=0;
	while( (1<<(k+1)) <=y-x+1) k++;//注意这个地方！！！
	ll a=dp[k][x];
	ll b=dp[k][y-(1<<k)+1];
	if(D[a]<D[b])
		return a;
	return b;
}
ll mapp[N];
int main() {
	cin >> n;
	for(ll i = 1; i<=n; i++) {
		ll turn = read();
		mapp[turn] = i;
	}
	memset(dis,0,sizeof(dis));
	memset(first,0,sizeof(first));
	memset(E,0,sizeof(E));
	memset(D,0,sizeof(D));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(flag,0,sizeof(flag));
	memset(dp,0,sizeof(dp));
	tot=0;
	top=0;
	ll a,b,w;
	m = n - 1;
	while(m--) {
		a = read();
		b = read();
		w = read();
		addedge(a,b,w);
		addedge(b,a,w);
		flag[b]=1;
	}
	ll root;
	for(ll i=1; i<=n; i++) {
		if(!flag[i]) {
			root=i;
			break;
		}
	}
	dfs(root,0,0);
	ST(top-1);
	ll k;
	cin >> k;
	while(k--) {
		a = read();
		b = read();
		a = mapp[a];
		b = mapp[b];
		ll x=first[a];
		ll y=first[b];
		if(x>y)
			swap(x,y);
		ll pos=RMQ(x,y);
		printf("%lld\n",dis[a]+dis[b]-(ll)2*dis[E[pos]]);
	}
	return 0;
}
