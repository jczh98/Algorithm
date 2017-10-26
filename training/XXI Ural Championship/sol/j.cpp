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

using namespace std;

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int n, m, s;
int A[100], B[100], C[100], D[100];
map< char, int > Map;
char T[2010][2010];

int INF = 1000000000;

int get_dist_x( int i, int j, int t )
{
	if (T[i][j]=='.') return INF;
	int tp = Map[T[i][j]];
	return (A[tp]*t + B[tp])%C[tp] + D[tp];
}

/*int get_dist( int i, int j, int t )
{
	if (T[i][j]=='.') return INF;
	// stupid
	int re = INF;
	int tp = Map[T[i][j]];
	for (int a=0; a<=4000; a++)
	{
		int dist = a + (A[tp]*(t+a) + B[tp])%C[tp] + D[tp];
		re = min( re, dist );
	}
	return re;
}*/

int raw_dist[60][10010];
int lifted_dist[60][10010];
int min_dist[60][10010];

int get_dist( int i, int j, int t )
{
	if (T[i][j]=='.') return INF;
	int tp = Map[T[i][j]];
	t %= C[tp];
	return min_dist[tp][t];
}

int S[2010];
bool F[2010];

void sol()
{
	for (int a=1; a<=m; a++)
		for (int b=0; b<=10000; b++)
		{
			raw_dist[a][b] = (A[a]*b + B[a])%C[a] + D[a];
			lifted_dist[a][b] = raw_dist[a][b] + b;
		}
	for (int a=1; a<=m; a++)
	{
		min_dist[a][10000] = lifted_dist[a][10000];
		for (int b=9999; b>=0; b--)
			min_dist[a][b] = min( lifted_dist[a][b], min_dist[a][b+1] );
	}
	for (int a=1; a<=m; a++)
		for (int b=0; b<=10000; b++)
			min_dist[a][b] -= b;


	// dijkstra
	for (int a=1; a<=n; a++)
		S[a] = INF;
	S[1] = s;
	while(1)
	{
		int ind = -1;
		for (int a=1; a<=n; a++)
			if (!F[a] && S[a]<INF && (ind==-1 || S[a]<S[ind]))
				ind = a;
		if (ind==-1) break;

		F[ind] = true;
		for (int a=1; a<=n; a++)
			if (!F[a])
			{
				int dist = get_dist( ind, a, S[ind] );
				S[a] = min( S[a], S[ind] + dist );
			}
	}
	//ass( S[n]<INF );

	/*for (int a=0; a<=10; a++)
		cout << get_dist_x( 1, 2, a ) << " ";
	cout << "\n";
	for (int a=0; a<=10; a++)
		cout << get_dist( 1, 2, a ) << " ";
	cout << "\n\n";

	for (int a=0; a<=10; a++)
		cout << get_dist_x( 2, 3, a ) << " ";
	cout << "\n";
	for (int a=0; a<=10; a++)
		cout << get_dist( 2, 3, a ) << " ";
	cout << "\n\n";

	for (int a=1; a<=n; a++)
		cout << S[a] << " ";
	cout << "\n";*/

	if ( S[n]==INF ) cout << -1 << "\n";
	else cout << S[n]-s << "\n";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> m >> s;
	for (int a=1; a<=m; a++)
	{
		char ch;
		cin >> ch >> A[a] >> B[a] >> C[a] >> D[a];
		Map[ch] = a;
	}
	for (int a=1; a<=n; a++)
		scanf( "%s", &T[a][1] );

	sol();
	
	return 0;
}
