#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string solve(int n) {
  if (n == 1) return "1";
  if (n == 2) return "11";
  if (n % 2 == 1) return solve(n - 1) + "1";
  return "[" + solve(n / 2) + "]";
}

int main() {
  freopen("doubling.in", "r", stdin);
  freopen("doubling.out", "w", stdout);
  int n;
  scanf("%d",&n);
  printf("%s\n", solve(n).c_str());
}
