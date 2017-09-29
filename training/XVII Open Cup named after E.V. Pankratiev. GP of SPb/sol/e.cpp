#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
typedef pair<int, int> pnt;
vector<ll> dp;
pnt operator - (pnt a, pnt b) {
  return pnt(a.x - b.x, a.y - b.y);
}
ll vp(pnt a, pnt b) {
  return a.x * b.y - a.y * b.x;
} 
void getkth(vector<pnt> p, ll k) {
  if (sz(p) == 0) return;
  vector<int> ls;  
  for (int i = 0; i < sz(p); i++) {
    ls.pb(i);
  }
  sort(all(ls), [p](int i, int j) { return p[i] < p[j];});
  for (int i = 0; i < sz(ls); i++) {
    for (int j = i + 1; j < sz(ls); j++) {
      int h = abs(ls[i] - ls[j]) - 1;
      if (h % 2 != 0) continue;
      ll x = dp[h] * dp[sz(p) - h - 2];
      if (k < x) {
        cout << p[ls[i]].x << " " << p[ls[i]].y << endl;
        cout << p[ls[j]].x << " " << p[ls[j]].y << endl;
        vector<pnt> lft;
        vector<pnt> rgt;
        for (int t = 0; t < sz(p); t++) if (t != ls[i] && t != ls[j]) {
          if (vp(p[ls[j]] - p[ls[i]], p[t] - p[ls[i]]) > 0) {
            lft.pb(p[t]);
          } else {
            rgt.pb(p[t]);
          }
        }
        assert(h == sz(lft) || h == sz(rgt));
        getkth(lft, k / dp[sz(rgt)]);
        getkth(rgt, k % dp[sz(rgt)]);
        return;
      } else {
        k -= x;
      }
    }
  }
}
int main(){
#ifndef NOFILES
//  assert(freopen("a.out","wt",stdout));
//  assert(freopen("a.in","rt",stdin));
#endif                
  int n;
  cin >> n;
  vector<pnt> p(n);  
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  dp.resize(n + 1);
  dp[0] = 1;
  for (int i = 2; i <= n; i += 2) {
    for (int i1 = 0; i1 < i; i1++) {
      for (int i2 = i1 + 1; i2 < i; i2 += 2) {
        dp[i] += dp[i2 - i1 - 1] * dp[i - (i2 - i1 + 1)];
      }
    }
  }
  ll k;
  cin >> k;
  getkth(p, k);  
  return 0;
}
