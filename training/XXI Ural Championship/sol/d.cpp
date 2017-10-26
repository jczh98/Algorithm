#include <string.h>
#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

struct DP
{
        int sz;
        int be[5];
        int en[5];
        DP()
        {
                sz = 0;
        }
};

DP dp[1010];
bool T[1010][2010];

int mx_sz = 0;

int v[100];

DP merge_vp( const DP & vp1, const DP & vp2 )
{
        int v_sz = 0;
        for (int a=0; a<vp1.sz; a++)
        {
                v[v_sz++] = vp1.be[a]*2;
                v[v_sz++] = (vp1.en[a]+1)*2 + 1;
        }
        for (int a=0; a<vp2.sz; a++)
        {
                v[v_sz++] = vp2.be[a]*2;
                v[v_sz++] = (vp2.en[a]+1)*2 + 1;
        }
        sort( v, v+v_sz );

        DP re;
        int d = 0, be;
        for (int a=0; a<(int)v_sz; a++)
        {
                if (d==0 && (v[a]&1)==0) be = (v[a]>>1);
                if ((v[a]&1)==0) d++;
                else d--;
                if (d==0 && (v[a]&1)==1)
                {
                                assert(re.sz <= 4);
                        re.be[re.sz] = be;
                        re.en[re.sz] = (v[a]>>1)-1;
                        re.sz++;
                }
        }
        mx_sz = max( mx_sz, re.sz );

        return re;
}

DP shift_vp( DP vp, int delta )
{
        for (int a=0; a<vp.sz; a++)
        {
                vp.be[a] += delta;
                vp.en[a] += delta;
        }
        return vp;
}

void init()
{
        dp[0].be[0] = 0;
        dp[0].en[0] = 0;
        dp[0].sz++;
        T[0][0] = true;

        for (int z=1; z<=1000; z++)
        {
                for (int d=1; d<=z; d++)
                        for (int a=1; a*a<=d; a++)
                                if (d%a==0)
                                        dp[z] = merge_vp( dp[z], shift_vp( dp[z-d], a + d/a ) );
                for (int a=0; a<dp[z].sz; a++)
                        for (int b=dp[z].be[a]; b<=dp[z].en[a]; b++)
                                T[z][b] = true;
        }

        /*cout << mx_sz << "\n";

        for (int a=0; a<=1000; a++)
        {
                printf( "%4d ", a );
                for (int b=0; b<=500; b++)
                        printf( "%c", T[a][b] ? '#' : '.' );
                printf( "\n" );
        }*/
}

int n, m;

int ans1[2000], ans2[2000];
int ans_sz;

void sol()
{
        if (m%2==1 || m > n*4 || !T[n][m/2])
        {
                cout << "No\n";
                return;
        }
        m/=2;

        ans_sz = 0;
        while(n>0)
        {
                for (int a=1; a<=n; a++)
                {
                        bool flag = false;
                        for (int b=1; b*b<=a; b++)
                                if (a%b==0)
                                {
                                        int p = b + a/b;
                                        if (p<=m)
                                                if (T[n-a][m-p])
                                                {
                                                        ans1[ans_sz] = b;
                                                        ans2[ans_sz] = a/b;
                                                        ans_sz++;
                                                        n-=a;
                                                        m-=p;
                                                        flag = true;
                                                        break;
                                                }
                                }
                        if (flag) break;
                }
        }

        cout << "Yes\n";
        cout << ans_sz << "\n";
        for (int a=0; a<ans_sz; a++)
                printf( "%d %d\n", ans1[a], ans2[a] );
}

int main()
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        init();

        //cerr << clock() << "\n";

        int T;
        cin >> T;

        for (int a=1; a<=T; a++)
        {
                cin >> n >> m;
                sol();
        }

        return 0;
}