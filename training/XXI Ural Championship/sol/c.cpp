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

int n, m_min, m_max;
int M[110], C[110];

int B[110];
bool K[20010];

bool check( int cnt )
{
	for (int a=1; a<=n; a++) B[a] = C[a]/cnt;
	memset( K, 0, sizeof( K ) );
	K[0] = true;
	for (int a=1; a<=n; a++) if (B[a])
	{
		int z = B[a], zz = 1;
		while(1)
		{
			for (long long b=m_max-(long long)M[a]*zz; b>=0; b--)
				if (K[b])
					K[b + M[a]*zz] = true;
			z -= zz;
			if (z==0) break;
			zz *= 2;
			if (zz > z) zz = z;
		}
	}

	for (int a=m_min; a<=m_max; a++)
		if (K[a])
			return true;

	return false;
}

void sol()
{
	int mi = 0, ma = 10000000;
	while (mi+1 < ma)
	{
		int sr = (mi+ma)/2;
		if (check( sr )) mi = sr;
		else ma = sr;
	}
	cout << mi;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> m_min >> m_max;
	for (int a=1; a<=n; a++) cin >> M[a] >> C[a];

	sol();

	return 0;
}
