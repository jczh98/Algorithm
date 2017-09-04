#include <bits/stdc++.h>
using namespace std;
int m, n;
struct Node {
    int indeg, id;
    bool operator < (const Node & rhs) const{
        return indeg > rhs.indeg || (indeg == rhs.indeg && id < rhs.id);
    }
}cock[20][100005];
char place[100005];
map<string, int> mp;
map<int, string> re_mp;
int u, v, cnt_place = 1;
int main() {
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%s", &u, &v, place);
        if(!mp[place]) {
            re_mp[cnt_place] = place;
            mp[place] = cnt_place++;
        }
        cock[mp[place]][v].indeg++;
        cock[mp[place]][v].id = v;
    }
    for(int i = 1; i < cnt_place; i++) {
        sort(cock[i] + 1, cock[i] + 1 + n);
        cout << re_mp[i] << " " << cock[i][1].id << endl;
    }
    return 0;
}