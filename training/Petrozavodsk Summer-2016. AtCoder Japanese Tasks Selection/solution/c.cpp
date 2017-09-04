#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long Int;
#define INF (1LL << 60)
Int dp[2][108000];
Int imos[108000];
vector<Int> family;
Int sum, n, m, p;
Int res;
Int sq(Int x){
	return x*x;
}

int main(){
	cin >> n >> m;
	for(Int i = 0;i < m;i++){
		cin >> p;
		family.push_back(p);
		sum += p;
	}
	for(Int i = 0;i < 108000;i++){
		dp[0][i] = dp[1][i] = INF;
	}
	
	dp[0][0] = 0;
	
	sort(family.rbegin(), family.rend());
	for(Int i = 0;i < m;i++){
		if(i==0)imos[i] = family[i];
		else imos[i] = family[i] + imos[i-1];
	}
	for(Int i = 0;i < m;i++){
		p = family[i];
		Int id = (i+1)%2;
		for(Int j = 0;j < 108000;j++){
			if(dp[i%2][j] == INF)continue;
			dp[id][j] = min(dp[id][j], dp[i%2][j] + sq(sum - 2*(imos[i]-j -p)) );
			dp[id][j+p] = min(dp[id][j+p], dp[i%2][j] + sq(sum - 2*(j+p)) );
			dp[i%2][j] = INF;
		}
	}
	for(Int i = 0;i < 108000;i++){
		if(dp[m%2][i] == INF)continue;
		Int tmp = dp[m%2][i];
		tmp += sq(2*i - sum) * (n-m);
		res = max(res, (sum*sum*n - tmp) / 4);
	}
	cout << res << endl;
	return 0;
}
