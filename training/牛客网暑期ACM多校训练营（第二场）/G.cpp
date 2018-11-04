#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int lch[N << 2], rch[N << 2], w[N << 2], ww[N << 2], a[N];
void push_up(int x) {
    w[x] = w[x << 1] + w[x << 1 | 1];
    ww[x] = 
}
void build(int x, int l, int r) {
    lch[x] = l; rch[x] = r;
    if(l == r) {
        w[x] = a[l]; return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
}
int query(int x, int l, int r) {

}
int main() {

}