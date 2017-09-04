#include <stdlib.h>
    #define _USE_MATH_DEFINES
    #include <algorithm>
    #include <cstdio>
    #include <functional>
    #include <iostream>
    #include <cfloat>
    #include <climits>
    #include <cstring>
    #include <cmath>
    #include <map>
    #include <queue>
    #include <random>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <string>
    #include <time.h>
    #include <vector>
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> i_i;
    typedef pair<ll, int> ll_i;
    typedef pair<double, int> d_i;
    typedef pair<ll, ll> ll_ll;
    typedef pair<double, double> d_d;
    struct edge { int u, v; ll w; };
     
    ll MOD = 1000000007;
    ll _MOD = 1000000009;
    double EPS = 1e-10;
     
    void dfs(int u, int x, vector<vector<i_i> >& G, vector<vector<bool> >& vis) {
    	vis[u][x] = true;
    	for (int i = 0; i < G[u].size(); i++) {
    		int v = G[u][i].first, y = G[u][i].second;
    		if (y == x && !vis[v][!y])
    			dfs(v, !y, G, vis);
    	}
    }
     
    bool solve(int N, int M, vector<int>& a, vector<int>& b, vector<int>& x) {
    	vector<vector<i_i> > G(N);
    	for (int i = 0; i < M; i++) {
    		G[a[i]].push_back(i_i(b[i], x[i]));
    		G[b[i]].push_back(i_i(a[i], x[i]));
    	}
    	for (int us = 0; us < N; us++)
    		for (int xs = 0; xs < 2; xs++) {
    			vector<vector<bool> > vis(N, vector<bool>(2));
    			dfs(us, xs, G, vis);
    			bool ok = true;
    			for (int i = 0; i < M; i++)
    				if (!vis[a[i]][x[i]] && !vis[b[i]][x[i]])
    					ok = false;
    			for (int u = 0; u < N; u++)
    				if (vis[u][0] && vis[u][1])
    					ok = true;
    			if (ok) return true;
    		}
    	return false;
    }
     
    int main() {
    	int N, M; cin >> N >> M;
    	vector<int> a(M), b(M), x(M);
    	for (int i = 0; i < M; i++) {
    		string c;
    		cin >> a[i] >> b[i] >> c;
    		a[i]--; b[i]--;
    		x[i] = (c == "r");
    	}
    	cout << (solve(N, M, a, b, x) ? "Yes" : "No") << endl;
    }
