#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


#define REP_ab(i,a,b) for(int i = a; i <= b; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP_1(i,n) for(int i = 1; i <= n; i++)
#define DEP(i,n) for(int i = n - 1; i >= 0; i--)
#define DEP_N(i,n) for(int i = n; i >= 1; i--)
#define CPY(A,B) memcpy(A,B,sizeof(B))
#define MEM(A) memset(A,0,sizeof(A))
#define MEM_1(A) memset(A,-1,sizeof(A))
#define MEM_INF(A) memset(A,0x3f,sizeof(A))
#define MEM_INFLL(A) memset(A,0x3f3f,sizeof(A))
#define mid ((l + r) >> 1)
#define lson (l, mid, u << 1)
#define rson (mid + 1, r, u << 1 | 1)
#define ls (u << 1)
#define rs (u << 1 | 1)


typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5000 + 5;
const int MAXM = 100000 + 5;
const int mod = 1e9 + 7;

struct Edge {
	int to,next,cap,flow;
} edge[MAXM]; //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];
void init() {
	tol = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw = 0) {
	edge[tol].to = v;
	edge[tol].cap = w;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = rw;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}
int Q[MAXN];
void BFS(int start,int end) {
	memset(dep,-1,sizeof(dep));
	memset(gap,0,sizeof(gap));
	gap[0] = 1;
	int front = 0, rear = 0;
	dep[end] = 0;
	Q[rear++] = end;
	while(front != rear) {
		int u = Q[front++];
		for(int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if(dep[v] != -1)continue;
			Q[rear++] = v;
			dep[v] = dep[u] + 1;
			gap[dep[v]]++;
		}
	}
}
int S[MAXN];
int sap(int start,int end,int N) {
	BFS(start,end);
	memcpy(cur,head,sizeof(head));
	int top = 0;
	int u = start;
	int ans = 0;
	while(dep[start] < N) {
		if(u == end) {
			int Min = INF;
			int inser;
			for(int i = 0; i < top; i++)
				if(Min > edge[S[i]].cap - edge[S[i]].flow) {
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
				}
			for(int i = 0; i < top; i++) {
				edge[S[i]].flow += Min;
				edge[S[i]^1].flow -= Min;
			}
			ans += Min;
			top = inser;
			u = edge[S[top]^1].to;
			continue;
		}
		bool flag = false;
		int v;
		for(int i = cur[u]; i != -1; i = edge[i].next) {
			v = edge[i].to;
			if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
				flag = true;
				cur[u] = i;
				break;
			}
		}
		if(flag) {
			S[top++] = cur[u];
			u = v;
			continue;
		}
		int Min = N;
		for(int i = head[u]; i != -1; i = edge[i].next)
			if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		gap[dep[u]]--;
		if(!gap[dep[u]])return ans;
		dep[u] = Min + 1;
		gap[dep[u]]++;
		if(u != start)u = edge[S[--top]^1].to;
	}
	return ans;
}

int del[MAXN];
int down[MAXM];


int main() {
	int n1,n2,m,L,R;
	int cas = 1;
	while(scanf("%d%d%d",&n1,&n2,&m) != EOF) {
		scanf("%d%d", &L, &R);
		int s,t;
		s = 0,t = n1 + n2 + 3;
		MEM(del);
		init();
        int us = n1 + n2 + 1, ut = n1 + n2 + 2;
        addedge(ut,us,INF);
		addedge(us,t,n1*L);
		addedge(s,ut,n2*L);
        int sum = n2*L;
        REP_1(i,n1) {
			addedge(us,i,R-L);
			addedge(s,i,L);
			sum+=L;
        }
        REP_1(i,n2) {
            addedge(i+n1,ut,R-L);
			addedge(i+n1,t,L);
        }
		REP_1(i,m) {
			int u,v;
			scanf("%d%d",&u,&v);
			v += n1;
			addedge(u,v,1);
		}
        if(sap(s, t, n1+n2+4) == sum) {
            printf("Case %d: Yes\n", cas++);
        } else {
            printf("Case %d: No\n", cas++);
        }
	}
	return 0;
}
