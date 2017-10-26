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


int n;
char T[20][20];

long long dp[15][1600000];
int pos[15][15], sz[15];
int pow3[15];
int mask2[15], mask3[15];
int bin[1600000];
int sum[1600000];
int cnt[15];

int akt_sum[15];

void sol()
{
	pow3[0] = 1;
	for (int a=1; a<=n; a++)
		pow3[a] = pow3[a-1]*3;

	for (int a=1; a<=n; a++)
		for (int b=1; b<=n; b++)
			if (T[a][b]=='.')
			{
				pos[a][sz[a]++] = b-1;
				mask3[a] += pow3[b-1];
				mask2[a] += (1<<(b-1));
			}
	int end_mask = 0;
	for (int a=1; a<=n; a++)
	{
		if (T[a][0]!='#') cnt[a]++;
		if (T[a][n+1]!='#') cnt[a]++;
		if (T[0][a]!='#') end_mask += pow3[a-1];
		if (T[n+1][a]!='#') end_mask += pow3[a-1];
	}
	for (int a=1; a<=n; a++)
		akt_sum[a] = akt_sum[a-1] + sz[a] - cnt[a];

	int Z = pow3[n];
	for (int a=0; a<Z; a++)
	{
		int z = a;
		for (int b=0; b<n; b++)
		{
			int tmp = z%3;
			if (tmp>0) bin[a] += (1<<b);
			sum[a] += tmp;
			z/=3;
		}
	}

	dp[0][0] = 1;
	for (int a=1; a<=n; a++)
		for (int b=0; b<Z; b++)
			if (sum[b] == akt_sum[a])
			{
				if (cnt[a]==2)
				{
					for (int i=0; i<sz[a]; i++)
						for (int j=i+1; j<sz[a]; j++)
						{
							int m2 = mask2[a] - (1<<pos[a][i]) - (1<<pos[a][j]);
							if ((bin[b] & m2)==m2)
							{
								int m3 = mask3[a] - pow3[pos[a][i]] - pow3[pos[a][j]];
								dp[a][b] += dp[a-1][b-m3];
							}
						}
				}
				else if (cnt[a]==1)
				{
					for (int i=0; i<sz[a]; i++)
					{
						int m2 = mask2[a] - (1<<pos[a][i]);
						if ((bin[b] & m2)==m2)
						{
							int m3 = mask3[a] - pow3[pos[a][i]];
							dp[a][b] += dp[a-1][b-m3];
						}
					}
				}
			}

	long long mult = 1;
	for (int a=1; a<=n; a++)
	{
		if (T[0][a]!='#' && T[n+1][a]!='#' && T[0][a]!=T[n+1][a]) mult *= 2;
		if (T[a][0]!='#' && T[a][n+1]!='#' && T[a][0]!=T[a][n+1]) mult *= 2;
	}

	cout << dp[n][end_mask]*mult << "\n";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf( "%d", &n );
	for (int a=0; a<n+2; a++)
		scanf( "%s", T[a] );

	sol();

	return 0;
}
