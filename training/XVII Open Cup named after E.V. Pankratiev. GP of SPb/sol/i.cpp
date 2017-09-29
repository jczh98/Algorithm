#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

typedef unsigned int uint;

uint state;

void setSeed(uint seed) {
    state = seed;
}

uint random(uint range) {
    state = state * 1664525 + 1013904223;
    return 1ll * state * range / (1ll << 32);
}

const int BUBEN = 60005;
const int N = 10000;
const int M = 2 * N + 10;
uint S;
int a[N];
int pos[N];
int moves[N];
uint A[M], B[M];
uint AA[M];

void shuffle(int *a) {
    for (int i = 0; i < N; ++i) {
        int j = random(i + 1);
        swap(a[i], a[j]);
        ++moves[a[i]];
        ++moves[a[j]];
    }
}

uint bin(uint x, ll to) {
    uint y = 1;
    while (to) {
        if (to & 1)
            y = x * y;
        x = x * x;
        to >>= 1;
    }
    return y;
}

void pre() {
    uint a = 1664525; 
    uint ia = bin(a, (1ll << 31) - 1);
    assert(a * ia == 1);
    uint b = 1013904223;

    A[0] = 1, B[0] = 0;
    AA[0] = 1;
    for (int i = 1; i < M; ++i) {
        AA[i] = a * AA[i - 1];
        A[i] = ia * A[i - 1];
        B[i] = a * B[i - 1] + b;
    }
}

void read() {
#ifdef LOCAL
    cin >> S;
    setSeed(S);
    iota(a, a + N, 0);
    shuffle(a);
    shuffle(a);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << "...\n";
#else
    int x;
    cin >> x;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        --a[i];
    }
#endif
    for (int i = 0; i < N; ++i)
        pos[a[i]] = i;
}

pair<uint, uint> build(int n, int k, int res) { //on nth step random(k) = res
    assert(n > 0);
    assert(0 <= res && res < k);
    ll pw = 1ll << 32;
    uint l = (pw * res + k - 1) / k;
    uint r = (pw * (res + 1) - 1) / k;
    return make_pair(l, r);
}

int b[N];

int inserts;

void checkSeed(uint s) {
    setSeed(s);
    iota(b, b + N, 0);
    shuffle(b);
    shuffle(b);
    if (equal(a, a + N, b)) {
        shuffle(b);
        for (int i = 0; i < N; ++i)
            cout << b[i] + 1 << " ";
        cout << endl;
        cerr << "seed = " << s << endl;
        int time = clock() / 1000;
        cerr << "time = " << time << "\n";
        cerr << "inserts = " << inserts << "\n";
        //assert(time <= 2500);
        exit(0);
    }
}

namespace HT {
const int SZ = 1 << 24;
uint val[SZ + 10000];

void ins(uint x) {
    ++inserts;
    uint h = (x ^ 918493 ^ (x << 5) ^ (x >> 21)) & (SZ - 1);
    while (val[h] != 0 && val[h] != x)
        ++h;
    if (val[h] == x)
        checkSeed(x);
    val[h] = x;
}

};

void intersect(uint kl, uint kr, uint a, uint b, uint L, uint R, uint sb, uint sa) {
    b += kl * a;
    kr -= kl;
    sb += kl;
    kl = 0;

    uint block = sqrt(kr) / 2;
    while (kr % block != 0) {
        uint y = b;
        if (L <= y && y <= R)
            HT::ins(sa * sb);
        b += a;
        --kr;
        ++sb;
    }
    typedef pair<uint, uint> puu;
    vector<puu> sega;
    for (uint x = 0; x < block; ++x) {
        uint pos = R - x * a;
        sega.emplace_back(pos, x);
    }
    sort(sega.begin(), sega.end());
    for (uint X = 0; X < kr / block; ++X) {
        uint y = (X * block) * a + b;
        for (auto it = lower_bound(sega.begin(), sega.end(), puu{y, 0u});
                it != sega.end() && (it->first - y) <= (R - L); ++it) {
            HT::ins(sa * (X * block + it->second + sb));
        }
    }
}

void check(int x) {
    //cerr << "x = " << x << endl;
    int pos = ::pos[x];
    for (int i = pos; i < x; ++i) {
        //x -> i -> pos
        //first step: x + 1
        //second step: N + (i + 1)


        auto F = build(x + 1, x + 1, i);
        auto S = build(N + (i + 1), i + 1, pos);

        int fn = x + 1, sn = N + (i + 1);

        uint a = A[fn], b = -B[fn] * A[fn];
        a = a * AA[sn]; b = B[sn] + AA[sn] * b;
        intersect(F.first, F.second + 1, a, b, S.first, S.second, -B[fn], A[fn]);

        //for (uint k = F.first; k <= F.second; ++k) {
            //uint y = a * k + b;
            //if (S.first <= y && y <= S.second) {
                //uint x = (k - B[fn]) * A[fn];
                //if ((m[x]++) == 2) {
                    //checkSeed(x);
                //}
            //}
        //}
    }
}

void kill() {
    for (int i = N - 1; i >= 0; --i)
        if (i >= pos[i] && i - pos[i] <= BUBEN)
            check(i);
    return;
}

int main() {
    #ifdef LOCAL
    assert(freopen("i.in", "r", stdin));
    #else
    #endif

    pre();
    read();
    kill();
    return 0;
}
