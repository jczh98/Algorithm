#include <bits/stdc++.h>
typedef long long ll;
const int N=100010;
int n,m,i,w[N],l[N],r[N],st[N],en[N],len[N],op,x,y;
int dfn;
ll c[N];
inline ll lowbit(ll o) {
	return o & -o;
}
ll query(ll o) {
	ll res=0;
	while (o > 0) {
		res += c[o];
		o -= lowbit(o);
	}
	return res;
}
void update(ll i, ll val) {
	while (i <= dfn) c[i] += val, i += lowbit(i);
}
void dfs(int x) {
	st[x]=++dfn;
	if(l[x]) dfs(l[x]);
	if(r[x]) dfs(r[x]);
	en[x]=dfn;
}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=n+1; i++) {
		scanf("%d",&w[i]);
	}
	for(i=1; i<=n; i++) {
		scanf("%d%d%d",&len[i],&l[i],&r[i]);
		if(l[i]<0)	l[i]=n-l[i];
		if(r[i]<0)	r[i]=n-r[i];
	}
	dfs(1);
	for(i=1; i<=n+1; i++)update(st[n+i],w[i]);
	while(m--) {
		scanf("%d%d",&op,&x);
		if(op==1) {
			scanf("%d",&y);
			update(st[n+x],y-w[x]);
			w[x]=y;
		} else {
			ll lw = query(en[l[x]])-query(st[l[x]]-1);
			ll rw = query(en[r[x]])-query(st[r[x]]-1);
			double ans = (double)rw * (double)len[x] / ((double)lw + (double)rw);
			printf("%.16f\n",ans);
		}
	}
}
