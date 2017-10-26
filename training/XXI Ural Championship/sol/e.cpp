#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

map <string, int> t;

int queries;

int cnt(string s) {
	return t[s];
}

bool use(string s) {
	if (t[s] > 0) {
		t[s]--;
		printf("%s", s.c_str());
		return true;
	}
	return false;
}

void query(int num) {
	printf("%d\n", num);
	fflush(stdout);
	char res[5];
	scanf("%s", res);
	t[res]++;
	queries++;
}

int main() {
	query(1);
	while (cnt("0") < 2) query(3);
	while (cnt("2") == 0) query(4);
	while (cnt("*") == 0 || cnt("+") == 0) query(5);
	int f = 1;
	while (f) {
		f = 0;
		while (cnt("1") + cnt("2") + cnt("3") + cnt("4") + cnt("5") + cnt("6") + cnt("7") + cnt("8") + cnt("9") < cnt("+") + cnt("-") + cnt("*") + cnt("/") + 5 ||
			cnt(")") < cnt("(")) {
			f = 1;
			query(4);
		}
		while (cnt("(") < cnt(")") || cnt(")") == 0) {
			f = 1;
			query(2);
		}
	}

	printf("0 ");

	use("0");

	if (cnt("<")) {
		use("-");
		use("2");
	} else if (cnt(">") || cnt("!=")) {
		use("+");
		use("2");
	}

	use("=");
	use("!=");
	use("<");
	use(">");
	use("<=");
	use(">=");

	use("0");
	use("*");
	while (use("("));

	while (1) {
		int f = 0;
		for (int i = 1; i <= 9; i++) {
			char num[10];
			sprintf(num, "%d", i);
			if (use(num)) {
				f = 1;
				break;
			}
		}
		if (!f) break;
		if (use("+")) {
		} else if (use("-")) {
		} else if (use("*")) {
		} else if (use("/")) {
		}
	}

	while (use(")"));

	printf("\n");
	fflush(stdout);

	return 0;
}
