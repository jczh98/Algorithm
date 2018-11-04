#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, lev;
bool vis[2005][2005];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
struct node {
    int x, y, z;
    node(int x, int y, int z): x(x), y(y), z(z){}
};
pair<int,int> ans[2005];
queue<node> que;
int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &k);
        for(int i = 0; i <= 2000; ++i) {
            ans[i].first = INT_MAX; ans[i].second = INT_MAX;
        }
        for(int i = 1; i <= k; ++i) {
            scanf("%d%d", &x, &y);
            vis[x][y] = 1;
            //ans[0].push_back(make_pair(x, y));
            if(ans[0].first > x) {
                ans[0].first = x; ans[0].second = y;
            } else if(ans[0].first == x && ans[0].second > y) {
                ans[0].second = y;
            }
            que.push(node(x,y,0));
        }
        lev = 0;
        while(!que.empty()) {
            node cur = que.front();
            int cx = cur.x, cy = cur.y, cz = cur.z; que.pop();
            lev = cz;
            for(int i = 0; i < 4; ++i) {
                int nx = cx+dx[i], ny = cy+dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(!vis[nx][ny]) {
                    //ans[cz+1].push_back(make_pair(nx, ny));
                    if(ans[cz+1].first > nx) {
                        ans[cz+1].first = nx; ans[cz+1].second = ny;
                    } else if(ans[cz+1].first == nx && ans[cz+1].second > ny) {
                        ans[cz+1].second = ny;
                    }
                    que.push(node(nx, ny, cz+1));
                    vis[nx][ny] = 1;
                }
            }
        }
        // for(int i = 0; i < ans[lev].size(); ++i) {
        //     printf("%d %d\n", ans[lev][i].first, ans[lev][i].second);
        // }
        //sort(ans[lev].begin(), ans[lev].end());
        printf("%d %d\n", ans[lev].first, ans[lev].second);
        //for(int i = 0; i <= lev; ++i) ans[i].clear();
    }
    return 0;
}