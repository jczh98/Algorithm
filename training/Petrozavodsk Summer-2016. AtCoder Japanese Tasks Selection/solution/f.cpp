#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;

int n;
string s[405];
bool used[405][405];
int dh[405][405];
int dv[405][405];

int main() {
  cin >> n;
  rep(i,n) cin >> s[i];
  string ans = "IMPOSSIBLE";
  int tot = 0;
  rep(i,n)rep(j,n) if (s[i][j] == '.') tot++;
  int si = 0, sj = 0;
  rep(i,n)rep(j,n) if (s[i][j] == 's') si = i, sj = j;
  rep(ti,2) {
    int dir = 0, p = 0;
    rep(i,n) {
      int c = 0;
      rep(j,n) if (s[i][j] == '.') c++;
      if (c&1) dir = 0, p = i;
    }
    rep(i,n) {
      int c = 0;
      rep(j,n) if (s[j][i] != '#') c++;
      if (c&1) dir = 1, p = i;
    }
    rep(ni,n) {
      int x, y;
      if (dir == 0) { // vertical
        x = p; y = ni;
      } else { // horizontal
        x = ni; y = p;
      }
      if (s[x][y] != '.') continue;
      s[x][y] = 'g';
      bool ok = true;
      rep(i,n) {
        int f = 1;
        rep(j,n) {
          if (s[i][j] == '#') continue;
          if (s[i][j] == 's') continue;
          if (s[i][j] == 'g' && dir == 0) continue;
          dh[i][j] = f;
          f *= -1;
        }
        if (f != 1) ok = false;
      }
      rep(i,n) {
        int f = 1;
        rep(j,n) {
          if (s[j][i] == '#') continue;
          if (s[j][i] == 'g' && dir == 1) continue;
          dv[j][i] = f;
          f *= -1;
        }
        if (f != 1) ok = false;
      }
      rep(i,n)rep(j,n) used[i][j] = false;
      if (ok) {
        int cnt = 0;
        int i = si, j = sj, v = 0;
        while (!used[i][j] && s[i][j] != 'g') {
          if (s[i][j] == '#') { ok = false; break;}
          used[i][j] = true;
          cnt++;
          if (v == 0) {
            i += dv[i][j];
          } else {
            j += dh[i][j];
          }
          v ^= 1;
        }
        if (s[i][j] != 'g') ok = false;
        if (cnt != tot) ok = false;
        if (ok) ans = "POSSIBLE";
      }
      s[x][y] = '.';
    }
    rep(i,n)rep(j,i) swap(s[i][j], s[j][i]);
    swap(si,sj);
  }
  cout<<ans<<endl;
  return 0;
}
