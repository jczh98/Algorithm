#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 1100
using namespace std;
const unsigned int BASE1 = 10016957;
const unsigned int BASE2 = 10016957;
const int MO = 99999997;
 
int m,n,ask_m,ask_n,asks;
unsigned int Hash[MAX][MAX],_hash[MAX][MAX];
unsigned int pow1[MAX],pow2[MAX];
 
bool set[100000000];
 
inline unsigned int GetHash()
{
    for(int i = 1; i <= ask_m; ++i)
        for(int j = 1; j <= ask_n; ++j)
            _hash[i][j] += _hash[i - 1][j] * BASE1;
    for(int i = 1; i <= ask_m; ++i)
        for(int j = 1; j <= ask_n; ++j)
            _hash[i][j] += _hash[i][j - 1] * BASE2;
    return _hash[ask_m][ask_n];
}
 
int main()
{
    cin >> m >> n ;//>> ask_m >> ask_n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%1d",&Hash[i][j]);
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i <= 100; ++i)
        pow1[i] = pow1[i - 1] * BASE1,pow2[i] = pow2[i - 1] * BASE2;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            Hash[i][j] += Hash[i - 1][j] * BASE1;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            Hash[i][j] += Hash[i][j - 1] * BASE2;
    cout << Hash[m][n] << endl;
    // int q;
    // scanf("%d", &q);
    // while(q--) {
    //     int l1, r1, l2, r2, l3, r3, l4, r4;
    //     cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3 >> l4 >> r4;
    //     l1++;l2++;l3++;l4++;r1++;r2++;r3++;r4++;
    //     unsigned int h = Hash[l2][r2], hh = Hash[l4][r4];
    //     h-=Hash[l2-l1][r2]*pow1[l1];
    //     h-=Hash[l2][r2-r1]*pow2[r1];
    //     h+=Hash[l2-l1][r2-r1]*pow1[l1]*pow2[r1];

    //     hh-=Hash[l4-l3][r4]*pow1[l3];
    //     hh-=Hash[l4][r4-r3]*pow2[r3];
    //     hh+=Hash[l4-l3][r4-r3]*pow1[l3]*pow2[r3];
    //     cout << h <<  Hash[l2][r2] << endl;
    // }
    // for(int i = ask_m; i <= m; ++i)
    //     for(int j = ask_n; j <= n; ++j) {
    //         unsigned int h = Hash[i][j];
    //         h -= Hash[i - ask_m][j] * pow1[ask_m];
    //         h -= Hash[i][j - ask_n] * pow2[ask_n];
    //         h += Hash[i - ask_m][j - ask_n] * pow1[ask_m] * pow2[ask_n];
    //         set[h % MO] = true;
    //     }
    // for(cin >> asks; asks--;) {
    //     for(int i = 1; i <= ask_m; ++i)
    //         for(int j = 1; j <= ask_n; ++j)
    //             scanf("%1d",&_hash[i][j]);
    //     puts(set[GetHash() % MO] ? "1":"0");
    // }
    return 0;
}