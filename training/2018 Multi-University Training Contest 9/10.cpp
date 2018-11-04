#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string);	stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
//pos = lower_bound(a, a+n, key) - a	//查找>=key的位置
//pos = upper_bound(a, a+n, key) - a	//查找>key的位置
int l1[5], l2[5];
void cal(int a, int b) {
	int i;
	if(a > b) {
		printf("1\n");
		return;
	}
	if(a < b) {
		printf("-1\n");
		return;
	}
    if(a == 2) {
        long long ans1 = 0, ans2 = 0;
        for(i = a; i >= 1; --i) {
            ans1 += l1[i]; ans2 += l2[i];
        }
        int flag = true, flag2 = true;
        if(l1[a] == l1[a-1]) {
            if(l2[a] < l2[a-1]) flag2 = false;
            if(abs(l2[a] - l2[a-1]) > 2) flag2 = false;
        }
        if(l2[a] == l2[a-1]) {
            if(l1[a] < l1[a-1]) flag2 = false;
            if(abs(l1[a] - l1[a-1]) > 2) flag2 = false;
        }
        if(l1[a] == l2[a-1] && l2[a] == l1[a-1]) flag = false;
        if(ans1 == ans2 && flag && flag2) {
            printf("0\n");
            return;
        }
    }
    if(a == 3) {
        long long ans1 = 0, ans2 = 0;
        for(i = a; i >= 2; --i) {
            ans1 += l1[i]; ans2 += l2[i];
        }
        int flag = true, flag2 = true;
        if(l1[a] == l1[a-1]) {
            if(l2[a] < l2[a-1]) flag2 = false;
            if(abs(l2[a] - l2[a-1]) > 2) flag2 = false;
        }
        if(l2[a] == l2[a-1]) {
            if(l1[a] < l1[a-1]) flag2 = false;
            if(abs(l1[a] - l1[a-1]) > 2) flag2 = false;
        }
        if(l1[a] == l2[a-1] && l2[a] == l1[a-1]) flag = false;
        if(ans1 == ans2 && flag && flag2) {
            if(l1[1] > l2[1]) printf("-1\n");
            if(l1[1] < l2[1]) printf("1\n");
            if(l1[1] == l2[1]) printf("0\n");
            return;
        }
    }
	for(i=a; i>=1; i--) {
		if(l1[i] > l2[i]) {
			printf("-1\n");
			return;
		}
		if(l1[i] < l2[i]) {
			printf("1\n");
			return;
		}
	}
	printf("0\n");
}
int main() {
	int i, j, k, n, m, t;
	scanf("%d", &t);
	int a,b;
	while(t--) {
		scanf("%d%d", &a, &b);
		for(i=1; i<=a; i++)	scanf("%d", &l1[i]);
		for(i=1; i<=b; i++)	scanf("%d", &l2[i]);
		cal(a, b);
	}
	return 0;
}
