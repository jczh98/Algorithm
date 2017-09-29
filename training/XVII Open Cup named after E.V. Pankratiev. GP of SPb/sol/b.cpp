#include <stdlib.h>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXCOST = 100000;
const int MAXN = 100;

int dp[MAXN + 1][MAXCOST / 100 * MAXN + 1];
int p[MAXN];

void restore(int n, int bonuses) {
  if (!n) {
    assert(!bonuses);
    return;
  }
  int cost = p[n-1];
  if (bonuses >= cost / 100 && dp[n - 1][bonuses - cost / 100] + cost == dp[n][bonuses]) {
    restore(n - 1, bonuses - cost / 100);
    printf("%d + %d\n", cost, 0);
    return;
  }
  for (int b = 0; ; b++) {
    assert(bonuses + b <= MAXCOST && b <= cost);
    if (dp[n - 1][bonuses + b] + cost - b == dp[n][bonuses]) {
      restore(n - 1, bonuses + b);
      printf("%d + %d\n", cost - b, b);
      return;
    }
  }
}

int main() {
  freopen("bonuses.in", "r", stdin);
  freopen("bonuses.out", "w", stdout);

  int n;
  scanf("%d", &n);

  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  

  int totmax = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    for (int j = 0; j <= totmax; j++) {
      dp[i+1][j + p[i] / 100] = min(dp[i+1][j + p[i] / 100], dp[i][j] + p[i]);
      int maxb = min(p[i], j);
      dp[i+1][j - maxb] = min(dp[i+1][j - maxb], dp[i][j] + p[i] - maxb);
    }
    totmax += p[i] / 100;
  }
  
  int best = 0;
  for (int i = 0; i <= totmax; i++) 
    if (dp[n][i] < dp[n][best]) {
      best = i;
    }

  printf("%d\n", dp[n][best]);
  restore(n, best);
  return 0;
}
