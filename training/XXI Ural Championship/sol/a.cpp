#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string.h>

using namespace std;

#define MAX 100

int n, m;
int matr[MAX][MAX];

void print_yes() {
	printf("Yes\n");
	exit(0);
}

void print_no() {
	printf("No\n");
	exit(0);
}

int color[MAX];
int deg[MAX];
int deg_cnt[MAX];

void dfs(int x) {
	if (color[x]) return;
	color[x] = 1;
	for (int i = 0; i < n; i++) {
		if (matr[x][i]) {
			dfs(i);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		matr[a][b] = matr[b][a] = 1;
		deg[a]++;
		deg[b]++;
	}
	dfs(1);
	for (int i = 0; i < m; i++) {
		if (!color[i]) print_no();
	}
	for (int i = 0; i < n; i++) {
		deg_cnt[deg[i]]++;
	}

	if (deg_cnt[1] == 1 && deg_cnt[2] == n - 2 && deg_cnt[3] == 1) {
		print_yes();
	} else {
		print_no();
	}

	return 0;
}
