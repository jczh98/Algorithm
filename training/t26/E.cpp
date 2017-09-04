#include <bits/stdc++.h>
using namespace std;
struct Node {
    int t, k, id;
    deque<int> room;
}people[1005];
int cmp(Node a, Node b) {
    if(a.t == b.t) return a.id < b.id;
    else return a.t < b.t;
}
queue<int> rooms[1005];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &people[i].t, &people[i].k);
        people[i].id = i;
        for(int j = 1; j <= people[i].k; j++) {
            int x;
            scanf("%d", &x);
            people[i].room.push_back(x);
        }
    }
    sort(people + 1, people + 1 + n, cmp);
    int ans = people[1].t;
    for(int i = 1; i <= n; i++) {

    }
}

