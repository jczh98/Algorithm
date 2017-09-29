#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main() {
	/*for(int i(10); i <= 10000000; i *= 10) {
		for(int j(0); j < 10; j++) {
			set<int> st;
			for(int k(0); k < 10000; k++) {
				st.insert(rand() % i);
			}
			printf("%d %d\n", i, (int)st.size());
		}
	}*/
	set<string> st;
	for(int i(0); i < 10000; i++) {
		cout << '+' << endl;
		fflush(stdout);
		string x;
		cin >> x;
		st.insert(x);
	}
	int x(st.size());
	cout << "= " << (x >= 9980 ? 10000000 : x >= 9800 ? 1000000 : x >= 8000 ? 100000 : x >= 2000 ? 10000 : x >= 500 ? 1000 : x >= 50 ? 100 : x >= 5 ? 10 : 0) << endl;
	fflush(stdout);
	return 0;
}
