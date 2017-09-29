#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second < a.second * b.first;
}

int main() {
  freopen("cut-potatoes.in", "r", stdin);
  freopen("cut-potatoes.out", "w", stdout);

  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  pair<int, int> ans = make_pair(1, 0);
  vector<int> ansv;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      int bad = 0;
      pair<int, int> size = make_pair(a[i], j);
      pair<int, int> maxv = size;
      vector<int> parts(n);
      for (int t = 0; t < n; t++) {
        // a[t] * j / den >= a[i]
        int den = (a[t] * j) / a[i];
        den = min(den, k);
        parts[t] = den;
        pair<int, int> cur = make_pair(a[t], den);
        if (cmp(cur, size)) {
          bad = 1;
          assert(den == 1);
        }
        maxv = max(maxv, cur, cmp);
      }
      if (bad) {
        continue;
      }
      maxv.first *= size.second;
      maxv.second *= size.first;
      //fprintf(stderr, "%d %d: %d %d\n", i, j, maxv.first, maxv.second);
      if (!ansv.size() || cmp(maxv, ans)) {
        ans = maxv;
        ansv = parts;
      }
    }
  }

  assert((int)ansv.size() == n);

  for (int i = 0; i < n; i++) {
    printf("%d%c", ansv[i], " \n"[i==n-1]);
  }
}
