#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#ifdef LOCAL
#define LLD "%lld"
#else
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#endif

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "arrayfactory"

void precalc() {
}

const int maxn = (int) 2e5 + 10;
const ll inf = (ll) 1.01e18;

struct tree {
  ll x[4 * maxn];
  int n;

  void init(int _n, ll *a) {
    for (n = 1; n < _n; n <<= 1);
    for (int i = 0; i < n; ++i) {
      x[n + i] = (i < _n ? a[i] : inf);
    }
    for (int i = n - 1; i > 0; --i) {
      x[i] = min(x[2 * i], x[2 * i + 1]);
    }
  }

  int findr(int v, int L, int R, int l, ll s) {
    if (l >= R || x[v] > s) {
      return -1;
    }
    if (R - L == 1) {
      return L;
    }
    int M = (L + R) / 2;
    if (x[2 * v + 1] <= s) {
      return findr(2 * v + 1, M, R, l, s);
    }
    return findr(2 * v, L, M, l, s);
  }

  int findr(int l, ll s) {
    return findr(1, 0, n, l, s);
  }
} t;

int n;
ll s;
int a[maxn];
ll p[maxn];

bool read() {
  if (scanf("%d" LLD, &n, &s) < 2) {
    return false;
  }
  p[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    p[i + 1] = p[i] + a[i];
  }
  return true;
}

void solve() {
  t.init(n + 1, p);

  int len = -1, al = -1, ar = -1;

  for (int l = 0; l < n; ++l) {
    int r = t.findr(l + 1, s + p[l]);
    if (r != -1 && (len == -1 || r - l > len)) {
      assert(p[r] - p[l] <= s);
      len = r - l;
      al = l, ar = r;
    }
  }

  if (len == -1) {
    printf("-1\n");
    return;
  }

  printf("%d\n%d %d\n", len, al, n - ar);
}

int main() {
  srand(rdtsc());
  precalc();
  assert(freopen(TASK".out", "w", stdout));
  assert(freopen(TASK".in", "r", stdin));

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}


