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

#define NN 10000100

int n;
unsigned int seed;

int digit[NN];
int best_up[NN];
int best_down[NN];

int parse( int i, int j, int * out )
{
	int sz = 0;
	if (i < j)
	{
		while (i < j)
		{
			out[sz++] = digit[j];
			j >>= 1;
		}
		reverse( out, out+sz );
	}
	else
	{
		while (j < i)
		{
			out[sz++] = digit[i];
			i >>= 1;
		}
	}
	return sz;
}

bool le( int * num1, int num1_sz, int * num2, int num2_sz )
{
	if (num1_sz != num2_sz) return num1_sz < num2_sz;
	for (int a=0; a<num1_sz; a++)
		if (num1[a] != num2[a])
			return num1[a] < num2[a];
	return false;
}

int ans[100];

void add_to_ans( int * num, int num_sz )
{
	reverse( num, num+num_sz );
	for (int a=0; a<num_sz; a++)
		ans[a] += num[a];
}

void sol()
{
	for (int a=2; a<=n; a++)
	{
		seed = seed * 1103515245 + 12345;
		//cout << (((seed >> 16) & ((1<<15)-1)) % 9) + 1 << "\n";
		digit[a] = (((seed >> 16) & ((1<<15)-1)) % 9) + 1;
	}


	for (int a=1; a<=n; a++)
		best_up[a] = best_down[a] = a;

	int num1[50], num1_sz;
	int num2[50], num2_sz;

	for (int a=n; a>=1; a--)
	{
		if (a*2+1 <= n) // 2 childs
		{
			num1_sz = parse( best_up[a*2], a, num1 );
			num2_sz = parse( best_up[a*2+1], a, num2 );
			if (le( num1, num1_sz, num2, num2_sz ))
				best_up[a] = best_up[a*2+1];
			else best_up[a] = best_up[a*2];

			num1_sz = parse( a, best_down[a*2], num1 );
			num2_sz = parse( a, best_down[a*2+1], num2 );
			if (le( num1, num1_sz, num2, num2_sz ))
				best_down[a] = best_down[a*2+1];
			else best_down[a] = best_down[a*2];
		}
		else if (a*2 <= n) // 1 child
		{
			best_up[a] = best_up[a*2];
			best_down[a] = best_down[a*2];
		}
	}

	for (int a=1; a<=n; a++)
	{
		if (a*2+1 <= n) // 2 childs
		{
			num1_sz = parse( best_up[a*2], a, num1 );
			num1_sz += parse( a, best_down[a*2+1], num1+num1_sz );
			num2_sz = parse( best_up[a*2+1], a, num2 );
			num2_sz += parse( a, best_down[a*2], num2+num2_sz );
			if (le( num1, num1_sz, num2, num2_sz ))
				add_to_ans( num2, num2_sz );
			else add_to_ans( num1, num1_sz );
		}
		else if (a*2 <= n) // 1 child
		{
			num1_sz = parse( best_up[a*2], a, num1 );
			num2_sz = parse( a, best_down[a*2], num2 );
			if (le( num1, num1_sz, num2, num2_sz ))
				add_to_ans( num2, num2_sz );
			else add_to_ans( num1, num1_sz );
		}
	}

	for (int a=0; a<100; a++)
		if (ans[a]>=10)
		{
			ans[a+1] += ans[a]/10;
			ans[a] %= 10;
		}

	for (int a=99; a>=0; a--)
		if (ans[a]>0)
		{
			for (int b=a; b>=0; b--)
				cout << ans[b];
			return;
		}
	cout << 0;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> seed;

	sol();
	
	return 0;
}
