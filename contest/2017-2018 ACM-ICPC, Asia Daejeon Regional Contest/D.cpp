#include<math.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
#include<map>
using namespace std;
ll cal(ll x) {
    ll temp = 0;
    while(x > 0) {
        temp += (x % 10) * (x % 10);
        x /= 10;
    }
    return temp;
}
map<ll,int> mp;
int main() {
	ll n;
	cin >> n;
	bool flag = false;
	while(!mp.count(n)) {
        mp[n] = 1;
        n = cal(n);
        if(n == 1)	flag = true;
//        cout << n << endl;
	}
	if(flag)	printf("HAPPY\n");
	else	printf("UNHAPPY\n");
	return 0;
}