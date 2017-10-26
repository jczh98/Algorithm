#include <stdlib.h>
#include <string.h>
#include <algorithm>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <map>

using namespace std;

#define MAX 40

int n;
pair<long long, long long> need;
pair<long long, long long> f[MAX];

map <long long, int> q;

long long ans;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf(INT64 " " INT64, &need.first, &need.second);
	for (int i = 0; i < n; i++) {
		scanf(INT64 " " INT64, &f[i].first, &f[i].second);
	}

	for (int i = 0; i < (1 << (n / 2)); i++) {
		long long a = 0;
		long long b = 0;
		for (int j = 0; j < n / 2; j++) {
			if ((1 << j) & i) {
				a += f[j].first;
				b += f[j].second;
			}
		}
		q[a * need.second - b * need.first]++;
	}

	for (int i = 0; i < (1 << ((n + 1) / 2)); i++) {
		long long a = 0;
		long long b = 0;
		for (int j = 0; j < (n + 1) / 2; j++) {
			if ((1 << j) & i) {
				a += f[n / 2 + j].first;
				b += f[n / 2 + j].second;
			}
		}
		ans += q[b * need.first - a * need.second];
	}

	printf(INT64 "\n", ans - 1);
	return 0;
}
