#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

using namespace std;

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
//  printf("%d %d %d\n", n, m, k);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
//    printf("%d %d\n", a, b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> color(n, -1);
  vector<int> used(n, -1);
  int bad = -1;
  for (int i = 0; i < n; i++) {
    for (int u : g[i]) {
      if (color[u] != -1) {
        used[color[u]] = i;
      }
    }
    color[i] = 0;
    while (used[color[i]] == i) {
      color[i]++;
    }
    if (color[i] == k) {
      bad = i;
    }
  }

  if (bad == -1) {
    printf("coloring");
    for (int i = 0; i < n; i++) {
      printf(" %d", color[i] + 1);
    }
    printf("\n");
    return;
  }
  int id = bad;
  printf("path %d", id + 1);
  while (color[id]) {
    int pid = -1;
    for (int u : g[id]) {
      if (color[u] == color[id] - 1) {
        pid = u;
      }
    }
    assert(pid != -1);
    printf(" %d", pid + 1);
    id = pid;
  }
  printf("\n");
}

int main() {
#ifndef NOFILES
  freopen("pathorcoloring.in","r",stdin);
  freopen("pathorcoloring.out","w",stdout);
#endif

  int t;
  scanf("%d", &t);
  while (t --> 0) {
    solve();
  }
}
