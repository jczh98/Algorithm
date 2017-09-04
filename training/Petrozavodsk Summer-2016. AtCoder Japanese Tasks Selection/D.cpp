#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef pair<int, int> pii;
pii point[MAXN];
int n, mp[2000][2000], ans[2000][2000];
vector<pii > vec;
void Solve(int L, int R) {
    if(L > R) return ;
    int mid = (L + R) / 2;
    for(int i = L; i <= R; i++) {
        ans[point[mid].first][point[i].second] = 1;
    }
    Solve(L, mid - 1);
    Solve(mid + 1, R);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &point[i].first, &point[i].second);
        mp[point[i].first][point[i].second] = 1;
    }
    sort(point + 1, point + 1 + n);
    Solve(1, n);
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(ans[i][j] != mp[i][j]) {
                vec.push_back(make_pair(i, j));
            }
        }
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++) {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
    return 0;
}