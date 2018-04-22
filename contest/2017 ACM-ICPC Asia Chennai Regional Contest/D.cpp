#include <bits/stdc++.h>
using namespace std;
int t, n, e, p1, p2;
struct node {
	int val, pos;
	bool operator < (const node & rhs) const {
		return val < rhs.val;
	}
} xi[1005];
int main() {
	scanf("%d", &t);
	while(t--) {
		p1 = p2 = 0;
		scanf("%d%d", &n, &e);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &xi[i].val);
			xi[i].pos = i;
		}
		if(n == 1) {
			if(e == xi[1].val) {
				printf("1\n");
			} else {
				printf("-1\n");
			}
			continue;
		}
		int flag = 1;
		for(int i = 1; i <= n; ++i) {
			if(xi[i].val == e) {
				flag = 0;
			}
		}
		if(!flag) {
			bool fl = false;
			for(int i = 1; i <= n; ++i) {
				if(xi[i].val == e) {
					if(!fl) {
						printf("1");
						fl = true;
					} else {
						printf("0");
					}
				} else printf("0");
				printf("%c", i == n ? '\n' : ' ');
			}
			continue;
		}

		for(int i = 1; i <= n; ++i) {
			if(e > xi[i].val) {
				p1 = i;
				break;
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(e < xi[i].val) {
				p2 = i;
				break;
			}
		}
		if(!p1 || !p2) {
			printf("-1\n");
		} else {
			double ans1 = (double)(xi[p2].val - e) / (double)(xi[p2].val - xi[p1].val);
			double ans2 = (double)(e - xi[p1].val) / (double)(xi[p2].val - xi[p1].val);
			for(int i = 1; i <= n; ++i) {
				if(i == p1) {
					printf("%.16f", ans1);
				} else if(i == p2) {
					printf("%.16f", ans2);
				} else printf("0");
				printf("%c", (i == n ? '\n' : ' '));
			}
		}
	}
	return 0;
}