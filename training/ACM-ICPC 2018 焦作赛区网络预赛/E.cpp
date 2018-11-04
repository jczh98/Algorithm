#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 10000;
ull sum[N<<2], mul[N<<2], add[N<<2], inv[N<<2];
inline void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
inline void pushdown(int rt, int l, int r) {
    if(mul[rt] == 1 && add[rt] == 0) return;
    int mid = (l+r)>>1, len = r-l+1;

    sum[rt] = sum[rt<<1] * mul[rt];
    sum[rt] = sum[rt<<1|1] * mul[rt];
    sum[rt << 1] = sum[rt<<1] + add[rt]*(mid-l+1);
    sum[rt<<1|1] = sum[rt<<1|1] + add[rt]*(r-mid);
    if(inv[rt]) {
        sum[rt<<1] = ~sum[rt<<1];
        sum[rt<<1|1] = ~sum[rt<<1|1];        
    }

    mul[rt<<1] = mul[rt]*mul[rt<<1];
    mul[rt<<1|1] = mul[rt]*mul[rt<<1|1];
    add[rt<<1] = add[rt<<1]*mul[rt] + add[rt];
    add[rt<<1|1] = add[rt<<1|1]*mul[rt] + add[rt];
    if(inv[rt]) {
        inv[rt<<1] ^= 1;
        inv[rt<<1|1] ^= 1;        
    }

    inv[rt] = 0;
    add[rt] = 0;
    mul[rt] = 1;
}
void update(int rt, int l, int r, int ql, int qr, int op, int qv) {
    if(ql <= l && r <= qr) {
        if(op == 1) {
            add[rt] = add[rt] * qv;
            mul[rt] = mul[rt] * qv;
            sum[rt] = sum[rt] * qv;
        }else if(op == 2) {
            add[rt] += qv;
            sum[rt] = sum[rt] + (r-l+1)*qv;
        }else if(op == 3) {
            inv[rt] ^= 1;
            sum[rt] = ~sum[rt];
        }
        return;
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, op, qv);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql ,qr, op, qv);
    pushup(rt);
    return;
}
ull query(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return sum[rt];
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    ull ans = 0;
    if(ql <= mid) ans += query(rt<<1, l, mid, ql, qr);
    if(qr > mid) ans += query(rt<<1|1, mid+1, r, ql ,qr);
    return ans;
}
int n;
int main() {
    n = 4;
    update(1, 1, n, 1, n, 1, 1);
    update(1, 1, n, 1, n, 2, 2);
    update(1, 1, n, 1, n, 3, 1);
    cout << query(1, 1, n, 1, n) << endl;
}