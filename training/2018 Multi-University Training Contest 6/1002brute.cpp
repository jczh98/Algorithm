#include <stdio.h>
#include <bits/stdc++.h>
struct list {
	int val;
	struct list * pre;
};
int cnt[1000005];
void print(struct list * n,struct list * d,int z){
	int i;
	if (n==NULL){
        int gcd = 0;
		for(;z>0;z--)
			printf("0 ");
		while(d!=NULL){
			printf("%d ",d->val); gcd = std::__gcd(gcd, d->val);
			d=d->pre;
		}
        printf(" GCD: %d ", gcd); cnt[gcd]++;
		printf("\n");
		return;
	}
	
	struct list d1;
	d1.val=n->val;
	d1.pre=d;
	print(n->pre,&d1,z);
	if (z>0) {
		struct list d2;
		d2.val=0;
		d2.pre=d;
		print(n,&d2,z-1);
	}
}

void loop(struct list * n,int sum,int lv,int m,int z){
	if (sum==0) {
		if (z>=0) print(n,NULL,z);
		return;
	}
	if (lv>m) return;
	int i=0;
	struct list nn[sum];
	for(;i<sum;i++){
		nn[i].val=i+1;
		nn[i].pre=n;
		loop(&nn[i],sum-i-1,lv+1,m,z+i);
	}
}
void f(int n,int m){
	loop(NULL,n,0,m,m-n);
}
int main(){
    int n = 6, m = 8;
    freopen("out.txt", "w", stdout);
	f(n,m);
    for(int i = 1; i <= n; ++i) {
        printf("GCD is %d, number is %d\n", i, cnt[i]);
    }
}