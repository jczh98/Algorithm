#include<math.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream> //istringstream stm(string); stm >> x;
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
struct pr {
	int xx;
	int yy;
};
pr ini[2][2];
pr re[2][2];
void bian0(pr in[2][2]) {
	re[0][0] = in[0][0];
	re[0][1] = in[1][0];
	re[1][1] = in[1][1];
	re[1][0] = in[0][1];
}
void bian3(pr in[2][2]) {
	re[0][0] = in[1][1];
	re[1][1] = in[0][0];
	re[0][1] = in[0][1];
	re[1][0] = in[1][0];
}
int main() {
	ini[0][0].xx = 0;
	ini[0][0].yy = 0;
	ini[0][1].xx = 0;
	ini[0][1].yy = 1;
	ini[1][0].xx = 1;
	ini[1][0].yy = 0;
	ini[1][1].xx = 1;
	ini[1][1].yy = 1;
	int k,n,i,j,m;
	cin >> n >> m;
//    int now = (2 << n);
//	cout << now << endl;
	int nx = 0,ny = 0;

//	cout << ini[0][0].xx << ini[0][1].xx << ini[1][1].xx << ini[1][0].xx << endl;
//	cout << ini[0][0].yy << ini[0][1].yy << ini[1][1].yy << ini[1][0].yy << endl;
	while(n >= 2) {
		int dir = 0;
		for(i = 1; i<=4; i++) {
			if(m <= (n*n) / 4 * i) {
				dir = i-1;
				break;
			}
		}
//		cout << "dir: " << dir << endl;
		if(dir == 0) {
			nx += n / 2 * ini[0][0].xx;
			ny += n / 2 * ini[0][0].yy;
		}

		if(dir == 1) {
			nx += n / 2 * ini[0][1].xx;
			ny += n / 2 * ini[0][1].yy;
		}

		if(dir == 2) {
			nx += n / 2 * ini[1][1].xx;
			ny += n / 2 * ini[1][1].yy;
		}

		if(dir == 3) {
			nx += n / 2 * ini[1][0].xx;
			ny += n / 2 * ini[1][0].yy;
		}


		if(dir == 0) {
			bian0(ini);
		ini[0][0] = re[0][0];
		ini[0][1] = re[0][1];
		ini[1][0] = re[1][0];
		ini[1][1] = re[1][1];
		}
		if(dir == 3) {
			bian3(ini);
		ini[0][0] = re[0][0];
		ini[0][1] = re[0][1];
		ini[1][0] = re[1][0];
		ini[1][1] = re[1][1];
		}
//		cout << ini[0][0].xx << ini[0][1].xx << ini[1][1].xx << ini[1][0].xx << endl;
//		cout << ini[0][0].yy << ini[0][1].yy << ini[1][1].yy << ini[1][0].yy << endl;
		if(m - n * n / 4 > 0)
			m -= n * n / 4;
		if(m - n * n / 4 > 0)
			m -= n * n / 4;
		if(m - n * n / 4 > 0)
			m -= n * n / 4;
		if(m - n * n / 4 > 0)
			m -= n * n / 4;
//		cout << "cor: " << nx + 1 << " " << ny + 1 << endl;
		n /= 2;
//		cout << "n: " << n << "  m: " << m << endl;
//		cout << endl;
	}
	cout << nx + 1 << " " << ny + 1 << endl;
	return 0;
}