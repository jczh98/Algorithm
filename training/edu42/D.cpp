#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node {
    LL val, pos;
    friend bool operator>(const node& n1, const node& n2) {
        if (n1.val == n2.val) return n1.pos > n2.pos;
        else return n1.val > n2.val;
    }
    friend bool operator<(const node& n1, const node& n2) {
        if(n1.val == n2.val) return n1.pos < n2.pos;
        else return n1.val < n2.val;
    }
    friend bool operator==(const node& n1, const node& n2) {
        return n1.pos == n2.pos && n1.val == n2.val;
    }
    friend bool operator!=(const node& n1, const node& n2) {
        return n1.pos != n2.pos || n1.val != n2.val;
    }
};
bool cmp(node n1, node n2) { return n1.pos < n2.pos; }
priority_queue<node, vector<node>, greater<node> > pq2;
node imp;
node a[150005], ans[150005];
int ans_count = 0, n;
int main() {
    imp.pos = -1;
    imp.val = -1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].val;
        a[i].pos = i;
        pq2.push(a[i]);
    }
    node last = imp;
    node new_;
    while (!pq2.empty()) {
        node tmp = pq2.top(); pq2.pop();
        bool flag = false;
        if (last != imp) {
            if (last.val == tmp.val) {
                new_.pos = tmp.pos;
                new_.val = tmp.val * 2;
                pq2.push(new_);
                flag = true;
                last = imp;
            } else {
                ans[ans_count++] = last;
            }
        }
        if (!flag) {
            last = tmp;
        }
    }
    ans[ans_count++] = last;
    sort(ans, ans + ans_count, cmp);
    cout << ans_count << endl;
    for (int i = 0; i < ans_count; ++i) {
        cout << ans[i].val;
        if(i == ans_count - 1) printf("\n"); else printf(" ");
    }
    return 0;
}
