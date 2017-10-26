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

int k[2], b[2], s[2];
int h[2][10010];

int ind[2][100000];

void sol()
{
	for (int z=0; z<2; z++)
		for (int i=1; i<=k[z]; i++)
			for (int j=b[z]+(i-1)*s[z]; j<b[z]+i*s[z]; j++)
				ind[z][j] = i;
	for (int a=0; a<100000; a++)
		while (h[0][ind[0][a]]>0 && h[1][ind[1][a]]>0)
		{
			h[0][ind[0][a]]--;
			h[1][ind[1][a]]--;
		}
	for (int z=0; z<2; z++)
		for (int i=1; i<=k[z]; i++)
			if (h[z][i]>0)
			{
				cout << "No";
				return;
			}
	cout << "Yes";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	for (int z=0; z<2; z++)
	{
		cin >> k[z] >> b[z] >> s[z];
		for (int a=1; a<=k[z]; a++)
			cin >> h[z][a];
	}

	sol();
	
	return 0;
}
