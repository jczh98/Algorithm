#include <stdlib.h>
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

#define MAX 1005

int n, m;

vector <string> a[MAX];
vector <string> b[MAX];

int match[MAX][MAX];
bitset<320000> bs[MAX];

int C[31][7];
int sum_C[31][7];

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= 30; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= 6; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	for (int j = 0; j <= 6; j++) {
		sum_C[0][j] = C[0][j];
		for (int i = 1; i <= 30; i++) {
			sum_C[i][j] = sum_C[i - 1][j] + C[i][j];
		}
	}
}

int q;
map <string, int> num_map;

int to_number(string s) {
	if (num_map.find(s) == num_map.end()) {
		q++;
		return num_map[s] = q;
	}
	return num_map[s];
	/*int res = 0;
	size_t c = 0;
	char x = 'a';
	while (c < s.size()) {
		res += sum_C['z' - x][s.size() - c - 1] - sum_C['z' - s[c]][s.size() - c - 1];
		x = s[c] + 1;
		c++;
	}
	for (size_t i = 1; i < s.size(); i++) {
		res += C[26][i];
	}
	return res;*/
}

void add(bitset<320000> &bs, string &s, string g = "", int c = 0) {
	if (c == s.length()) return;
	bs.set(to_number(g + s[c]));
	add(bs, s, g + s[c], c + 1);
	add(bs, s, g, c + 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int q;
		scanf("%d", &q);
		for (int j = 0; j < q; j++) {
			char s[50];
			scanf("%s", s);
			sort(s, s + strlen(s));
			a[i].push_back(s);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int q;
		scanf("%d", &q);
		for (int j = 0; j < q; j++) {
			char s[50];
			scanf("%s", s);
			sort(s, s + strlen(s));
			b[i].push_back(s);
		}
	}

	init();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (int)b[i].size(); j++) {
			add(bs[i], b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int) a[i].size(); j++) {
			int num = to_number(a[i][j]);
			for (int k = 0; k < m; k++) {
				if (bs[k].test(num)) {
					match[i][k]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int bst = 0;
		for (int k = 1; k < m; k++) {
			if (match[i][k] > match[i][bst]) {
				bst = k;
			}
		}
		printf("%d\n", bst + 1);
	}

	return 0;
}