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
const int maxn = 100005;
using namespace std;
int nex[5][maxn];
char s[5][maxn],str[maxn];
void init_next(int *Next,char *a) {
	int len = strlen(a);
	Next[0] = -1;
	int i = 0;
	int j=-1;
	while(i<len) {
		if(j==-1 || a[i]==a[j])  Next[++i]=++j;
		else j  =  Next[j];
	}
	return ;
}
struct node {
	int pos[5],ans[5],len[5];
};
node ansall[maxn];
int tot;
int pos1[5][maxn][26];
int get_next(int *Next,char ch,int pos,int id) {
	int last = pos;
	int temp = ch - 'a';
	for(; pos!=-1;) {
		if(s[id][pos] == ch) {
			break;
		}
		if(pos1[id][pos][temp]!=0)pos = pos1[id][pos][temp];
		else pos = Next[pos];
	}
	if(last == pos)return pos+1;
	int t1;
	for(; last!=pos;) {
		if(pos1[id][last][temp]!=0)t1 = pos1[id][last][temp];
		else t1 = Next[last];
		pos1[id][last][temp] = pos;
		last = t1;
	}
	return pos + 1;
}
int main() {
	int n, i, j;
	scanf("%d",&n);
	for(i = 1; i <= n; i++) {
		scanf("%s",s[i]);
		init_next(nex[i],s[i]);
	}
	scanf("%s",str);
	node t1;
	for(i = 1; i <= n; i++) {
		t1.pos[i] = 0;
		t1.len[i] = t1.ans[i] = strlen(s[i]);
	}

	ansall[++tot] = t1;
	int len = strlen(str);
	for(i = -1; i<len; i++) {
		if(i == -1) {
			int ans = INF;
			for(int j = 1; j <= n; j++)
				ans = min(ans,int(strlen(s[j])));
			printf("%d\n",ans);
			continue;
		}
		if(str[i] == '-') {
			tot = max(1, tot - 1);
			int ans1 = INF;
			for(int j = 1; j <= n; j++)	ans1 = min(ans1,ansall[tot].ans[j]);
			printf("%d\n",ans1);
			continue;
		}
		node t2 = ansall[tot];
		int ans1 = INF;
		for(j = 1; j <= n; j++) {
			t2.pos[j] = get_next(nex[j],str[i],t2.pos[j],j);
			t2.ans[j] = t2.len[j]-t2.pos[j];
			ans1 = min(ans1,t2.ans[j]);
		}
		ansall[++tot] = t2;
		printf("%d\n",ans1);
	}
	return 0;
}
