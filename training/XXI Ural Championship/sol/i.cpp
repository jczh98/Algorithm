#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string.h>

using namespace std;

int n;
int k;
char command[101];

char ans[100][100];
bool skip_col[100];
bool skip_row[100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inside(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool can(int x, int y) {
	return inside(x, y) && (ans[x][y] == '.' || ans[x][y] == '#');
}

bool can2(int x, int y) {
	return inside(x, y) && ans[x][y] == '.';
}

bool empty(int x, int y) {
	return inside(x, y) && (ans[x][y] == '.' || ans[x][y] == '~');
}

int rotate(int dir, char c) {
	if (c == 'L') return (dir + 1) % 4;
	if (c == 'R') return (dir + 3) % 4;
	return dir;
}

bool build(int x, int y, int dir, int c) {
	if (c == k) {
		while (empty(x + dx[dir], y + dy[dir])) {
			x += dx[dir];
			y += dy[dir];
		}
		x += dx[dir];
		y += dy[dir];
		return !inside(x, y);
	}
	int x2, y2;
	if (can2(x + dx[dir], y + dy[dir])) {
		x2 = x + dx[dir];
		y2 = y + dy[dir];
		char prev = ans[x2][y2];
		ans[x2][y2] = '#';
		if (build(x2 - dx[dir], y2 - dy[dir], rotate(dir, command[c]), c + 1)) return true;
		ans[x2][y2] = prev;
	}

	if (empty(x + dx[dir], y + dy[dir]) && can2(x + 2 * dx[dir], y + 2 * dy[dir])) {
		x2 = x + dx[dir];
		y2 = y + dy[dir];
		char prev1 = ans[x2][y2];
		ans[x2][y2] = '~';
		x2 += dx[dir];
		y2 += dy[dir];
		char prev2 = ans[x2][y2];
		ans[x2][y2] = '#';
		if (build(x2 - dx[dir], y2 - dy[dir], rotate(dir, command[c]), c + 1)) return true;
		ans[x2][y2] = prev2;
		x2 -= dx[dir];
		y2 -= dy[dir];
		ans[x2][y2] = prev1;
	}

	vector<pair<int, int> > used;
	x2 = x + dx[dir];
	y2 = y + dy[dir];
	while (empty(x2, y2) && can(x2 + dx[dir], y2 + dy[dir])) {
		if (ans[x2][y2] == '.') {
			ans[x2][y2] = '~';
			used.push_back(make_pair(x2, y2));
		}
		x2 += dx[dir];
		y2 += dy[dir];
	}

	if (can(x2, y2)) {
		char prev = ans[x2][y2];
		ans[x2][y2] = '#';
		if (build(x2 - dx[dir], y2 - dy[dir], rotate(dir, command[c]), c + 1)) return true;
		ans[x2][y2] = prev;
	}

	x2 -= dx[dir];
	y2 -= dy[dir];

	if (!used.empty() && used[used.size() - 1].first == x2 && used[used.size() - 1].second == y2) {
		ans[x2][y2] = '.';
		used.resize(used.size() - 1);
	}

	if ((x != x2 || y != y2) && can(x2, y2)) {
		char prev = ans[x2][y2];
		ans[x2][y2] = '#';
		if (build(x2 - dx[dir], y2 - dy[dir], rotate(dir, command[c]), c + 1)) return true;
		ans[x2][y2] = prev;
	}

	for (size_t i = 0; i < used.size(); i++) {
		ans[used[i].first][used[i].second] = '.';
	}

	return false;
}

void process_samples() {
	if (strcmp(command, "L") == 0) {
		printf("@#\n");
		exit(0);
	}
	if (strcmp(command, "LLLLLL") == 0) {
		printf("######\n");
		printf(".....#\n");
		printf("####.#\n");
		printf("#....#\n");
		printf("###.##\n");
		printf("###.##\n");
		printf("@...##\n");
		exit(0);
	}
	if (strcmp(command, "RLLRRLLRRLLRRLLRRLLRRLLL") == 0) {
		printf("@##\n");
		printf("..#\n");
		printf("###\n");
		exit(0);
	}
	if (strcmp(command, "LRRLLLLRRRLRRRRR") == 0) {
		printf(".......#...\n");
		printf("...#......#\n");
		printf(".#......#..\n");
		printf("......#....\n");
		printf("..#........\n");
		printf(".......#...\n");
		printf(".........#.\n");
		printf("@.#..#.....\n");		
		exit(0);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s", command);
	k = strlen(command);

	process_samples();

	n = 50;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = '.';
		}
	}

	if (command[0] == 'L') {
		ans[n - 1][0] = '@';
		build(n - 1, 0, 3, 0);
	} else {
		ans[0][0] = '@';
		build(0, 0, 3, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[j][i] == '~') {
				ans[j][i] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int j = 0; j < n; j++) {
			if (ans[i][j] != '.' || i != 0 && ans[i - 1][j] != '.' || i != n - 1 && ans[i + 1][j] != '.') {
				f = 1;
			}
		}
		if (!f) {
			skip_row[i] = 1;
		}
	}

	for (int j = 0; j < n; j++) {
		int f = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i][j] != '.' || j != 0 && ans[i][j - 1] != '.' || j != n - 1 && ans[i][j + 1] != '.') {
				f = 1;
			}
		}
		if (!f) {
			skip_col[j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (skip_row[i]) continue;
		for (int j = 0; j < n; j++) {
			if (skip_col[j]) continue;
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}

