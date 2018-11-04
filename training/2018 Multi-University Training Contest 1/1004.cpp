#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
//pos = lower_bound(a,a+n,key) - a	//查找>=key的位置
//pos = upper_bound(a,a+n,key) - a	//查找>key的位置
pii op[100005];
int a[100005];
int vis[100005];

//vector<int> tmp;
//void see() {
//	tmp.clear();
//	cout << "queue: ";
//	while(!que.empty()) {
//		int te = que.top();
//		cout << te << " ";
//		tmp.push_back(te);
//		que.pop();
//
//	}
//	cout << endl;
//	for(int i=0; i<tmp.size(); i++)   que.push(tmp[i]);
//}
int main() {
	int i,j,n,m,t;
	scanf("%d",&t);
	while(t--) {
		priority_queue<int, vector<int>, greater<int>> que;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++) {
			que.push(i);
			a[i] = -1;
		}
		for(i=0; i<m; i++) {
			scanf("%d%d",&op[i].first,&op[i].second);
		}
		sort(op,op + m);
		int pos = 1;
		for(i=0; i<m; i++) {
			for(; pos < op[i].first; pos++) {
				if(a[pos] == -1)	a[pos] = 1;
				else {
					que.push(a[pos]);
				}
			}
			for(j = op[i].first; j <= op[i].second; j++) {
				if(a[j] == -1) {
					a[j] = que.top();
					que.pop();
				}
			}
		}
		for(; pos <= n; pos++)	if(a[pos] == -1)	a[pos] = 1;
		for(i=1; i<=n; i++) {
			printf("%d",a[i]);
			if(i == n)	printf("\n");
			else	printf(" ");
		}

	}
	return 0;
}
