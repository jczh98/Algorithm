#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int MAXN = 100;

vector<int> f[2*MAXN];
vector<int> g[MAXN];
int conv(int x) {
  if (x > 0) return 2 * (x - 1) + 1;
  return 2 * (-x - 1);
}

int deg[MAXN];
int forbidden[MAXN];
int value[MAXN];
int ok[MAXN][MAXN];
long long ans;
int n, m;

void set(int id, int val) {
  assert(value[id] == -1);
  value[id] = val;
  forbidden[2*id + 1 - val]++;
  for (int x : g[id]) {
    deg[x]--;
  }
  for (int x : f[id * 2 + val]) {
    forbidden[x]++;
  }
}

void unset(int id) {
  assert(value[id] != -1);
  forbidden[2*id + 1 - value[id]]--;
  for (int x : g[id]) {
    deg[x]++;
  }
  for (int x : f[id * 2 + value[id]]) {
    forbidden[x]--;
  }
  value[id] = -1;
}

long long cycle(int v, vector<int>& used) {
  vector<int> path;
  int i = v;
  int prev = -1;
  while (true) {
    //fprintf(stderr, "i = %d\n", i);
    if (used[i]) {
      assert(i == v);
      break;
    }
    path.push_back(i);
    used[i] = 1;
    int to = -1;
    for (int j : g[i]) {
      if (value[j] == -1 && j != prev) {
        to = j;
        break;
      }
    }
    if (to == -1) {
      break;
    }
    prev = i;
    i = to;
  }

  long long c0, c1;
  long long res = 0;
  for (int i = 0; i < 2; i++) {
    c0 = i ? 0 : 1;
    c1 = i ? 1 : 0;
    for (int j = 1; j < (int)path.size(); j++) {
      long long nc0, nc1;
      nc0 = nc1 = 0;
      if (ok[path[j-1]][path[j]] & 1) nc0 += c0;
      if (ok[path[j-1]][path[j]] & 2) nc0 += c1;
      if (ok[path[j-1]][path[j]] & 4) nc1 += c0;
      if (ok[path[j-1]][path[j]] & 8) nc1 += c1;
      c1 = nc1;
      c0 = nc0;
    }
    //printf("i = %d, path.size() = %d, c0 = " INT64 ", c1 = " INT64 "\n", i, (int)path.size(), c0, c1);
    if (i == 0) {
      if (ok[path[0]][path.back()] & 1) res += c0;
      if (ok[path[0]][path.back()] & 4) res += c1;
    } else {
      if (ok[path[0]][path.back()] & 2) res += c0;
      if (ok[path[0]][path.back()] & 8) res += c1;
    }
  }
  return res;
}

void go() {
  for (int i = 0; i < n; i++) {
    if (forbidden[2*i] && forbidden[2*i+1]) {
      return;
    }
  }
  int maxd = -1;
  for (int i = 0; i < n; i++) {
    if (value[i] != -1) continue;
    if (forbidden[2*i]) {
      set(i, 1);
      go();
      unset(i);
      return;
    }
    if (forbidden[2*i + 1]) {
      set(i, 0);
      go();
      unset(i);
      return;
    }
    if (maxd == -1 || deg[i] > deg[maxd]) {
      maxd = i;
    }
  }
  //printf("maxd = %d\n", maxd);
  if (maxd == -1) {
    ans += 1;
  } else if (deg[maxd] <= 2) {
    long long c = 1;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
      if (value[i] != -1 || used[i]) continue;
      //printf("! i = %d, deg[i] = %d\n", i, deg[i]);
      if (deg[i] == 1) {
        c *= cycle(i, used);
      }
    }
    for (int i = 0; i < n; i++) {
      if (value[i] != -1 || used[i]) continue;
      //printf("!! i = %d, deg[i] = %d\n", i, deg[i]);
      c *= cycle(i, used);
    }
    ans += c;
  } else {
    set(maxd, 0);
    go();
    unset(maxd);
    set(maxd, 1);
    go();
    unset(maxd);
  }
}

int main() {
#ifndef NOFILES
  freopen("c2sat.in", "r", stdin);
  freopen("c2sat.out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ok[i][j] = 0xf;
    }

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = conv(a);
    b = conv(b);
    if (a / 2 != b / 2) {
      f[a ^ 1].push_back(b ^ 1);
      f[b ^ 1].push_back(a ^ 1);
      g[a / 2].push_back(b / 2);
      g[b / 2].push_back(a / 2);
      ok[a/2][b/2] &= 0xf ^ (1 << ((1 - (a & 1)) + 2 * (1 - (b & 1)))); 
      ok[b/2][a/2] &= 0xf ^ (1 << (2 * (1 - (a & 1)) + (1 - (b & 1)))); 
    } else {
      assert(a != b);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    deg[i] = g[i].size();
  }
  memset(value, -1, sizeof(value));
  go();

  printf(INT64 "\n", ans);
  return 0;
}
