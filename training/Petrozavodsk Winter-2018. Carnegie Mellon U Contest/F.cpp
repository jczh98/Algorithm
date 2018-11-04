#include<bits/stdc++.h>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define lowbit(x) (x&(-x))
int s,w;
int time_clock[5000100],now;
int tree[5000100];
inline void add(int x,int num) {
	for(int i=x; i<=w; i+=lowbit(i)) {
		if(time_clock[i]!=now)  tree[i]=0;
		time_clock[i]=now;
		tree[i]+=num;
	}
}
inline int search(int x) {
	int re=0;
	for(int i=x; i; i-=lowbit(i))
		if(time_clock[i]==now)  re+=tree[i];
	return re;
}
struct event {
	int x,y,num,val,ans;
} a[2000050],tmp[2000050];
int tp;
inline bool cmp(event a,event b) {
	return a.num<b.num;
}
inline void add_event(int x,int y,int z) {
	a[++tp].x=x;
	a[tp].y=y;
	a[tp].val=z;
	a[tp].num=tp;
	if(z==INF)  a[tp].ans+=x*y*s;
}
void CDQ(int l,int r) {
	if(l==r)    return;
	int mid=l+r>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	++now;
	int j=l;
	for(int i=mid+1; i<=r; ++i) {
		while(a[j].x<=a[i].x && j<=mid) {
			if(a[j].val!=INF)   add(a[j].y,a[j].val);
			++j;
		}
		if(a[i].val==INF)   a[i].ans+=search(a[i].y);
	}
	int L1=l,L2=mid+1;
	for(int i=l; i<=r; ++i) {
		if(a[L1].x<a[L2].x && L1<=mid || L2>r)  tmp[i]=a[L1++];
		else                                    tmp[i]=a[L2++];
	}
	memcpy(a+l,tmp+l,sizeof(a[0])*(r-l+1));
}
int main() {
//    scanf("%d%d",&s,&w);
	s = 0;
	w = 2000010;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		add_event(a+b+1000005,a-b+1000005,1);
	}
	int opt;
	scanf("%d",&opt);
	while(opt--) {
//        if(opt==1){
//            int x,y,z;
//            scanf("%d%d%d",&x,&y,&z);
//            add_event(x,y,z);
//        } else {

		int x1,yl,x2,y2;
		int a,b,d;
		cin >> a >> b >> d;
        x1 = a+b-d+1000005;
        x2 = a+b+d+1000005;
        yl = a-b-d+1000005;
        y2 = a-b+d+1000005;
//		scanf("%d%d%d%d",&x1,&yl,&x2,&y2);
		add_event(x2,y2,INF);
		add_event(x1-1,yl-1,INF);
		add_event(x1-1,y2,INF);
		add_event(x2,yl-1,INF);
//        }
	}
	CDQ(1,tp);
	sort(a+1,a+tp+1,cmp);
	for(int i=1; i<=tp; ++i) {
		if(a[i].val==INF) {
			printf("%d\n",a[i].ans+a[i+1].ans-a[i+2].ans-a[i+3].ans);
			i+=3;
		}
	}
	return 0;
}
