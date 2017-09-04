#include <stdlib.h>
#include <string.h>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef pair<int, int> P;
set<P> already;
vector<P> points, ans;
vector<int> vals;
int main(){
  int n, x, y, l, r;
  l = 1080, r = 0;
  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    scanf("%d%d", &x, &y);
    points.push_back(P(x, y));
	vals.push_back(x);
    already.insert(P(x, y));
    l = min(l, x);
    r = max(r, x);
  }
  sort(points.begin(), points.end());
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  
  for(int i = 0;i < n;i++){
    int left = 0, right = vals.size() - 1;
    x = points[i].first;
    y = points[i].second;
    while(true){
      int mid = (left + right) / 2;
      ans.push_back(P(vals[mid], y));
      if(vals[mid] == x)break;
      if(vals[mid] < x)left = mid + 1;
      if(vals[mid] > x)right = mid - 1;
    }		
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size() - n);
  for(int i = 0;i < ans.size();i++){
    if(already.count(ans[i]))continue;
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
